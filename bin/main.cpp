
#include <lib/number.h>
#include <iostream>

int main() {
    char n[600];
    char m[600];
    std::cin >> n >> m;
    uint2022_t value = from_string(n);
    uint2022_t value1 = from_string(m);
    for (int i = 0; i < 10; i++) {
        value1 = value1 * from_uint(10);
    }
    std::cout << value1;

    return 0;
}
