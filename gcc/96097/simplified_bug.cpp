/**
 * A reduced version of bug.cpp that also generates the same bug.
 */ 

template <template <typename T, typename T::type> typename>
void func() {}

template <typename, int>
struct Y {};

void test()
{
    func<Y>();
}