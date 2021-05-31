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
string
empty_line()
{
    double x1=0, y1=0, x2=100, y2=400, line=15, gap=20;
    int stroke_width= 2;
    string stroke = "black";
    svg_punktirn(x1, y1, x2, y2, stroke_width, stroke, line , gap);
    return "<line x1='"+to_string(x1)+"' y1='"to_string(y1)+"' x2='"+to_string(x2)+"' y2='"+to_string(y2)+"' stroke-width= '"+to_string(stroke_width)+"' stroke= '"+to_string(stroke)+"' stroke-dasharray= '"+to_string(line)+" "+to_string(gap)+"'/>";
}

int
main()
{
    /*test_positive();
    test_negative();
    test_one();
    test();*/
    return empty_line;

}


