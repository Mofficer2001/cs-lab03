#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
vector<double> input_numbers(size_t count)
{
    vector <double> numbers(count);
    for (size_t i = 0; i <count; i++)
    {
        cin >> numbers[i];
    }
    return numbers;
}

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

vector <size_t> make_histogram(const vector<double>& numbers, size_t number_count, size_t bin_count, double max, double min)
{
    //const vector<size_t>& bins,
    vector<size_t> bins(bin_count);
    double bin_size=(max-min)/bin_count;
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
    }
    return bins;
}

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
    cout << "<text x='20' y='35'>anything you want</text>";
}

void
svg_end() {
    cout << "</svg>\n";
}

void show_histogram_svg(const vector<size_t>& bins)
{
    svg_begin(400, 300);
    svg_text(20, 20, to_string(bins[0]));
    svg_end();
}
//void svg end

int main()
{
    size_t number_count, bin_count, bin_index,Max_bin_index, heigh, title_max, title_len;
    double bin_size, max, min;
    string str;

    cout <<"Number count :";
    cin >> number_count;
    const size_t Screen_Width=80;

    vector<string> title;
    //const vector<size_t> bins(bin_count);
    cout<<"Input numbers "<<"\n";
    const auto numbers=input_numbers(number_count);
    cout<<"Bin count :";
    cin >> bin_count;

    cout<<"Titles : \n";
    for(size_t i=0; i<bin_count; i++)
    {
        cin >>str;
        title.push_back(str);
    }

    find_minmax(numbers, max, min);
    //bin_size = (max - min) / bin_count;
    const auto bins=make_histogram(numbers, number_count, bin_count, max, min);

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
        if (title[i].length()> title_max)
            title_max = title[i].length();
    }

    const size_t Max_Asterisk=Screen_Width -4-1;
    //show_histogram_text(numbers,bins,title,bin_count,title_max,Max_Asterisk,Max_bin_index);
    show_histogram_svg(bins);
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


