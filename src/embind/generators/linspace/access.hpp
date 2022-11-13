#ifndef EMBIND_GENERATORS_LINSPACE_ACCESS_HPP
#define EMBIND_GENERATORS_LINSPACE_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <armadillo>
#include <string>

template<typename T>
val linspace(const double start, const double end, const arma::uword n) {
  return val(arma::linspace<T>(start, end, n));
}

#endif // EMBIND_GENERATORS_LINSPACE_ACCESS_HPP
