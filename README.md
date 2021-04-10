[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

# Info1 Library for C

The purpose of this library is to provide initial support to Info1 (Introduction to CS) students at National Technological University as they begin programming in C, in the same way that training wheels work on a bicycle. It is based on Harvard CS50's [libcs50](https://github.com/cs50/libcs50).

## Getting Started

### Prerequisites

To build the library from source, the following tools are needed:

 * git
 * make
 * gcc

On Ubuntu/Debian, you can install them with:

```shell
  sudo apt-get install git build-essential
```

On other platforms, please use the corresponding package managing tool to
install them before proceeding.

### Building

You can get the source by "git clone" this git repository.

```shell
  git clone https://github.com/jballoffet/libinfo1.git
```

To build the library execute the following:

```shell
  cd libinfo1
  make
```

### Installing

To install the library execute the following:

```shell
  cd libinfo1
  sudo make install
```

Note: By default, the library will be installed to `/usr/local`. In case you'd like to change the installation location, change the value of `INSTALL_DIR` in the [Makefile](https://github.com/jballoffet/libinfo1/blob/master/Makefile).

### Uninstalling

To uninstall the library execute the following:

```shell
  cd libinfo1
  sudo make uninstall
```

### Running the test app

To run the test application execute the following:

```shell
  cd libinfo1
  make test
```

## Authors

 * [Javier Balloffet](https://github.com/jballoffet) ([National Technological University - Buenos Aires](https://www.frba.utn.edu.ar/en/))

## Maintainers

 * [Javier Balloffet](https://github.com/jballoffet) ([National Technological University - Buenos Aires](https://www.frba.utn.edu.ar/en/))

## License

This project is licensed under the MIT License. See the [LICENSE](/LICENSE) file for details.

## References

Library inspired by and based on:

- https://github.com/cs50/libcs50
