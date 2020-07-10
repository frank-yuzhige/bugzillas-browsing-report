/**
 * Triggers ICE on x86-64 clang 11.0, when compiled with flag "-std=c++17"
 * https://godbolt.org/z/AaGSKJ
 * The bug is introduced in x86-64 clang 5.0.0 (the patch which clang first support c++17 standard).
 */

#include <tuple>
#include <ostream>
#include <iostream>

template <typename = void>
void f(const std::tuple<unsigned>& tpl) {
    std::apply([&](const auto&... values){
        ([x = values](){ /* Use X */ }(), ...);
    }, tpl);
}

int main() {
    std::tuple x { 3 };
    f(x);
}