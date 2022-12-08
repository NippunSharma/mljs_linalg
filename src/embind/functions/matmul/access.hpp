#ifndef EMBIND_FUNCTIONS_MATMUL_ACCESS_HPP
#define EMBIND_FUNCTIONS_MATMUL_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <utility>
#include <armadillo>

template<typename T, typename U>
struct get_output_type {
  using type = std::conditional_t<std::is_same_v<T, U>, T,
      std::conditional_t<(std::is_floating_point_v<T> || std::is_floating_point_v<U>), double_t, T>>;
};

template<typename T, typename U>
using get_output_type_t = typename get_output_type<T,U>::type;

template<typename T, typename U>
auto matmul(const T& A, const U& B) ->
std::enable_if_t<((arma::is_Mat<T>::value || arma::is_Row<T>::value || arma::is_Col<T>::value) &&
(arma::is_Mat<U>::value || arma::is_Row<U>::value || arma::is_Col<U>::value)),
arma::Mat<get_output_type_t<typename T::elem_type, typename U::elem_type>>> {
  return A * B;
}

#endif // EMBIND_FUNCTIONS_MATMUL_ACCESS_HPP
