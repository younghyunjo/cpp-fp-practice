#include <iostream>
#include <algorithm>
#include <vector>

auto foreach () -> void
{
    std::vector<int> v = {1, 2, 3, 4};
    std::for_each(std::begin(v),
                  std::end(v),
                  [](int i) {
                      std::cout << i << std::endl;
                  });
}

auto begin_end() -> void
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "for-loop" << std::endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "non memger begin() and end()" << std::endl;
    for (auto i = std::begin(arr); i != std::end(arr); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    std::cout << "range based for-loop" << std::endl;
    for (auto i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

auto add(auto i, auto j) -> decltype(i + j)
{
    return i + j;
}

auto autoTest() -> void
{
    auto a = 1;
    auto b = 1.0;
    auto c = a + b;
    auto d = {b, c};

    std::cout << "typeof a: " << typeid(a).name() << std::endl;
    std::cout << "typeof b: " << typeid(b).name() << std::endl;
    std::cout << "typeof c: " << typeid(c).name() << std::endl;
    std::cout << "typeof d: " << typeid(d).name() << std::endl;
}

auto lambdaReturn()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    std::cout << "original" << std::endl;
    for (auto vv : v)
    {
        std::cout << vv << " ";
    }
    std::cout << std::endl;

    std::vector<int> v2;
    v2.resize(v.size());

    std::transform(std::begin(v), std::end(v),
                   std::begin(v2), [](auto i) { return i * i; });

    std::cout << "transform" << std::endl;
    std::for_each(begin(v2), end(v2), [](auto i) { std::cout << i << " "; });
    std::cout << std::endl;

    std::vector<int> v3;
    v3.resize(v.size());
    std::transform(v.begin(), v.end(),
                   v3.begin(), [](auto i) -> double { return i / 2; });

    std::cout << "transform" << std::endl;
    std::for_each(begin(v3), end(v3), [](auto i) { std::cout << i << " "; });
    std::cout << std::endl;
}

auto lambdaCapture()
{
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    std::cout << "original" << std::endl;
    for (auto vv : v)
    {
        std::cout << vv << " ";
    }
    std::cout << std::endl;

    std::vector<int> v2;
    v2.resize(v.size());

    int a = 2;
    int b = 8;

    std::for_each(v.begin(), v.end(), [a, b](auto n) {
            if (n > a && n < b) {
                std::cout << n << " "; } });

    a = 3;
    b = 7;

    for_each(std::begin(v),
             std::end(v),
             [=](int n) mutable {
                 if (n > a && n < b)
                 {
                     std::cout << n << " ";
                 }
                 a = 0;
                 b = 10;
                 std::cout << a << b << std::endl;
             });
    std::cout << std::endl;

    std::cout << a << b << std::endl;
}

auto lambdaInitializationCapture() {
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    std::cout << "original" << std::endl;
    for (auto vv : v)
    {
        std::cout << vv << " ";
    }

    int a = 2;
    int b = 8;

    [&x =a]() {
        std::cout << "X ";
        std::cout << x << std::endl;
    }();
}

auto lambdaGeneric() {
    auto findMax = [](auto &x, auto &y) {
        return x > y ? x : y;
    };

    int i1 = 5, i2 = 3;
    float f1 = 2.5f, f2 = 2.05f;

    std::cout << "Max " << findMax(i1, i2) << std::endl;
    std::cout << "Max " << findMax(f1, f2) << std::endl;
}

auto main() -> int
{
    lambdaGeneric();
    // lambdaInitializationCapture();
    // lambdaCapture();
    //lambdaReturn();
    //foreach();
    //begin_end();
    //std::cout << add(1, 2) <<std::endl;
    //autoTest();
    return 0;
}
