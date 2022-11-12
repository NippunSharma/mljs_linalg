#ifndef EMBIND_CLASSES_MAT_ACCESS_HPP
#define EMBIND_CLASSES_MAT_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <string>
#include <armadillo>

template<typename MatType>
struct MatAccess {
      static val get(
          const MatType& self,
          arma::uword row_idx,
          arma::uword col_idx
      ) {
          if (row_idx < self.n_rows && col_idx < self.n_cols) {
              return val(self(row_idx, col_idx));
          } else {
              return val::undefined();
          }
      }

      static val get_submat(
          const MatType& self,
          arma::uword first_row,
          arma::uword first_col,
          arma::uword last_row,
          arma::uword last_col
      ) {
          return val(MatType(self.submat(first_row, first_col, last_row, last_col)));
      }

      static bool set_submat(
          MatType& self,
          arma::uword first_row,
          arma::uword first_col,
          arma::uword last_row,
          arma::uword last_col,
          MatType& new_val
      ) {
          self.submat(first_row, first_col, last_row, last_col) = new_val;
          return true;
      }

      static bool set(
          MatType& self,
          arma::uword row_idx,
          arma::uword col_idx,
          const typename MatType::elem_type& value
      ) {
          if (col_idx > self.n_cols || row_idx > self.n_rows)
            return false;

          self(row_idx, col_idx) = value;
          return true;
      }

      static bool set_size(
        MatType& self,
        arma::uword n_rows,
        arma::uword n_cols
      ) {
          self.set_size(n_rows, n_cols);
          return true;
      }

      static arma::uword n_rows(MatType& self) {
        return self.n_rows;
      }

      static arma::uword n_cols(MatType& self) {
        return self.n_cols;
      }

      static bool from_js_array(MatType& self, const val& v) {
        const arma::uword len = v["length"].as<arma::uword>();
        const arma::uword rows = n_rows(self);
        const arma::uword cols = n_cols(self);

        if (len != rows * cols)
          return false;

        for(int i = 0; i < rows; i++) {
          for(int j = 0; j < cols; j++) {
            self(i, j) = v[i * cols + j].as<const typename MatType::elem_type>();
          }
        }

        return true;
      }

      static bool zeros(MatType& self) {
        self.zeros();
        return true;
      }

      static bool ones(MatType& self) {
        self.ones();
        return true;
      }

      static bool eye(MatType& self) {
        self.eye();
        return true;
      }

      static bool randu(MatType& self) {
        self.randu();
        return true;
      }

      static bool randn(MatType& self) {
        self.randn();
        return true;
      }

      static bool fill(MatType& self, const typename MatType::elem_type& v) {
        self.fill(v);
        return true;
      }

      static bool clean(MatType& self, const typename MatType::elem_type& thres) {
        self.clean(thres);
        return true;
      }

      static bool replace(MatType& self, const typename MatType::elem_type& old_val,
          const typename MatType::elem_type& new_val) {
        self.replace(old_val, new_val);
        return true;
      }

      static bool clamp(MatType& self, const typename MatType::elem_type& min_val,
          const typename MatType::elem_type& max_val) {
        self.clamp(min_val, max_val);
        return true;
      }

      static bool transform(MatType& self, const val& func) {
        typedef typename MatType::elem_type elem_type;

        class functor {
          private:
            const val my_op;
          public:
            functor(const val& op): my_op(op) {}
            elem_type operator() (elem_type x) {
              return my_op(x).template as<elem_type>();
            }
        };

        self.transform(functor(func));
        return true;
      }

      static bool resize(MatType& self, const arma::uword& n_rows, const arma::uword& n_cols) {
        self.resize(n_rows, n_cols);
        return true;
      }

      static bool reshape(MatType& self, const arma::uword& n_rows, const arma::uword& n_cols) {
        self.reshape(n_rows, n_cols);
        return true;
      }

      static bool reset(MatType& self) {
        self.reset();
        return true;
      }

      static bool shed_row(MatType& self, arma::uword row_idx) {
        self.shed_row(row_idx);
        return true;
      }

      static bool shed_col(MatType& self, arma::uword col_idx) {
        self.shed_col(col_idx);
        return true;
      }

      static bool shed_rows(MatType& self, arma::uword first_row, arma::uword last_row) {
        self.shed_rows(first_row, last_row);
        return true;
      }

      static bool shed_cols(MatType& self, arma::uword first_col, arma::uword last_col) {
        self.shed_cols(first_col, last_col);
        return true;
      }
    
      static std::string str(MatType& self) {
        std::stringstream ostream;
        self.print(ostream);
        return ostream.str();
      }
};

#endif // EMBIND_CLASSES_MAT_ACCESS_HPP
