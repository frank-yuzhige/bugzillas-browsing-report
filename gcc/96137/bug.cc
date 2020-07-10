/**
 * This piece of code makes x86-64 gcc 11.0 hang on. 
 * The bug is introduced in x86-64 gcc 11.0.
 */

void a () { .operator b }