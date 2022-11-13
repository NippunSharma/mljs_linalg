#include "globalconfig.hpp"

#include "classes/mat/register.hpp"
#include "classes/row/register.hpp"
#include "classes/col/register.hpp"

#include "generators/linspace/register.hpp"
#include "generators/logspace/register.hpp"

#include <emscripten/bind.h>
using namespace emscripten;

EMSCRIPTEN_BINDINGS(webml_linalg) {
  REGISTER_ARMA_MAT(double, "arma_mat_double")
  REGISTER_ARMA_MAT(int, "arma_mat_int")
  REGISTER_ARMA_MAT(float, "arma_mat_float")

  REGISTER_ARMA_ROW(double, "arma_row_double")
  REGISTER_ARMA_ROW(int, "arma_row_int")
  REGISTER_ARMA_ROW(float, "arma_row_float")

  REGISTER_ARMA_COL(double, "arma_col_double")
  REGISTER_ARMA_COL(int, "arma_col_int")
  REGISTER_ARMA_COL(float, "arma_col_float")

  REGISTER_GEN_LINSPACE
  REGISTER_GEN_LOGSPACE
}
