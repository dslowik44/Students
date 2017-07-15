#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "core.h"

class Grad: public Core {
public:
    Grad() : thesis(0) { std::cout << "Grad() ctor\n"; }
    Grad(std::istream&);
    ~Grad() { std::cout << "~Grad() dtor\n"; }

    std::istream& read(std::istream& is);
    double grade() const;

private:
    double thesis;
};

#endif // STUDENT_H
