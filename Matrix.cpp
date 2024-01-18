#include "Matrix.h"

Matrix::Matrix(size_t rows, size_t cols)
    : data(make_unique<vector<vector<double>>>(rows, vector<double>(cols, 0.0))),
    rows(rows), cols(cols) {}

Matrix::Matrix(const Matrix& other)
    : data(make_unique<vector<vector<double>>>(*other.data)),
    rows(other.rows), cols(other.cols) {}

Matrix::Matrix(Matrix&& other) noexcept
    : data(move(other.data)), rows(other.rows), cols(other.cols) {}

size_t Matrix::getRows() const { return rows; }
size_t Matrix::getCols() const { return cols; }

double Matrix::determinant() const {
    if (rows != cols) {
        throw runtime_error("Wyznacznik tylko dla macierzy kwadratowej");
    }

    if (rows == 1) {
        return at(0, 0);
    }

    double det = 0.0;
    for (size_t i = 0; i < cols; ++i) {
        det += (i % 2 == 0 ? 1 : -1) * at(0, i) * this->getMinor(0, i).determinant();
    }
    return det;
}

double& Matrix::at(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
        throw out_of_range("Indeks poza zakresem");
    }
    return (*data)[row][col];
}

const double& Matrix::at(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw out_of_range("Indeks poza zakresem");
    }
    return (*data)[row][col];
}

Matrix Matrix::operator+(const Matrix& rhs) const {
    if (this->rows != rhs.rows || this->cols != rhs.cols) {
        throw invalid_argument("Wymiary macierzy musz¹ byæ zgodne");
    }

    Matrix result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.at(i, j) = this->at(i, j) + rhs.at(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& rhs) const {
    if (this->rows != rhs.rows || this->cols != rhs.cols) {
        throw invalid_argument("Wymiary macierzy musz¹ byæ zgodne");
    }

    Matrix result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.at(i, j) = this->at(i, j) - rhs.at(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (this->cols != rhs.rows) {
        throw invalid_argument("Wymiary macierzy musz¹ byæ zgodne");
    }

    Matrix result(this->rows, rhs.cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < rhs.cols; ++j) {
            for (size_t k = 0; k < this->cols; ++k) {
                result.at(i, j) += this->at(i, k) * rhs.at(k, j);
            }
        }
    }
    return result;
}

Matrix Matrix::getMinor(size_t row, size_t col) const {
    Matrix minor(rows - 1, cols - 1);
    for (size_t i = 0, mi = 0; i < rows; ++i) {
        if (i == row) continue;
        for (size_t j = 0, mj = 0; j < cols; ++j) {
            if (j == col) continue;
            minor.at(mi, mj) = at(i, j);
            mj++;
        }
        mi++;
    }
    return minor;
}

Matrix Matrix::transpose() const {
    Matrix transposed(cols, rows);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            transposed.at(j, i) = this->at(i, j);
        }
    }
    return transposed;
}

double Matrix::trace() const {
    if (rows != cols) {
        throw invalid_argument("Slad tylko dla macierzy kwadratowej");
    }
    double traceSum = 0.0;
    for (size_t i = 0; i < rows; ++i) {
        traceSum += at(i, i);
    }
    return traceSum;
}

Matrix Matrix::createIdentityMatrix(size_t size) {
    Matrix identity(size, size);
    for (size_t i = 0; i < size; ++i) {
        identity.at(i, i) = 1.0;
    }
    return identity;
}

Matrix Matrix::createZeroMatrix(size_t rows, size_t cols) {
    return Matrix(rows, cols);
}
