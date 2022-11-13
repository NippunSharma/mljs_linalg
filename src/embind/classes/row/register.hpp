#ifndef EMBIND_CLASSES_ROW_REGISTER_HPP
#define EMBIND_CLASSES_ROW_REGISTER_HPP

#include "access.hpp"

#define REGISTER_ARMA_ROW(T, name) \
        class_<arma::Row<T>, base<arma::Mat<T>>>(name) \
        .constructor<> () \
        .function("set_size", select_overload<void(const arma::uword)>(&arma::Row<T>::set_size)) \
        .function("get", &RowAccess<arma::Row<T>>::get) \
        .function("set", &RowAccess<arma::Row<T>>::set) \
        .function("func_fill", &RowAccess<arma::Row<T>>::func_fill) \
        ;

#endif // EMBIND_CLASSES_ROW_REGISTER_HPP
