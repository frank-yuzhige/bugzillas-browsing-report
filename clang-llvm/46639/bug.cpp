/**
 * Triggers ICE on x86-64 clang 11.0.0.
 * https://godbolt.org/z/VuonmD
 * The bug is first introduced in x86-64 clang 10.0.0.
 */

# 1 "<built-in>"
# 1 "test.cpp"

 class A {
	 public:
	 ~A(){} // needed to cause the error
 };

int main() {

  auto a = new A[2][3];
  
  A (*b) [] = (A (*)[])a; // Adding dimension solves the error too.
  
  delete[] b;

  return 0;
}
