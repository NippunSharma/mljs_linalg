#ifndef EMBIND_GENERATORS_ACCESS_HPP
#define EMBIND_GENERATORS_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <armadillo>
#include <string>

struct GeneratorAccess {
  static val linspace(const double start, const double end, const std::string& type, const arma::uword n) {
    if (type == "Mat<double>")
      return val(arma::linspace<arma::Mat<double>>(start, end, n));
    if (type == "Mat<int>")
      return val(arma::linspace<arma::Mat<int>>(start, end, n));
    if (type == "Mat<float>")
      return val(arma::linspace<arma::Mat<float>>(start, end, n));

    if (type == "Row<double>")
      return val(arma::linspace<arma::Row<double>>(start, end, n));
    if (type == "Row<int>")
      return val(arma::linspace<arma::Row<int>>(start, end, n));
    if (type == "Row<float>")
      return val(arma::linspace<arma::Row<float>>(start, end, n));

    if (type == "Col<double>")
      return val(arma::linspace<arma::Col<double>>(start, end, n));
    if (type == "Col<int>")
      return val(arma::linspace<arma::Col<int>>(start, end, n));
    if (type == "Col<float>")
      return val(arma::linspace<arma::Col<float>>(start, end, n));

    return val::undefined();
  }
};

#endif // EMBIND_GENERATORS_ACCESS_HPP
