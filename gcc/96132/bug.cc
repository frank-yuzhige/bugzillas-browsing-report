/**
 * Triggers ICE on x86-64 gcc 11.0(experimental).
 * https://godbolt.org/z/VrzgsQ
 * The bug is introduced in x86-64 gcc 11.0.
 */

template <int> class a;
template <int b> class c {
  a<b> e;
  void operator=(c d) { e = d; }
};
