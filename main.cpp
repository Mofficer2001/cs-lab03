#include <iostream>
#include <vector>
#include <string.h>
#include "histogram.h"

using namespace std;
int main()
{
    const char* name = "Commander Shepard";
    int year = 2154;
    printf("%s was born in %d.\n", name, year);
    return 0;

    Input input=read_input(cin, true);
    const auto bins=make_histogram(input);
    int stroke_width=3;
    //show_histogram_text(numbers,bins,title,bin_count,title_max,Max_Asterisk,Max_bin_index);
    cerr<<stroke_width;
    show_histogram_svg(bins, stroke_width);
    return 0;
}

