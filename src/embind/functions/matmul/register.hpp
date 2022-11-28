#ifndef EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP
#define EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP

#include "access.hpp"
#include <string>

#define REGISTER_FUNC_MATMUL(eT, name) \
        function((std::string("matmul_mat_row_") + std::string(name)).c_str(), &matmul<arma::Mat<eT>, arma::Row<eT>>); \
        function((std::string("matmul_mat_col_") + std::string(name)).c_str(), &matmul<arma::Mat<eT>, arma::Col<eT>>); \
        function((std::string("matmul_row_col_") + std::string(name)).c_str(), &matmul<arma::Row<eT>, arma::Col<eT>>); \
        function((std::string("matmul_mat_mat_") + std::string(name)).c_str(), &matmul<arma::Mat<eT>, arma::Mat<eT>>); \
        function((std::string("matmul_row_row_") + std::string(name)).c_str(), &matmul<arma::Row<eT>, arma::Row<eT>>); \
        function((std::string("matmul_col_col_") + std::string(name)).c_str(), &matmul<arma::Col<eT>, arma::Col<eT>>); \

#endif // EMBIND_FUNCTIONS_MATMUL_REGISTER_HPP
