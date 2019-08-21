#ifndef MATRIX_HPP
#define MATRIX_HPP

template <size_t rows, size_t cols>
class Matrix
{
    public:
        Matrix ()
        {
            data = new double * [rows];
            for (size_t i = 0; i < rows; ++i) {
                data [i] = new double [cols];
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

        double Get (size_t r, size_t c) const {return data [r][c];}
        void Set (size_t r, size_t c, double v) {data [r][c] = v;}

    private:
        double ** data;
};



template <size_t rows, size_t cols>
std::ostream & operator << (std::ostream & os, const Matrix <rows, cols> & matrix)
{
    for (size_t i = 0; i < matrix.Rows (); ++i) {
        for (size_t j = 0; j < matrix.Cols (); ++j) {
            os << matrix.Get (i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

#endif//MATRIX_HPP
