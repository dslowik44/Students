#include "core.h"
#include "utility.h"

Core::Core(std::istream& is) {
    std::cout << "Core(istream &) ctor\n";
    read(is);
}

std::istream& Core::read(std::istream& is) {
    read_common(is);
    read_hw(is, hw);
    return is;
}

std::istream& Core::read_common(std::istream& is) {
    is >> _name >> midterm >> final;
    return is;
}

double Core::grade() const {
    return ::grade(midterm, final, hw);
}


bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}

bool compare_ptrs(const Core* cp1, const Core* cp2) {
    return cp1->name() < cp2->name();
}
