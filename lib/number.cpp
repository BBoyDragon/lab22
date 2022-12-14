#include "number.h"

int count_digits_element(int i) {
    if (i == 0) {
        return 1;
    }
    int cnt = 0;
    while (i) {
        cnt++;
        i /= 10;
    }
    return cnt;
}

uint2022_t from_string(const char* buff) {
    uint2022_t result;
    int cnt_digits = 0;
    while (isdigit(buff[cnt_digits])) {
        cnt_digits++;
    }

    result.count_digits = cnt_digits;
    result.count_element = result.count_digits / 9 + ((result.count_digits % 9 == 0) ? 0 : 1);

    int step = 0;
    int digit9 = 0;
    int ind_vec = result.size_number - 1;
    for (int j = result.count_digits - 1; j >= 0; j--) {
        int digit = (buff[j]) - '0';
        digit9 += digit * pow(10, step);
        step++;
        if (step >= 9) {
            result.number[ind_vec] = digit9;
            digit9 = 0;
            step = 0;
            ind_vec--;
        }
    }
    result.number[ind_vec] = digit9;

    return result;
}

uint2022_t from_uint(uint32_t i) {
    uint2022_t result;
    result.number[result.size_number - 2] = i / int(1e9);
    result.number[result.size_number - 1] = i % int(1e9);
    result.count_element = (i < int(1e9) ? 1 : 2);
    result.count_digits = count_digits_element(i);
    return result;
}

uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t result;
    int s1 = lhs.count_digits;
    int s2 = rhs.count_digits;
    result.count_digits = std::max(s1, s2);
    result.count_element = result.count_digits / 9 + (result.count_digits % 9 == 0 ? 0 : 1);
    int c = 0;

    for (int i = result.size_number - 1; i >= 0; --i) {
        c = c + lhs.number[i] + rhs.number[i];
        result.number[i] = c % int(1e9);
        c = c / int(1e9);
    }

    return result;
}


uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t result;
    int c = 0;
    result.count_digits = lhs.count_digits;
    result.count_element = result.count_digits / 9 + (result.count_digits % 9 == 0 ? 0 : 1);

    for (int i = result.size_number - 1; i >= 0; --i) {
        int tmp = 0;
        int a = lhs.number[i];
        int b = rhs.number[i];
        for (int j = 0; j < 9; ++j) {
            c = c + (a % 10) - (b % 10) + 10;
            a /= 10; b /= 10;
            tmp += (c % 10) * pow(10, j);
            if (c < 10) c = -1;
            else c = 0;
        }
        result.number[i] = tmp;
    }
    return result;
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
    for (int i = lhs.size_number - 1; i >= 0; --i) {
        if (lhs.number[i] != rhs.number[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return !(lhs == rhs);
}

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t result;
    result.count_element = (lhs.count_element + rhs.count_element);
    for (int i = 0; i < lhs.count_element; ++i) {
        long long carry = 0;
        for (int j = 0; j < rhs.count_element || carry != 0; ++j) {
            carry += result.number[result.size_number - (i + j) - 1] + lhs.number[lhs.size_number - 1 - i] * 1LL * rhs.number[rhs.size_number - 1 - j];
            result.number[result.size_number - 1 - (i + j)] = int(carry % int(1e9));
            carry = int(carry / int(1e9));
        }
    }
    return result;
}


std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
    bool ignore_leading_zeros = true;
    bool first_elements = true;
    for (int i = 0; i < value.size_number; ++i) {
        if (value.number[i] != 0) {
            ignore_leading_zeros = false;
        }
        if (!ignore_leading_zeros) {
            if (count_digits_element(value.number[i]) < 9 && !first_elements) {
                for (int j = 0; j < 9 - count_digits_element(value.number[i]); ++j) {
                    stream << 0;
                }
            }
            stream << value.number[i];
            first_elements = false;
        }
    }
    if (ignore_leading_zeros) {
        stream << 0;
    }
    return stream;
}

