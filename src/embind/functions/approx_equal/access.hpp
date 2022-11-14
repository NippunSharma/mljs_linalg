#ifndef EMBIND_FUNCTIONS_APPROX_EQUAL_ACCESS_HPP
#define EMBIND_FUNCTIONS_APPROX_EQUAL_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <utility>
#include <armadillo>

template<typename T, typename U>
auto approx_equal(const T& A, const U& B, const std::string& method, const typename T::pod_type abs_tol, const typename T::pod_type rel_tol) ->
  std::enable_if_t<(arma::is_arma_type<T>::value && arma::is_arma_type<U>::value &&
      std::is_same<typename T::elem_type, typename U::elem_type>::value), bool> {
  return arma::approx_equal(A, B, method.c_str(), abs_tol, rel_tol);
}

#endif // EMBIND_FUNCTIONS_APPROX_EQUAL_ACCESS_HPP
