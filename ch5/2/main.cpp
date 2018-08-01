#include <iostream>
#include <functional>

template<class T>
class Memoization {
public:
    Memoization(std::function<T()> func) :
        m_func(func),
        m_subRoutine(&ForceSubroutine),
        m_recordedFunc(T()) {
    }

    T fetch()
    {
        return m_subRoutine(this);
    }

private:
    T const & (*m_subRoutine)(Memoization *);
    mutable T m_recordedFunc;
    std::function<T()> m_func;

    static T const & ForceSubroutine(Memoization *  d) {
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

auto main() -> int {
    int a = 10;
    int b = 5;
    int multiplexer = 0;

    Memoization<int> multiply_impure([&]() {
        return multiplexer * a * b;
    });

    for (int i=0; i<5; ++i) {
        ++multiplexer;
        std::cout << "multiplexer:" << multiplexer << std::endl;
        std::cout << "a * b =" << multiply_impure.fetch();
        std::cout << std::endl;
    }

    return 0;
}