#ifndef EMBIND_CLASSES_MAT_REGISTER_HPP
#define EMBIND_CLASSES_MAT_REGISTER_HPP

#include "access.hpp"
#include <armadillo>

#define REGISTER_ARMA_MAT(T, name) \
        class_<arma::Mat<T>>(name) \
        .constructor<>() \
        .function("set_size", select_overload<void(const arma::uword, const arma::uword)>(&arma::Mat<T>::set_size)) \
        .property("n_rows", &arma::Mat<T>::n_rows) \
        .property("n_cols", &arma::Mat<T>::n_cols) \
        .function("get", MatAccess<arma::Mat<T>>::get) \
        .function("set", MatAccess<arma::Mat<T>>::set) \
        ;

#endif EMBIND_CLASSES_MAT_REGISTER_HPP
