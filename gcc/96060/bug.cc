/**
 * Triggers ICE (segmentation fault) on x86-64 gcc 11.0(experimental) with flag "-std=c++20".
 * The bug can also be found on any version of gcc that supports c++20 standard.
 */

#include <set>

struct xx {
    int a;
    int operator<=>(const xx&) const = default;
};

int f(std::set<xx> &x) {
    x.emplace(0);
    return 0;
}