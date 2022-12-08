#ifndef EMBIND_FUNCTIONS_AFFMUL_REGISTER_HPP
#define EMBIND_FUNCTIONS_AFFMUL_REGISTER_HPP

#include "access.hpp"

#define REGISTER_FUNC_AFFMUL \
        function("affmul_double", &affmul<double>); \
        function("affmul_int", &affmul<int>); \

#endif // EMBIND_FUNCTIONS_AFFMUL_REGISTER_HPP
