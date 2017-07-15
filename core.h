#ifndef CORE_H
#define CORE_H
#include <string>
#include <vector>
#include <iostream>


class Core {
public:
    Core() : midterm(0), final(0) { std::cout << "Core() ctor\n"; }
    Core(std::istream&);
    virtual ~Core() { std::cout << "~Core() dtor\n"; }

    std::string name() const { return _name; }
    virtual std::istream& read(std::istream& is);
    virtual double grade() const;

protected:
  std::istream& read_common(std::istream& is);

  double midterm, final;
  std::vector<double> hw;

private:
    std::string _name;
};

bool compare(const Core&, const Core&);
bool compare_ptrs(const Core*, const Core*);

#endif // CORE_H
