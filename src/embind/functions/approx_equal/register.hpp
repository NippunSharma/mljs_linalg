#ifndef EMBIND_FUNCTIONS_APPROX_EQUAL_REGISTER_HPP
#define EMBIND_FUNCTIONS_APPROX_EQUAL_REGISTER_HPP

#include "access.hpp"
#include <string>

#define REGISTER_FUNC_APPROX_EQUAL(eT, name) \
        function((std::string("approx_equal_mat_row_") + std::string(name)).c_str(), &approx_equal<arma::Mat<eT>, arma::Row<eT>>); \
        function((std::string("approx_equal_mat_col_") + std::string(name)).c_str(), &approx_equal<arma::Mat<eT>, arma::Col<eT>>); \
        function((std::string("approx_equal_row_col_") + std::string(name)).c_str(), &approx_equal<arma::Row<eT>, arma::Col<eT>>); \

#endif // EMBIND_FUNCTIONS_APPROX_EQUAL_REGISTER_HPP
