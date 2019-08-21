#include <cstdlib>
#include <iostream>
#include "Matrix.hpp"

int main (int, char **)
{
    Matrix * m = new Matrix (2, 2);

    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            m->Set (i, j, i * 2 + j);
        }
    }

    std::cout << * m;

    delete m;

    return EXIT_SUCCESS;
}
