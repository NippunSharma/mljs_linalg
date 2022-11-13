#ifndef EMBIND_GENERATORS_LOGSPACE_ACCESS_HPP
#define EMBIND_GENERATORS_LOGSPACE_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <armadillo>
#include <string>
#include <utility>

template<typename T, typename = std::enable_if_t<(arma::is_Mat<T>::value && arma::is_real<typename T::pod_type>::value), T>>
val logspace(const double start, const double end, const arma::uword n) {
  return val(arma::logspace<T>(start, end, n));
}

#endif // EMBIND_GENERATORS_LOGSPACE_ACCESS_HPP
