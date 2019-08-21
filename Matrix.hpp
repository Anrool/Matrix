#ifndef MATRIX_HPP
#define MATRIX_HPP

template <typename T, size_t rows, size_t cols>
class Matrix
{
    public:
        Matrix ()
        {
            data = new T [rows * cols];
        }

        ~Matrix ()
        {
            delete [] data;
        }

        size_t Rows () const {return rows;}
        size_t Cols () const {return cols;}

        T & operator () (size_t r, size_t c) {return data [r * cols + c];}
        const T & operator () (size_t r, size_t c) const {return data [r * cols + c];}

        template <typename M = Matrix <T, rows, cols> >
        struct iterator : std::iterator <std::input_iterator_tag, T>
        {
            iterator (M & m, size_t row, size_t col)
                : m {m}
                , row {row}
                , col {col}
            {
            }
            ~iterator () = default;

            bool operator == (const iterator & that) {return this->row == that.row && this->col == that.col;}
            bool operator != (const iterator & that) {return ! operator == (that);}
            T & operator * () const {return m (row, col);}
            iterator & operator ++ ()
            {
                row += ++col / cols;
                col  =   col % cols;
                return * this;
            }

            M & m;
            size_t row;
            size_t col;
        };

        iterator <> begin () {return iterator <> {* this, 0, 0};}
        iterator <> end   () {return iterator <> {* this, rows, 0};}

    private:
        T * data;
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
