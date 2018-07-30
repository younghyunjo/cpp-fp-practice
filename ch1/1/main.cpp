#include <iostream>

auto main() -> int {
    auto a = 1;
    auto b = 1.0;
    auto c = a + b;
    auto d = {b, c};

    std::cout << "typeof a: " << typeid(a).name() << std::endl;
    std::cout << "typeof b: " << typeid(b).name() << std::endl;
    std::cout << "typeof c: " << typeid(c).name() << std::endl;
    std::cout << "typeof d: " << typeid(d).name() << std::endl;

    return 0;
}
