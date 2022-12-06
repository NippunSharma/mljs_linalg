#ifndef EMBIND_FUNCTIONS_ACCU_REGISTER_HPP
#define EMBIND_FUNCTIONS_ACCU_REGISTER_HPP

#include "access.hpp"

#define REGISTER_FUNC_ACCU \
        function("accu_mat_float", &accu<arma::Mat<float>>); \
        function("accu_mat_int", &accu<arma::Mat<int>>); \
        function("accu_row_float", &accu<arma::Row<float>>); \
        function("accu_row_int", &accu<arma::Row<int>>); \
        function("accu_col_float", &accu<arma::Col<float>>); \
        function("accu_col_int", &accu<arma::Col<int>>); \

#endif // EMBIND_FUNCTIONS_ACCU_REGISTER_HPP
