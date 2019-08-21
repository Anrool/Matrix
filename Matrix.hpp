#ifndef MATRIX_HPP
#define MATRIX_HPP

template <typename T, size_t rows, size_t cols>
class Matrix
{
    public:
        Matrix ()
        {
            data = new T * [rows];
            for (size_t i = 0; i < rows; ++i) {
                data [i] = new T [cols];
            }
        }

        ~Matrix ()
        {
            for (size_t i = 0; i < rows; ++i) {
                delete [] data [i];
            }
            delete [] data;
        }

        size_t Rows () const {return rows;}
        size_t Cols () const {return cols;}

        T & operator () (size_t r, size_t c) {return data [r][c];}
        const T & operator () (size_t r, size_t c) const {return data [r][c];}

    private:
        T ** data;
};



template <typename T, size_t rows, size_t cols>
std::ostream & operator << (std::ostream & os, const Matrix <T, rows, cols> & matrix)
{
    for (size_t i = 0; i < matrix.Rows (); ++i) {
        for (size_t j = 0; j < matrix.Cols (); ++j) {
            os << matrix (i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

#endif//MATRIX_HPP
