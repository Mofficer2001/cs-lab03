#pragma once /*#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED*/
#include <vector>
#include <string>

using namespace std;
void find_minmax(const vector <double>&  numbers, double& max, double& min);
vector <size_t> make_histogram(const vector<double>& numbers, size_t number_count, size_t bin_count);
void show_histogram_text(const vector<double>& numbers, const vector<size_t>& bins, const vector<string>& title, double bin_count, double title_max, size_t Max_Asterisk, size_t Max_bin_index);
void svg_begin(double width, double height);
void
svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "blue", string fill = "green");
string svg_punktirn(double x1, double y1, double x2, double y2, ostream& out, int stroke_width=2, string stroke="gold", double line=15 , double gap=10);
void svg_end();
void show_histogram_svg(const vector<size_t>& bins, int stroke_width);

//#endif // HISTOGRAM_H_INCLUDED
