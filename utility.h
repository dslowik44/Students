#ifndef UTILITY_H
#define UTILITY_H
// Global functions used by methods of Core and Grad classes.
#include <istream>
#include <vector>

std::istream& read_hw(std::istream& is, std::vector<double>& hw);
double grade(double midterm, double final, std::vector<double> hw);

#endif // UTILITY_H
