#include "globalconfig.hpp"

#include "classes/mat/register.hpp"
#include "classes/row/register.hpp"

#include <emscripten/bind.h>
using namespace emscripten;

EMSCRIPTEN_BINDINGS(webml_linalg) {
  REGISTER_ARMA_MAT(double, "ArmaMatDouble")
  REGISTER_ARMA_MAT(int, "ArmaMatInt")
  REGISTER_ARMA_MAT(float, "ArmaMatFloat")

  REGISTER_ARMA_ROW(double, "ArmaRowDouble")
  REGISTER_ARMA_ROW(int, "ArmaRowInt")
  REGISTER_ARMA_ROW(float, "ArmaRowFloat")
}
