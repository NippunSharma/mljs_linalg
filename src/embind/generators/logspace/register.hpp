#ifndef EMBIND_GENERATORS_LOGSPACE_REGISTER_HPP
#define EMBIND_GENERATORS_LOGSPACE_REGISTER_HPP

#include "access.hpp"

#define REGISTER_GEN_LOGSPACE \
        function("logspace_mat_float", &logspace<arma::Mat<float>>); \
        function("logspace_row_float", &logspace<arma::Row<float>>); \
        function("logspace_col_float", &logspace<arma::Col<float>>);

#endif // EMBIND_GENERATORS_LOGSPACE_REGISTER_HPP
