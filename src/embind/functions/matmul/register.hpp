#ifndef EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP
#define EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP

#include "access.hpp"
#include <string>

#define REGISTER_FUNC_MATMUL \
        function("matmul_float_int", &matmul<arma::Mat<float>, arma::Mat<int> >); \
        function("matmul_float_float", &matmul<arma::Mat<float>, arma::Mat<float> >); \
        function("matmul_int_int", &matmul<arma::Mat<int>, arma::Mat<int> >); \

#endif // EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP
