#pragma once /*#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED*/
#include <vector>
#include <string>

using namespace std;
struct Input {
    vector<double> numbers;
    size_t number_count;
    size_t bin_count;
    vector<string> bin_title;

};
void find_minmax(const vector<double>& numbers, double& max, double& min);
vector<double> input_numbers(istream& in, size_t count);
vector<string> input_title(istream& in, size_t bin_count);
Input
read_input(istream& in, bool prompt);
//const vector <double>&  numbers,
vector <size_t> make_histogram(Input a);
//const vector<double>& numbers,
void show_histogram_text(Input input, const vector<size_t>& bins);
//const vector<double>& numbers,
void svg_begin(double width, double height);
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "blue", string fill = "green");
void svg_punktirn(double x1, double y1, double x2, double y2, int stroke_width=2, string stroke="gold", double line=15 , double gap=10);
void svg_end();
void show_histogram_svg(const vector<size_t>& bins, int stroke_width);

//#endif // HISTOGRAM_H_INCLUDED
