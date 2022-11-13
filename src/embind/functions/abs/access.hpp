#ifndef EMBIND_FUNCTIONS_ABS_ACCESS_HPP
#define EMBIND_FUNCTIONS_ABS_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <armadillo>

template<typename T>
T abs(T& inp) {
  return arma::abs(inp);
}

#endif // EMBIND_FUNCTIONS_ABS_ACCESS_HPP
