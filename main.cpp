#include <cstdlib>
#include "Matrix.hpp"

int main (int, char **)
{
    Matrix * m = new Matrix ();

    delete m;

    return EXIT_SUCCESS;
}
