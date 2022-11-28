#ifndef _CUSTOMTYPES_H_
#define _CUSTOMTYPES_H_

#include <string>
using namespace std;

struct airport {
    double lat;
    double lon;
    string code;
};


class route{
    public:
        string airportCode;
        string airlineCode;
        int stops;
        bool operator==(const route& name) const {
            return this->airportCode.compare(name.airportCode) == 0;
        }
};

class node {
    public:
        route curr;
        node *prev;
        double distance = 0.0;
        int stops;
        bool operator==(const node& name) const {
            return this->curr == name.curr;
        }
        node(route rt, node* nd) {
            this->curr = rt;
            this->prev = nd;
        }
        node(route rt) {
            this->curr = rt;
            this->prev = nullptr;
        }
};


#endif