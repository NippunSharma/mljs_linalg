#ifndef EMBIND_GENERATORS_LOGSPACE_REGISTER_HPP
#define EMBIND_GENERATORS_LOGSPACE_REGISTER_HPP

#include "access.hpp"

#define REGISTER_GEN_LOGSPACE \
        function("logspace_mat_double", &logspace<arma::Mat<double>>); \
        function("logspace_row_double", &logspace<arma::Row<double>>); \
        function("logspace_col_double", &logspace<arma::Col<double>>);

#endif // EMBIND_GENERATORS_LOGSPACE_REGISTER_HPP
