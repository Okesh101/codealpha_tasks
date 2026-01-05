# ---

# ⚙️ CMakeLists.txt

# ```cmake
cmake_minimum_required(VERSION 3.10)

project(AuthenticationSystem VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SQLite3 REQUIRED)

add_executable(AuthenticationSystem
    src/main.cc
)

# Link sqlite3
target_link_libraries(AuthenticationSystem SQLite::SQLite3)
