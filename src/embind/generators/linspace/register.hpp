#ifndef EMBIND_GENERATORS_LINSPACE_REGISTER_HPP
#define EMBIND_GENERATORS_LINSPACE_REGISTER_HPP

#include "access.hpp"

#define REGISTER_GEN_LINSPACE \
        function("linspace_mat_double", &linspace<arma::Mat<double>>); \
        function("linspace_mat_int", &linspace<arma::Mat<int>>); \
        function("linspace_mat_float", &linspace<arma::Mat<float>>); \
        function("linspace_row_double", &linspace<arma::Row<double>>); \
        function("linspace_row_int", &linspace<arma::Row<int>>); \
        function("linspace_row_float", &linspace<arma::Row<float>>); \
        function("linspace_col_double", &linspace<arma::Col<double>>); \
        function("linspace_col_int", &linspace<arma::Col<int>>); \
        function("linspace_col_float", &linspace<arma::Col<float>>);

#endif // EMBIND_GENERATORS_LINSPACE_REGISTER_HPP
