#include <utility>
#include <iostream>

template<typename T, typename U>
class FunctionComposition
{
private:
    const T& m_f;
    const U& m_g;

public:
    FunctionComposition(const T& f, const U& g) : m_f(f), m_g(g) {}

    template<typename V>
    using ReturnValue = decltype(std::declval<T>()(std::declval<U>()(std::declval<V>())));

    template<typename V>
    ReturnValue<V> operator()(V x) const
    {
        return m_f(m_g(x));
    }
};

template<typename T, typename U>
FunctionComposition<T, U> make_function_composition(const T& f, const U& g) {
    return FunctionComposition<T, U>(f, g);
}

double f(double x) {
    return x + x;
}

double g(double x) {
    return x * x;
}

int main() {
    auto h1 = make_function_composition(f, g); // f(g())
    auto res1 = h1(2.0); // res1 <- 8.0
    std::cout << res1 << '\n';

    auto h2 = make_function_composition(g, f); // g(f())
    auto res2 = h2(2.0); // res2 <- 16.0
    std::cout << res2 << '\n';
    return 0;
}