/**
 * Triggers ICE on x86-64 clang 11.0, when compiled with flag "-g"
 * https://godbolt.org/z/UrGRYG
 * The bug is introduced in x86-64 clang 6.0.0.
 */

template<typename T> struct X { T* p; };
X<auto () -> auto> x;