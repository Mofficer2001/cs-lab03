#include "histogram.h"
#include <cassert>
//#define NDEBUG

void
test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3.5, 4, 8, -5}, min, max);
    assert(max == 8);
    assert(min == 3.5);

}

int
main()
{
    test_positive();
}
