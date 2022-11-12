#ifndef EMBIND_GENERATORS_REGISTER_HPP
#define EMBIND_GENERATORS_REGISTER_HPP

#include "access.hpp"

#define REGISTER_ARMA_GENERATORS() \
        function("linspace", GeneratorAccess::linspace) \
        ;

#endif // EMBIND_GENERATORS_REGISTER_HPP
