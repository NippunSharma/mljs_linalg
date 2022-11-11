#ifndef EMBIND_CLASSES_MAT_ACCESS_HPP
#define EMBIND_CLASSES_MAT_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <armadillo>

template<typename MatType>
struct MatAccess {
      static val get(
          const MatType& v,
          arma::uword row_idx,
          arma::uword col_idx
      ) {
          if (row_idx < v.n_rows && col_idx < v.n_cols) {
              return val(v(row_idx, col_idx));
          } else {
              return val::undefined();
          }
      }

      static bool set(
          MatType& v,
          arma::uword row_idx,
          arma::uword col_idx,
          const typename MatType::elem_type& value
      ) {
          if (col_idx > v.n_cols || row_idx > v.n_rows)
            return false;

          v(row_idx, col_idx) = value;
          return true;
      }
};

#endif // EMBIND_CLASSES_MAT_ACCESS_HPP
