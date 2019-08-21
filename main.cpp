#include <cstdlib>
#include <iostream>
#include "Matrix.hpp"

int main (int, char **)
{
    Matrix <int, 2, 2> * m = new Matrix <int, 2, 2> ();

    for (size_t i = 0; i < m->Rows (); ++i) {
        for (size_t j = 0; j < m->Cols (); ++j) {
            m->Set (i, j, i * m->Cols () + j);
        }
    }

    std::cout << * m;

    delete m;

    return EXIT_SUCCESS;
}
