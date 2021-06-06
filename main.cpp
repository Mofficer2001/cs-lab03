#include <iostream>
#include <vector>
#include <string.h>
#include "histogram.h"

using namespace std;
/*struct Input {
    vector<double> numbers;
    vector<string> bin_name;
    size_t bin_count;
};*/
/*vector<double> input_numbers(size_t count)
{
    vector <double> numbers(count);
    for (size_t i = 0; i <count; i++)
    {
        cin >> numbers[i];
    }
    return numbers;
}*/

/*void find_minmax(const vector <double>&  numbers, double& max, double& min)
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


}*/

/*vector <size_t> make_histogram(const vector<double>& numbers, size_t number_count, size_t bin_count)
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
}*/

/*size_t max_bin_index(const vector<size_t>& bins,  size_t bin_count)
{
    size_t max_index=bins[0];
    for(size_t i=0; i<bin_count; i++)
    {
        if (bins[i] > max_index)
        {
            max_index=bins[i];
        }
    }
    return max_index;
}*/

/*void show_histogram_text(const vector<double>& numbers, const vector<size_t>& bins, const vector<string>& title, double bin_count, double title_max, size_t Max_Asterisk, size_t Max_bin_index)
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
}*/
/*void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}*/

/*void
svg_text(double left, double baseline, string text) {
    cout << "<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";
}*/

/*void svg_rect(double x, double y, double width, double height, string stroke = "blue", string fill = "green")
{
    cout<<"<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}*/


/*void svg_punktirn(double x1, double y1, double x2, double y2, int stroke_width=2, string stroke="gold", double line=15 , double gap=10)
{
    cout<<"<line x1='"<<x1<<"' y1='"<<y1<<"' x2='"<<x2<<"' y2='"<<y2<<"' stroke-width= '"<<stroke_width<<"' stroke= '"<<stroke<<"' stroke-dasharray= '"<<line<<" "<<gap<<"'/>";
    //<line x1="60" y1="120" x2="180" y2="120" style="stroke-dasharray: 10 10; stroke: yellow; stroke-width: 4px;" />
    //stroke='"<<stroke<<"' stroke-disharray='"<<line<<" "<<gap<<"' />";

   //<line x1='0' y1='0' x2='100' y2='100' stroke='blue' stroke-width='4'/>
}*/


/*void svg_end() {
    cout << "</svg>\n";
}*/

/*void show_histogram_svg(const vector<size_t>& bins, int stroke_width)
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
        svg_punktirn(START_LINE, top+BIN_HEIGHT+(int)(stroke_width/2), IMAGE_WIDTH, top+BIN_HEIGHT, stroke_width);
        top =top+BIN_HEIGHT+stroke_width;
    }
    svg_end();
}*/
//void svg end



vector<double>
input_numbers(istream& in, size_t count)
{
    vector <double> numbers(count);
    for (size_t i = 0; i <count; i++)
    {
        cin >> numbers[i];
    }
    return numbers;
}

vector<string>
input_title(istream& in, size_t bin_count)
{
    vector <string> title;
    string str;
    for(size_t i=0; i<bin_count; i++)
    {
        cin >> str;
        title.push_back(str);
    }
    return title;
}

Input read_input(istream& in) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    in >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr<<"Bin count :";
    size_t bin_count;
    in >> bin_count;
    data.bin_count=bin_count;

    cerr<<"Titles : \n";
    data.bin_name = input_title(in, bin_count);

    return data;
}

int main()
{
    size_t   bin_index,Max_bin_index, heigh, title_max, title_len;
    double bin_size, max, min;
    Input data;
    //string str;
    const size_t Screen_Width=80;

    cerr<<data.bin_name[1].length();
   /* cerr <<"Number count :";
    cin >> number_count;*/
   // vector<string> title;
    //const vector<size_t> bins(bin_count);
    read_input(cin);
    /*cerr<<"Input numbers "<<"\n";
    const auto numbers=input_numbers(number_count);
    cerr<<"Bin count :";
    cin >> bin_count;

   / cerr<<"Titles : \n";
    */

    /*find_minmax(data.numbers,max, min);
    cerr<<"max="<<max;
    cerr<<"min="<<min;*/
    //bin_size = (max - min) / bin_count;
    const auto bins=make_histogram(data.numbers,number_count, bin_count);

    Max_bin_index=bins[0];
    for(size_t i=0; i<bin_count; i++)
    {
        if (bins[i] > Max_bin_index)
            Max_bin_index=bins[i];
    }

    //Max_bin_index=max_bin_index(bins,bin_count);
    //title_max=title[0].length();
    for(size_t i=0; i<bin_count; i++)
    {
        if (data.bin_name[i].length()> title_max)
            title_max = data.bin_name[i].length();
    }


    int stroke_width=3;
    const size_t Max_Asterisk=Screen_Width -4-1;
    //show_histogram_text(numbers,bins,title,bin_count,title_max,Max_Asterisk,Max_bin_index);
    cerr<<stroke_width;
    show_histogram_svg(bins, stroke_width);
    return 1;
}

//cin >> bin_count;
    /*//////
        for (size_t i = 0; i < number_count; i++)
        {
            cin >> numbers[i];
        }*/

   // title.push_back(str);
    //}
    /*/////
    max = numbers[0], min = numbers[0];
    for (double x : numbers)
    {
        if (x > max)
            max = x;
        else if (x < min)
            min = x;
    }*/

//const auto bins=make_histogram(numbers, number_count, bin_count, max, min);
    /*/////
    for (size_t i = 0; i < number_count; i++)
    {
        bool f = false;
        for (size_t j = 0; (j < bin_count - 1) && !f; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1)*bin_size;
            if ((lo <= numbers[i]) && (hi > numbers[i]))
            {
                bins[j]++;
                f = true;
            }
        }
        if (!f)
            bins[bin_count - 1]++;
    }*/

//const auto bins=make_histogram(numbers, number_count, bin_count, max, min);
/*Max_bin_index=bins[0];
    /*for(size_t i=0; i<bin_count; i++)
    {
        if (bins[i] > Max_bin_index)
        {
            Max_bin_index=bins[i];
        }
    }*/


