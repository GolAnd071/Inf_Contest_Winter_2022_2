
class FunctionComposition final
{

};

FunctionComposition make_function_composition()
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