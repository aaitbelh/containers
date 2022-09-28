#include <iostream>
#include <vector>
struct Test {
  typedef int foo;
};

template <typename T>
void f(typename T::foo) {
    std::cout << "I get inside here\n";
}  // Definition #1

template <typename T>
void f(T) {
    std::cout << "I get inside here2\n";
}  // Definition #2

int main() {
  f<Test>(10); // Call #1.
  f<int>(10);   // Call #2. Without error (even though there is no int::foo)
                // thanks to SFINAE.
            std::cout << "YOOO" << std::endl;
    std::is_unsigned<int>::type<
}