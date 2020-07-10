# gcc & llvm bugzilla study report

Bug id `gcc:90736`, `gcc:95396`, and `clang:44512` are examples of how different optimization flags may lead to unexpected runtime behaviour of the code. Such miscompilations are more difficult to detect, as the effect of such unexpected behaviours will not be detected until someone actually runs the code and triggers the bug. If the code is running in production mode, it may cause bad consequences.

Bug id `gcc:96060`, `gcc:96097`, `gcc:96132`, `clang:46619`, `clang:46624`, `clang:46637`, `clang:46639` are cases which would trigger an ICE (Internal Compiler Error) of the compiler. ICEs are obvious fatal errors of the compiler, and they may sometimes make the compiler to reject valid programs.

Bug id `gcc:96137` makes the compiler to hang on. This can be treated as an ICE, and it has the potential to suspend the whole dev pipeline.

The file which triggers the bug can be found under the relevant folder. The way to reproduce the bug, the expected behaviour (if any), and the earliest version of the compiler that has the bug are recorded in the comments at the beginning of each file.
