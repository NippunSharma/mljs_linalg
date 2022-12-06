#ifndef EMBIND_GENERATORS_REGSPACE_REGISTER_HPP
#define EMBIND_GENERATORS_REGSPACE_REGISTER_HPP

#include "access.hpp"

#define REGISTER_GEN_REGSPACE \
        function("regspace_mat_float", &regspace<arma::Mat<float>>); \
        function("regspace_mat_int", &regspace<arma::Mat<int>>); \
        function("regspace_row_float", &regspace<arma::Row<float>>); \
        function("regspace_row_int", &regspace<arma::Row<int>>); \
        function("regspace_col_float", &regspace<arma::Col<float>>); \
        function("regspace_col_int", &regspace<arma::Col<int>>);

#endif // EMBIND_GENERATORS_REGSPACE_REGISTER_HPP
