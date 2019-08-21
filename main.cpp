#include <cstdlib>
#include "Matrix.hpp"

int main (int, char **)
{
    Matrix * m = new Matrix (2, 2);

    delete m;

    return EXIT_SUCCESS;
}
