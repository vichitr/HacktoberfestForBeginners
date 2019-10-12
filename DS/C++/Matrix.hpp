#include <vector>
#include <stdexcept>

template<typename T>
class Matrix {
    std::vector<std::vector<T>> matrix;
    std::size_t _rows;
    std::size_t _columns;
  public:
    Matrix(std::size_t row_count, std::size_t column_count) :
        matrix(row_count),
        _rows(row_count),
        _columns(column_count) {
        matrix.resize(row_count, std::vector<T>(column_count, 0));
        for (auto& row : matrix) {
            row.resize(_columns);
        }
    }

    Matrix(std::size_t row_count, std::size_t column_count, const T& value) :
        matrix(row_count),
        _rows(row_count),
        _columns(column_count) {
        for (auto& row : matrix) {
            row.resize(_columns, value);
        }
    }
    Matrix(std::vector<vector<T>>& x) :
        _rows(x.size()),
        _columns(x[0].size()) {
        matrix = x;
    }

    Matrix(const Matrix& other) = default;

    Matrix& operator=(const Matrix& other) = default;

    // Scalar Multiplication
    Matrix& operator*=(const T& scalar) {
        for (auto& row : matrix) {
            for (auto& cell : row) {
                cell *= scalar;
            }
        }
        return *this;
    }

    // Scalar Division
    Matrix& operator/=(const T& scalar) {
        for (auto& row : matrix) {
            for (auto& cell : row) {
                cell /= scalar;
            }
        }
        return *this;
    }

    // Modular Operator
    Matrix& operator%=(const T& mod) {
        for (std::size_t i = 0; i < _rows; i++) {
            for (std::size_t j = 0; j < _columns; j++) {
                matrix[i][j] %= mod;
            }
        }
        return *this;
    }

    // Matrix Multiplication
    Matrix& operator*=(const Matrix& other) {
        if (_columns != other._rows) {
            throw std::logic_error("column count of lhs and row count of rhs are not equal\n");
        }
        Matrix temp(_rows, other._columns, 0);

        for (std::size_t i = 0; i < temp._rows; i++) {
            for (std::size_t j = 0; j < temp._columns; j++) {
                for (std::size_t k = 0; k < _columns; k++) {
                    temp[i][j] += matrix[i][k] * other[k][j];
                }
            }
        }
        std::swap(matrix, temp.matrix);
        std::swap(_columns, temp._columns);
        return *this;
    }

    // addition Operator
    Matrix& operator+=(const Matrix& other) {
        if (_rows != other._rows || _columns != other._columns) {
            throw std::logic_error("either or both of row count and column count of lhs and rhs are not equal\n");
        }
        for (std::size_t i = 0; i < _rows; i++) {
            for (std::size_t j = 0; j < _columns; j++) {
                matrix[i][j] += other[i][j];
            }
        }
        return *this;
    }

    // Subtraction Operator
    Matrix& operator-=(const Matrix& other) {
        if (_rows != other._rows || _columns != other._columns) {
            throw std::logic_error("either or both of row count and column count of lhs and rhs are not equal\n");
        }
        for (std::size_t i = 0; i < _rows; i++) {
            for (std::size_t j = 0; j < _columns; j++) {
                matrix[i][j] -= other[i][j];
            }
        }
        return *this;
    }

    // Number of Rows
    std::size_t rows() const {
        return _rows;
    }

    // Number of Columns
    std::size_t columns() const {
        return _columns;
    }

    std::vector<T>& operator[](std::size_t row) {
        return matrix[row];
    }

    const std::vector<T>& operator[](std::size_t row) const {
        return matrix[row];
    }
};

//Matrix Transpose
template<typename T>
auto operator!(const Matrix<T>& other) {
    Matrix<T> res(other.columns(), other.rows());
    for (auto row = 0; row < other.rows(); ++row) {
        for (auto col = 0; col < other.columns(); ++col) {
            res[col][row] = other[row][col];
        }
    }
    return res;
}

//Equals Operator
template<typename T>
bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    if (lhs.rows() != rhs.rows() || lhs.columns() != rhs.columns()) {
        return false;
    }
    for (auto i = 0; i < lhs.rows(); i++) {
        for (auto j = 0; j < lhs.columns(); j++) {
            if (lhs[i][j] != rhs[i][j]) {
                return false;
            }
        }
    }
    return true;
}

//Not-Equals Operator
template<typename T>
bool operator!=(const Matrix<T>& lhs, const Matrix<T>& rhs) {
    return !(lhs == rhs);
}

//Add matrices
template<typename T>
Matrix<T> operator+(Matrix<T>& lhs, const Matrix<T>& rhs) {
    return lhs += rhs;
}

//Subtract matrices
template<typename T>
Matrix<T> operator-(Matrix<T>& lhs, const Matrix<T>& rhs) {
    return lhs -= rhs;
}

// Multiply Matrices
template<typename T>
Matrix<T> operator*(Matrix<T>& lhs, const Matrix<T>& rhs) {
    return lhs *= rhs;
}

//Scalar multiplication
template<typename T, typename U>
Matrix<T> operator*(Matrix<T>& lhs, const U& rhs) {
    return lhs *= rhs;
}

//Scalar Division
template<typename T, typename U>
Matrix<T> operator/(Matrix<T>& lhs, const U& rhs) {
    return lhs /= rhs;
}

//Scalar modulo
template<typename T, typename U>
Matrix<T> operator%(Matrix<T>& lhs, const U& mod) {
    return lhs %= mod;
}

template<typename T, typename U>
Matrix<T> operator*(const U& scalar, Matrix<T> lhs) {
    return lhs *= scalar;
}

template<typename T>
Matrix<T> operator*(const T& lhs, Matrix<T> rhs) {
    return rhs *= lhs;
}

// Power of a Matrix
template<typename T, typename U>
Matrix<T> power(Matrix<T>& base, U exp) {
    Matrix<T> res = base;
    while (exp > 0) {
        if (exp & 1) {
            res *= base;
        }
        exp >>= 1;
        base *= base;
    }
    return res;
}

template<typename T, typename U>
Matrix<T> power(Matrix<T>& base, U exp, T mod) {
    Matrix<T> res = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            res *= base;
            res %= mod;
        }
        exp >>= 1;
        base *= base;
        base %= mod;
    }
    return res;
}

// Trace of Matrix
template<typename T>
T trace(Matrix<T>& matrix) {
    if (matrix.rows() != matrix.columns()) {
        throw std::logic_error("Not a square matrix\n");
    }
    T res = 0;
    for (std::size_t i = 0; i < matrix.rows(); ++i) {
        res += matrix[i][i];
    }
    return res;
}

template<typename T>
std::istream& operator>>(std::istream& is, Matrix<T>& matrix) {
    for (std::size_t i = 0; i < matrix.rows(); i++) {
        for (std::size_t j = 0; j < matrix.columns(); j++) {
            is >> matrix[i][j];
        }
    }
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (std::size_t i = 0; i < matrix.rows(); i++) {
        for (std::size_t j = 0; j < matrix.columns(); j++) {
            os << matrix[i][j] << ' ';
        }
        os << "\n";
    }
    return os;
}
