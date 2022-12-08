#ifndef EMBIND_FUNCTIONS_ABS_REGISTER_HPP
#define EMBIND_FUNCTIONS_ABS_REGISTER_HPP

#include "access.hpp"

#define REGISTER_FUNC_ABS \
        function("abs_mat_double", &abs<arma::Mat<double>>); \
        function("abs_mat_int", &abs<arma::Mat<int>>); \
        function("abs_row_double", &abs<arma::Row<double>>); \
        function("abs_row_int", &abs<arma::Row<int>>); \
        function("abs_col_double", &abs<arma::Col<double>>); \
        function("abs_col_int", &abs<arma::Col<int>>); \

#endif // EMBIND_FUNCTIONS_ABS_REGISTER_HPP
