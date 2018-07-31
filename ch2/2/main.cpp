#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>

auto cppMap()
{
    std::vector<int> v1;
    for (int i = 0; i < 5; i++)
        v1.push_back(i);

    std::vector<int> v2;
    v2.resize(v1.size());

    std::transform(
        std::begin(v1),
        std::end(v1),
        std::begin(v2),
        [](auto i) {
            return i * i;
        });

    std::cout << "v1 : ";
    for (auto v : v1)
        std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "v2 : ";
    for (auto v : v2)
        std::cout << v << " ";
    std::cout << std::endl;
}

auto cppFilter()
{
    std::vector<int> numbers(20);
    std::iota(std::begin(numbers), std::end(numbers), 0);

    std::cout << "original : ";
    copy(std::begin(numbers), std::end(numbers),
         std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> prime;
    copy_if(std::begin(numbers), std::end(numbers),
            std::back_inserter(prime),
            [](int n) {
                if (n < 2)
                {
                    return (n != 0) ? true : false;
                }
                else
                {
                    for (int j = 2; j < n; j++)
                    {
                        if (n % j == 0)
                        {
                            return false;
                        }
                    }
                }
                return true;
            });

    std::cout << "primes : ";
    std::copy(std::begin(prime), std::end(prime),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

auto cppFilterRemoveIf()
{
    std::vector<int> numbers(20);
    std::iota(std::begin(numbers), std::end(numbers), 0);

    std::cout << "original : ";
    copy(std::begin(numbers), std::end(numbers),
         std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int> prime;
    remove_copy_if(std::begin(numbers), std::end(numbers),
                   std::back_inserter(prime),
                   [](int n) {
                       if (n < 2)
                       {
                           return (n != 0) ? true : false;
                       }
                       else
                       {
                           for (int j = 2; j < n; j++)
                           {
                               if (n % j == 0)
                               {
                                   return false;
                               }
                           }
                       }
                       return true;
                   });

    std::cout << "primes : ";
    std::copy(std::begin(prime), std::end(prime),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

auto cppFold() -> void
{
    std::vector<int> numbers(5);
    std::iota(std::begin(numbers), std::end(numbers), 0);

    auto foldl = std::accumulate(std::begin(numbers), std::end(numbers), 0, std::plus<int>());
    auto foldr = std::accumulate(std::rbegin(numbers), std::rend(numbers), 0, std::plus<int>());

    std::cout << "foldl " << foldl << std::endl;
    std::cout << "foldr " << foldr << std::endl;
}

template <typename Func, typename... Args>
auto curry(Func func, Args... args)
{
    return [=](auto... lastParam) {
        return func(args..., lastParam...);
    };
}

auto areaOfRect(int length, int width)
{
    return length * width;
}

auto curring() -> void {
    auto length5 = curry(areaOfRect, 5);

    std::cout << "Curried with specific length =5" << std::endl;
    for (int i=0; i<5; i++) {
        std::cout << "length5(" << i << ") =";
        std::cout << length5(i) << std::endl;
    }
}

auto volumeOfRect(int length, int width, int height) {
    return length * width * height;
}
auto curring2() -> void {
    auto length5width4 = curry(volumeOfRect, 5, 4);

    std::cout << "Curried with length 5, width 4" << std::endl;

    for (int i=0; i<5; i++) {
        std::cout << "length5width4(" << i << ") = ";
        std::cout << length5width4(i) <<std::endl;
    }
}

auto main() -> int
{
    curring2();
    // curring();
    // cppFold();
    // cppFilterRemoveIf();
    // cppFilter();
    // cppMap();
}