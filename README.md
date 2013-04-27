# SWE 1D

## Dependencies

* [SCons](http://www.scons.org)
* [Doxygen](http://doxygen.org) (for documentation)

## Build Options

Build options can be supplied using 

    scons <command> [name=value [name=value] [...]]

Available options are

* `debug=1`: Use debug option `-g` (off by default)
* `optimize=<level>`: Use optimization level `-O<level>` (0 by default)
* `compiler=<name>`: Use different compiler, e.g. *clang* for LLVM/Clang

## Build

The default build command (".")

    scons
    
will build the executable `build/SWE1D`

## Testing

Unit tests can be built and run using

    scons check

## Running

See `./build/SWE1D --help` for runtime options

