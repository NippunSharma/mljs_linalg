#ifndef EMBIND_CLASSES_COL_REGISTER_HPP
#define EMBIND_CLASSES_COL_REGISTER_HPP

#include "access.hpp"

#define REGISTER_ARMA_COL(T, name) \
        class_<arma::Col<T>, base<arma::Mat<T>>>(name) \
        .constructor<> () \
        .function("set_size", select_overload<void(const arma::uword)>(&arma::Col<T>::set_size)) \
        .function("get", &ColAccess<arma::Col<T>>::get) \
        .function("set", &ColAccess<arma::Col<T>>::set) \
        .function("set", &ColAccess<arma::Col<T>>::func_fill) \
        ;

#endif // EMBIND_CLASSES_COL_REGISTER_HPP
