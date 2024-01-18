#pragma once
#include <cstddef>

using namespace std;

class AbstractMatrix {
public:
    virtual size_t getRows() const = 0;
    virtual size_t getCols() const = 0;
    virtual double determinant() const = 0;
    virtual double& at(size_t row, size_t col) = 0;
    virtual const double& at(size_t row, size_t col) const = 0;
    virtual ~AbstractMatrix() = default;
    };