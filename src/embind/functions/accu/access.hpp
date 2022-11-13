#ifndef EMBIND_FUNCTIONS_ACCU_ACCESS_HPP
#define EMBIND_FUNCTIONS_ACCU_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <armadillo>

template<typename T>
typename T::elem_type accu(T& inp) {
  return arma::accu(inp);
}

#endif // EMBIND_FUNCTIONS_ACCU_ACCESS_HPP
