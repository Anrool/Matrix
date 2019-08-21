#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "Matrix.hpp"

int main (int, char **)
{
    Matrix <int, 2, 2> * m = new Matrix <int, 2, 2> ();

    for (size_t i = 0; i < m->Rows (); ++i) {
        for (size_t j = 0; j < m->Cols (); ++j) {
            (* m) (i, j) = i * m->Cols () + j;
        }
    }

    std::cout << * m;

    std::replace_if (m->begin (), m->end (), [](const int & v){return v & 1;}, 42);

    std::cout << * m;

    std::transform (m->begin (), m->end (), m->begin (), std::negate<int> () );

    std::cout << * m;

    delete m;

    return EXIT_SUCCESS;
}
