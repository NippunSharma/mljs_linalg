#include "globalconfig.hpp"

#include "classes/mat/register.hpp"
#include "classes/row/register.hpp"
#include "classes/col/register.hpp"

#include "generators/linspace/register.hpp"
#include "generators/logspace/register.hpp"
#include "generators/regspace/register.hpp"

#include "functions/abs/register.hpp"
#include "functions/accu/register.hpp"
#include "functions/affmul/register.hpp"
#include "functions/approx_equal/register.hpp"
#include "functions/approx_equal/register.hpp"
#include "functions/matmul/register.hpp"

#include <emscripten/bind.h>
using namespace emscripten;

EMSCRIPTEN_BINDINGS(webml_linalg) {
  REGISTER_ARMA_MAT(int, "arma_mat_int")
  REGISTER_ARMA_MAT(float, "arma_mat_float")

  REGISTER_ARMA_ROW(int, "arma_row_int")
  REGISTER_ARMA_ROW(float, "arma_row_float")

  REGISTER_ARMA_COL(int, "arma_col_int")
  REGISTER_ARMA_COL(float, "arma_col_float")

  REGISTER_GEN_LINSPACE
  REGISTER_GEN_LOGSPACE
  REGISTER_GEN_REGSPACE

  REGISTER_FUNC_ABS
  REGISTER_FUNC_ACCU
  REGISTER_FUNC_AFFMUL

  REGISTER_FUNC_APPROX_EQUAL(float, "float")
  REGISTER_FUNC_APPROX_EQUAL(int, "int")

  REGISTER_FUNC_MATMUL(float, "float")
  REGISTER_FUNC_MATMUL(int, "int")
}
