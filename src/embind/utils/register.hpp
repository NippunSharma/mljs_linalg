#ifndef SRC_EMBIND_UTILS_REGISTER_HPP
#define SRC_EMBIND_UTILS_REGISTER_HPP

#include "access.hpp"
#include <string>

#define REGISTER_UTILS(eT, name) \
        function((std::string("mat_to_row_") + std::string(name)).c_str(), &mat_to_row<eT>); \
        function((std::string("row_to_mat_") + std::string(name)).c_str(), &row_to_mat<eT>); \
        function((std::string("mat_to_col_") + std::string(name)).c_str(), &mat_to_col<eT>); \
        function((std::string("col_to_mat_") + std::string(name)).c_str(), &col_to_mat<eT>); \

#endif // SRC_EMBIND_UTILS_REGISTER_HPP
