# libtommath - Multiple-precision integer arithmetic C library

This is a `build2` package for the
[`libtommath`](https://github.com/libtom/libtommath) C library. It provides a
portable implementation of number theoretic multiple-precision integer (MPI)
arithmetic.


## Usage

To start using `libtommath` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libtommath ^1.3.0
```

Then import the library in your `buildfile`:

```
import libs = libtommath%lib{tommath}
```

The library interface is declared in the `<tommath.h>` header.

Note that when using the shared library built with MSVC, the multiplication
cutoff variables (`KARATSUBA_MUL_CUTOFF`, `KARATSUBA_SQR_CUTOFF`,
`TOOM_MUL_CUTOFF`, and `TOOM_SQR_CUTOFF`) are only accessible if they are
declared with `__declspec(dllimport)`, which `<tommath.h>` does not do. All
the library functions are accessible.
