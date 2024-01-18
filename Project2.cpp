#include "Matrix.h"
#include <iostream>

int main() {
    try {
        // Tworzenie macierzy
        Matrix m1(3, 3);
        m1.at(0, 0) = 1; m1.at(0, 1) = 2; m1.at(0, 2) = 3;
        m1.at(1, 0) = 4; m1.at(1, 1) = 5; m1.at(1, 2) = 6;
        m1.at(2, 0) = 7; m1.at(2, 1) = 8; m1.at(2, 2) = 9;

        Matrix m2 = Matrix::createIdentityMatrix(3);

        // Wyświetlanie macierzy m1
        cout << "Macierz m1:\n";
        for (size_t i = 0; i < m1.getRows(); ++i) {
            for (size_t j = 0; j < m1.getCols(); ++j) {
                cout << m1.at(i, j) << " ";
            }
            cout << "\n";
        }

        // Dodawanie macierzy
        Matrix sum = m1 + m2;
        cout << "Suma macierzy m1 i m2:\n";
        for (size_t i = 0; i < sum.getRows(); ++i) {
            for (size_t j = 0; j < sum.getCols(); ++j) {
                cout << sum.at(i, j) << " ";
            }
            cout << "\n";
        }

        // Odejmowanie macierzy
        Matrix diff = m1 - m2;
        cout << "Różnica macierzy m1 i m2:\n";
        for (size_t i = 0; i < diff.getRows(); ++i) {
            for (size_t j = 0; j < diff.getCols(); ++j) {
                cout << diff.at(i, j) << " ";
            }
            cout << "\n";
        }

        // Mnożenie macierzy
        Matrix product = m1 * m2;
        cout << "Mnożenie macierzy m1 i m2:\n";
        for (size_t i = 0; i < product.getRows(); ++i) {
            for (size_t j = 0; j < product.getCols(); ++j) {
                cout << product.at(i, j) << " ";
            }
            cout << "\n";
        }

        // Transpozycja macierzy
        Matrix transposed = m1.transpose();
        cout << "Transpozycja m1:\n";
        for (size_t i = 0; i < transposed.getRows(); ++i) {
            for (size_t j = 0; j < transposed.getCols(); ++j) {
                cout << transposed.at(i, j) << " ";
            }
            cout << "\n";
        }

        // Obliczanie wyznacznika
        double det = m1.determinant();
        cout << "Wyznacznik m1: " << det << "\n";

        // Obliczanie śladu
        double trace = m1.trace();
        cout << "Slad m1: " << trace << "\n";
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}