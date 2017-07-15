#include "utility.h"
#include <stdexcept>
#include <algorithm>


std::istream& read_hw(std::istream& is, std::vector<double>& hw) {
    if (is) {
        hw.clear();

        double x;
        while (is >> x)
            hw.push_back(x);

        is.clear();
    }
    return is;
}

double grade(double midterm, double final, double median_hw) {
    return 0.2 * midterm + 0.4 * final + 0.4 * median_hw;
}

double grade(double midterm, double final, std::vector<double> hw) {
    if (!hw.size())
        throw std::domain_error("No homework for grade.");

    std::vector<double>::size_type mid_n = hw.size()/2;
    std::nth_element(hw.begin(), hw.begin() + mid_n, hw.end());
    double median = hw[mid_n];
    if (hw.size() % 2 == 0) {
        std::nth_element(hw.begin(), hw.begin() + mid_n - 1, hw.end());
        median = (median + hw[mid_n - 1]) / 2;
    }
    return grade(midterm, final, median);
}
