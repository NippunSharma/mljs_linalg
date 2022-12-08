#ifndef EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP
#define EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP

#include "access.hpp"
#include <string>

#define REGISTER_FUNC_MATMUL \
        function("matmul_double_int", &matmul<arma::Mat<double>, arma::Mat<int> >); \
        function("matmul_double_double", &matmul<arma::Mat<double>, arma::Mat<double> >); \
        function("matmul_int_int", &matmul<arma::Mat<int>, arma::Mat<int> >); \

#endif // EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP
