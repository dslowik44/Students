#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "core.h"
#include "grad.h"

using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;
using std::max; using std::sort;

int main() {
    vector<Core*> students;
    Core* record;
    char ch;
    string::size_type maxlen{0};
    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;
        record->read(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_ptrs);

    using stdnt_itr = vector<Core*>::const_iterator;
    stdnt_itr itr_end = students.end();
    cout << " Name    " << "  Grade\n";
    for (stdnt_itr itr = students.begin(); itr != itr_end; ++itr) {
        double grade = (*itr)->grade();
        cout << (*itr)->name() << string(maxlen + 1 - (*itr)->name().size(), ' ')
             << grade << endl;
        delete *itr;
    }

    return 0;
}

