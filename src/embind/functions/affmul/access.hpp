#ifndef EMBIND_FUNCTIONS_AFFMUL_ACCESS_HPP
#define EMBIND_FUNCTIONS_AFFMUL_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <utility>
#include <armadillo>

template<typename T>
arma::Mat<T> affmul(const val& A, const val& B) {
  typedef arma::Mat<T> ArmaMatType;
  return ArmaMatType(arma::affmul(A.as<ArmaMatType>(), B.as<ArmaMatType>()));
}

#endif // EMBIND_FUNCTIONS_AFFMUL_ACCESS_HPP
