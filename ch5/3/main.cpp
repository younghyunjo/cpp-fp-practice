#include <iostream>
#include <functional>
#include <chrono>

template<typename T>
class Delay {
public:
    Delay(std::function<T()> func) : m_func(func) {}

    T Fetch() {
        return m_func();
    }
private:
    std::function<T()> m_func;
};

int fibonacci(int n) {
    if (n <= 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

auto nonmemoiztion() -> int {
    auto start = std::chrono::high_resolution_clock::now();

    int fib40Result = 0;

    Delay<int> fib40([]() {
        return fibonacci(40);
    });

    for (int i=0; i<=5; ++i) {
        std::cout << "Invocation " << i << std::endl;

        auto start = std::chrono::high_resolution_clock::now();

        fib40Result = fib40.Fetch();

        auto finish = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> elapsed = finish - start;

        std::cout << "Result:" << fib40Result << std::endl;
        std::cout << "Consumed:" << elapsed.count() << "ms" << std::endl;
    }

    auto finish = std::chrono::high_resolution_clock::now();

    auto elpased = finish - start;
    std::cout << "Total consumed:" << elpased.count() << "ms" << std::endl;

    return 0;
}

template<typename T>
class Memoization {
public:
    Memoization(std::function<T()> func) :
        m_func(func),
        m_subRoutine(&ForceSubroutine),
        m_recordedFunc(T()) {}

    T Fetch() {
        return m_subRoutine(this);
    }

private:
    std::function<T()> m_func;
    mutable T m_recordedFunc;
    T const & (*m_subRoutine)(Memoization *);

    static T const & ForceSubroutine(Memoization * d) {
        return d->DoRecording();
    }

    static T const & FetchSubroutine(Memoization * d) {
        return d->FetchRecording();
    }

    T const & FetchRecording() {
        return m_recordedFunc;
    }

    T const & DoRecording() {
        m_recordedFunc = m_func();
        m_subRoutine = &FetchSubroutine;
        return FetchRecording();
    }
};

auto memoization() -> int {
    auto start = std::chrono::high_resolution_clock::now();

    int fib40Result = 0;

    Memoization<int> fib40([] () {
        return fibonacci(40);
    });

    for (int i=0; i<=5; i++) {
        auto start = std::chrono::high_resolution_clock::now();

        fib40Result = fib40.Fetch();

        auto finish = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> elapsed = finish - start;

        std::cout << "Result:" << fib40Result << std::endl;
        std::cout << "Consumed:" << elapsed.count() << "ms" << std::endl;

    }

    auto finish = std::chrono::high_resolution_clock::now();

    auto elpased = finish - start;
    std::cout << "Total consumed:" << elpased.count() << "ms" << std::endl;

    return 0;
}

auto main() -> int {
    nonmemoiztion();
    memoization();
}