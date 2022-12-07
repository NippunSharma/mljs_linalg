#ifndef SRC_EMBIND_UTILS_ACCESS_HPP
#define SRC_EMBIND_UTILS_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <armadillo>

template<typename eT>
arma::Mat<eT> row_to_mat(arma::Row<eT> row) {
  return row;
}

template<typename eT>
arma::Row<eT> mat_to_row(arma::Mat<eT> mat) {
  return mat.as_row();
}

template<typename eT>
arma::Mat<eT> col_to_mat(arma::Col<eT> col) {
  return col;
}

template<typename eT>
arma::Col<eT> mat_to_col(arma::Mat<eT> mat) {
  return mat.as_col();
}

#endif // SRC_EMBIND_UTILS_ACCESS_HPP
