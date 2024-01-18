#pragma once

#include "AbstractMatrix.h"
#include <vector>
#include <memory>
#include <stdexcept>

class Matrix : public AbstractMatrix {
private:
    unique_ptr<vector<vector<double>>> data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;

    size_t getRows() const override;
    size_t getCols() const override;
    double determinant() const override;
    double& at(size_t row, size_t col) override;
    const double& at(size_t row, size_t col) const override;

    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;

    Matrix getMinor(size_t row, size_t col) const;
    Matrix transpose() const;
    double trace() const;

    static Matrix createIdentityMatrix(size_t size);
    static Matrix createZeroMatrix(size_t rows, size_t cols);
};
