#pragma once
/*
#include "Matrix.h"

template<typename T>
class MatrixAdd
{
public:
    static Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        if (lhs.getRows() != rhs.getRows() || lhs.getCols() != rhs.getCols()) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        Matrix<T> result(lhs.getRows(), lhs.getCols());
        for (size_t i = 0; i < lhs.getRows(); ++i) {
            for (size_t j = 0; j < lhs.getCols(); ++j) {
                result.at(i, j) = lhs.at(i, j) + rhs.at(i, j);
            }
        }
        return result;
    }
};

template<typename T>
class MatrixSub
{
public:
    static Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        if (lhs.getRows() != rhs.getRows() || lhs.getCols() != rhs.getCols()) {
            throw std::invalid_argument("Matrix dimensions must match for subtraction");
        }

        Matrix<T> result(lhs.getRows(), lhs.getCols());
        for (size_t i = 0; i < lhs.getRows(); ++i) {
            for (size_t j = 0; j < lhs.getCols(); ++j) {
                result.at(i, j) = lhs.at(i, j) - rhs.at(i, j);
            }
        }
        return result;
    }
};

template<typename T>
class MatrixMul
{
public:
    static Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        if (lhs.getCols() != rhs.getRows()) {
            throw std::invalid_argument("Matrix dimensions must be compatible for multiplication");
        }

        Matrix<T> result(lhs.getRows(), rhs.getCols());
        for (size_t i = 0; i < lhs.getRows(); ++i) {
            for (size_t j = 0; j < rhs.getCols(); ++j) {
                result.at(i, j) = T();  // Inicjalizacja elementu na 0
                for (size_t k = 0; k < lhs.getCols(); ++k) {
                    result.at(i, j) += lhs.at(i, k) * rhs.at(k, j);
                }
            }
        }
        return result;
    }
};

*/