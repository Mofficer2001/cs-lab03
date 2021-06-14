#include <iostream>
#include <vector>
#include <string.h>
#include "histogram.h"
#include <curl/curl.h>
#include <sstream>
#include <string>

// ...������� �������...



using namespace std;

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    // TODO: ���������� ������ � ������.
    size_t data_size=item_size*item_count;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(reinterpret_cast<const char*>(items), data_size);
    return data_size;
}

Input
download(const string& address)
{
    stringstream buffer;


    CURL *curl = curl_easy_init();
    if(curl)
    {
        curl_off_t ul;

        CURLcode res, result;
        result = curl_easy_getinfo(curl, CURLINFO_SIZE_UPLOAD_T, &ul);
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        result = curl_easy_getinfo(curl, CURLINFO_SIZE_UPLOAD_T, &ul);
        res = curl_easy_perform(curl);
        if(!result)
        {
            cerr<<"Uploaded %"<<CURL_FORMAT_CURL_OFF_T<<" bytes\n"<< ul;
        }
        if (res!=0)
        {
            cerr<<res<<" "<<curl_easy_strerror(res)<<endl;
            exit(1);
        }
        curl_easy_cleanup(curl);
    }

    return read_input(buffer, false);
}

//void svg end

int main(int argc, char* argv[])
{
    Input input;
    if (argc>1)
    {
        input=download(argv[1]);
    }
    else
    {
        input=read_input(cin, true);
    }
    const auto bins=make_histogram(input);

    int stroke_width=3;
    cerr<<stroke_width;
    show_histogram_svg(bins, stroke_width);
    return 0;
}

/*if (argc>1)
{
    CURL *curl = curl_easy_init();
    if(curl)
    {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res!=0)
        {
            cerr<<res<<" "<<curl_easy_strerror(res)<<endl;
            exit(1);
        }
    }
    return 0;

}*/
//bin_size = (max - min) / bin_count;
//int stroke_width=3;
//show_histogram_text(numbers,bins,title,bin_count,title_max,Max_Asterisk,Max_bin_index);


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

//////////////////
/*vector<double> input_numbers(istream& in, size_t count)
{
    vector <double> numbers(count);
    for (size_t i = 0; i <count; i++)
    {
        cin >> numbers[i];
    }
    return numbers;
}



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
