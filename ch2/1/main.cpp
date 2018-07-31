#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>

using std::back_inserter;
using std::count;
using std::endl;
using std::function;
using std::transform;
using std::vector;

typedef std::function<double(double)> HyperbolicFunc;

std::vector<HyperbolicFunc> funcs = {
    sinh,
    cosh,
    tanh,
    [](double x) {
        return x * x;
    }};

vector<HyperbolicFunc> inverseFuncs = {
    asinh,
    acosh,
    atanh,
    [](double x) {
        return exp(log(x) / 2);
    }};

template <typename A, typename B, typename C>
function<C(A)> compose(
    function<C(B)> f,
    function<B(A)> g)
{
    return [f, g](A x) {
        return f(g(x));
    };
};

template<typename A, typename B, typename C>
auto comopseAuto( std::function<C(B)> f, std::function<B(A)> g ) -> function<C(A)> {
    return [f, g](A x) {
        return f(g(x));
    };
}

auto main() -> int
{
    std::vector<HyperbolicFunc> composedFuncs;

    std::vector<double> nums;
    for (int i = 1; i <= 5; i++)
        nums.push_back(i * 0.2);

    transform(std::begin(inverseFuncs),
              std::end(inverseFuncs),
              std::begin(funcs),
              back_inserter(composedFuncs),
              comopseAuto<double, double, double>);

    for (auto num : nums)
    {
        for (auto func : composedFuncs)
        {
            std::cout << "f(g(" << num << "))" << func(num) << std::endl;
        }
    }
}
