#include "../histogram.h"
#include <iostream>
#include <cassert>
#include <vector>

//#define NDEBUG
using namespace std;

void
test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 4, 8}, max, min);
    //cout << min;
    assert(max == 8);
    assert(min == 1);

}

void
test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, max, min);
    //cout << min;
    assert(max == -1);
    assert(min == -3);
}

void
test_one()
{
    double min = 0;
    double max = 0;
    find_minmax({1}, max, min);
    //cout << min;
    assert(max == 1);
    assert(min == 1);
}
void test()
{
    vector<double> a;


    double min = 0;
    double max = 0;
    find_minmax(a, max, min);
    cout << min;
    assert(max == 1);
    assert(min == 1);
}

int
main()
{
    test_positive();
    test_negative();
    test_one();
    test();
}


