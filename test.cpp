template <int N>
class A
{
    int v{N};
};

template <int N = 10>
class B
{
    int v{N};
};

template <int = 10>
class C
{
    int v{0};
};

template <int>
class D
{
    int v{0};
};

template <int, int>
class E
{
    int v{0};
};

int main()
{
    A<10> a{};
    B<> b{};
    C<> c{};
    D<10> d{};
    E<10, 10> e{};
}