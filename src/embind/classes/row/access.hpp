#ifndef EMBIND_CLASSES_ROW_ACCESS_HPP
#define EMBIND_CLASSES_ROW_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <string>
#include <armadillo>

template<typename RowType>
struct RowAccess {
      static val get(
          const RowType& self,
          arma::uword idx
      ) {
          if (idx < self.n_elem) {
              return val(self(idx));
          } else {
              return val::undefined();
          }
      }

      static bool set(
          RowType& self,
          arma::uword idx,
          const typename RowType::elem_type& value
      ) {
          if (idx >= self.n_elem)
            return false;

          self(idx) = value;
          return true;
      }

      static bool set_size(
        RowType& self,
        arma::uword n_elem
      ) {
          self.set_size(n_elem);
          return true;
      }
};

#endif // EMBIND_CLASSES_ROW_ACCESS_HPP
