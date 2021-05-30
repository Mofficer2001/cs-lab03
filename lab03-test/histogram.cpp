#include "histogram.h"
#include <vector>

void find_minmax(const vector <double>&  numbers, double& max, double& min)
{
   // double min,max;
    max=numbers[0];
    min=numbers[0];
    for (double x: numbers)
    {
        if (x>max)
            max=x;
        else if (x<min)
            min=x;
    }
}
