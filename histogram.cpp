#include "histogram.h"
#include <iostream>

void find_minmax(const vector <double>&  numbers, double& max, double& min)
{
   // double min,max;
    if(numbers.size()!=0)
    {
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
    else if(numbers.size()==0)
    {
        max=0;
        min=0;
    }


}
vector <size_t> make_histogram(const vector<double>& numbers, size_t number_count, size_t bin_count)
{
    //const vector<size_t>& bins,
    vector<size_t> bins(bin_count);
    double max=0;
    double min=0;
    find_minmax(numbers,max,min);
    double bin_size=(max-min)/bin_count;
    for (size_t i = 0; i < number_count; i++)
    {
        bool f = false;
        for (size_t j = 0; (j < bin_count - 1) && !f; j++)
        {
            auto lo = min + (j * bin_size);
            auto hi = min + (j + 1)*bin_size;
            if ((lo <= numbers[i]) && (hi > numbers[i]))
            {
                bins[j]++;
                f = true;
            }
        }
        if (!f)
            bins[bin_count - 1]++;
    }
    return bins;
}

void show_histogram_text(const vector<double>& numbers, const vector<size_t>& bins, const vector<string>& title, double bin_count, double title_max, size_t Max_Asterisk, size_t Max_bin_index)
{
    size_t heigh, title_len;
    //size_t Max_bin_index= max_bin_index(bins,bin_count);
    //const size_t Screen_Width=80;
    //const size_t Max_Asterisk=Screen_Width -4-1;
    for (size_t i = 0; i < bin_count; i++)
    {
        if (Max_bin_index>Max_Asterisk)
            heigh=Max_Asterisk*(static_cast<double>(bins[i])/Max_bin_index);
        else
            heigh=bins[i];

        title_len=title[i].length();
        //size_t d=title_max-title_len;
        for(size_t k=0; k<title_max-title_len; k++)
        {
            cout<<" ";
        }
        cout<<title[i]<<"|";
        for (size_t j = 0; j < heigh; j++)
        {
            cout << "*";
        }
        cout<<"\n";
    }
}
void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_text(double left, double baseline, string text) {
    cout << "<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke , string fill)
{
    cout<<"<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}

string svg_punktirn(double x1, double y1, double x2, double y2, ostream& out, int stroke_width, string stroke, double line , double gap)
{
    out << "<line x1='"<<x1<<"' y1='"<<y1<<"' x2='"<<x2<<"' y2='"<<y2<<"' stroke-width= '"<<stroke_width<<"' stroke= '"<<stroke<<"' stroke-dasharray= '"<<line<<" "<<gap<<"'/>";
    //<line x1="60" y1="120" x2="180" y2="120" style="stroke-dasharray: 10 10; stroke: yellow; stroke-width: 4px;" />
    //stroke='"<<stroke<<"' stroke-disharray='"<<line<<" "<<gap<<"' />";
    //return "<xxx aaa='" + to_string(x1) + "'>";
   //<line x1='0' y1='0' x2='100' y2='100' stroke='blue' stroke-width='4'/>
}

void svg_end() {
    cout << "</svg>\n";
}
void show_histogram_svg(const vector<size_t>& bins, int stroke_width)
{
    double top=0;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto START_LINE = 0;
    const auto LINE = 0;
    const auto GAP = 0;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    for (size_t bin:bins)
    {
        const double bin_width = BLOCK_WIDTH * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
        svg_punktirn(START_LINE, top+BIN_HEIGHT+(int)(stroke_width/2)+1, IMAGE_WIDTH, top+BIN_HEIGHT+(int)(stroke_width/2)+1, cout, stroke_width);
        top =top+BIN_HEIGHT+stroke_width;
    }
    svg_end();
}

