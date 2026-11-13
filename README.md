# libtommath - Multiple-precision integer arithmetic C library

This is a `build2` package repository for
[`libtommath`](https://github.com/libtom/libtommath), a portable number
theoretic multiple-precision integer (MPI) arithmetic library written in C.

This file contains setup instructions and other details for developing the
package. If you want to use `libtommath` in your `build2`-based project, then
see the accompanying
[`PACKAGE-README.md`](libtommath/PACKAGE-README.md) file instead.

The development setup for `libtommath` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../libtommath.git
cd libtommath

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```

The package patches one upstream source file. See
[`libtommath/README-DEV`](libtommath/README-DEV) for details.
