#include "grad.h"
#include "utility.h"
#include <algorithm>

Grad::Grad(std::istream& is) {
    std::cout << "Grad(istream &) ctor\n";
    read(is);
}

std::istream& Grad::read(std::istream& is) {
    read_common(is);
    is >> thesis;
    read_hw(is, hw);
    return is;
}

double Grad::grade() const {
    return std::min(Core::grade(), thesis);
}
