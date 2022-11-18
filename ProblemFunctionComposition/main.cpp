#include <utility>

template <typename T>
class FunctionComposition final
{
private:
    T m_f, m_g;

public:
    FunctionComposition(T f, T g) : m_f(f), m_g(g) {}

    
};

template <typename T>
FunctionComposition<T> make_function_composition(T f, T g)
{

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

    auto h2 = make_function_composition(g, f); // g(f())
    auto res2 = h2(2.0); // res2 <- 16.0
    return 0;
}