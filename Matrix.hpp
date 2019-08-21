#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix
{
    public:
        Matrix (size_t rows, size_t cols)
            : rows {rows}
            , cols {cols}
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

    private:
        const size_t rows;
        const size_t cols;

        double ** data;
};

#endif//MATRIX_HPP
