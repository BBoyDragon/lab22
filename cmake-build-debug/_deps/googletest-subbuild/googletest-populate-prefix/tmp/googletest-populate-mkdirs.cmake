# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Labs/labwork2-Mihail-mm/cmake-build-debug/_deps/googletest-src"
  "D:/Labs/labwork2-Mihail-mm/cmake-build-debug/_deps/googletest-build"
  "D:/Labs/labwork2-Mihail-mm/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "D:/Labs/labwork2-Mihail-mm/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "D:/Labs/labwork2-Mihail-mm/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "D:/Labs/labwork2-Mihail-mm/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "D:/Labs/labwork2-Mihail-mm/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Labs/labwork2-Mihail-mm/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
