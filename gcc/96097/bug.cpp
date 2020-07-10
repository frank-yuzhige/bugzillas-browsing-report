/**
 * Triggers ICE on x86-64 gcc 10.1 with flag "-std=c++17"
 * The bug is first introduced in x86-64 gcc 5.1 (the version which gcc begins to support c++17 standard).
 */

template <
    typename A,
    template <typename T, typename T::typeX> typename TA>
auto func()
{
    return TA<typename A::typeY, 0>{};
}

struct X { using typeX = int; };

template <typename T, int>
// template <typename T, typename T::typeX>  // works
struct Y { using typeY = T; };

void test()
{
    func<Y<X, 0>, Y>();
}
