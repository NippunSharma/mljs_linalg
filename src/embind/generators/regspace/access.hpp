#ifndef EMBIND_GENERATORS_REGSPACE_ACCESS_HPP
#define EMBIND_GENERATORS_REGSPACE_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <armadillo>
#include <string>
#include <utility>

template<typename T>
val regspace(const double start, const double delta, const double end) {
  return val(arma::regspace<T>(start, delta, end));
}

#endif // EMBIND_GENERATORS_REGSPACE_ACCESS_HPP
