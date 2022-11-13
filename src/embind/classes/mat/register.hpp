#ifndef EMBIND_CLASSES_MAT_REGISTER_HPP
#define EMBIND_CLASSES_MAT_REGISTER_HPP

#include "access.hpp"

#define REGISTER_ARMA_MAT(T, name) \
        class_<arma::Mat<T>>(name) \
        .constructor<>() \
        .function("set_size", &MatAccess<arma::Mat<T>>::set_size) \
        .function("n_rows", &MatAccess<arma::Mat<T>>::n_rows) \
        .function("n_cols", &MatAccess<arma::Mat<T>>::n_cols) \
        .function("get", &MatAccess<arma::Mat<T>>::get) \
        .function("set", &MatAccess<arma::Mat<T>>::set) \
        .function("get_submat", &MatAccess<arma::Mat<T>>::get_submat) \
        .function("set_submat", &MatAccess<arma::Mat<T>>::set_submat) \
        .function("from_array", &MatAccess<arma::Mat<T>>::from_js_array) \
        .function("zeros", &MatAccess<arma::Mat<T>>::zeros) \
        .function("ones", &MatAccess<arma::Mat<T>>::ones) \
        .function("eye", &MatAccess<arma::Mat<T>>::eye) \
        .function("randu", &MatAccess<arma::Mat<T>>::randu) \
        .function("randn", &MatAccess<arma::Mat<T>>::randn) \
        .function("fill", &MatAccess<arma::Mat<T>>::fill) \
        .function("clean", &MatAccess<arma::Mat<T>>::clean) \
        .function("replace", &MatAccess<arma::Mat<T>>::replace) \
        .function("clamp", &MatAccess<arma::Mat<T>>::clamp) \
        .function("transform", &MatAccess<arma::Mat<T>>::transform) \
        .function("resize", &MatAccess<arma::Mat<T>>::resize) \
        .function("reshape", &MatAccess<arma::Mat<T>>::reshape) \
        .function("reset", &MatAccess<arma::Mat<T>>::reset) \
        .function("str", &MatAccess<arma::Mat<T>>::str) \
        .function("shed_row", &MatAccess<arma::Mat<T>>::shed_row) \
        .function("shed_col", &MatAccess<arma::Mat<T>>::shed_col) \
        .function("shed_rows", &MatAccess<arma::Mat<T>>::shed_rows) \
        .function("shed_cols", &MatAccess<arma::Mat<T>>::shed_cols) \
        .function("func_fill", &MatAccess<arma::Mat<T>>::func_fill) \
        ;

#endif EMBIND_CLASSES_MAT_REGISTER_HPP
