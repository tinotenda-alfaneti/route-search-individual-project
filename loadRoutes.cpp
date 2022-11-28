#include "main.h"
using namespace std;

/**
 * precondition: routes,  a pointer to the routes map
 * postcondition: loading the routes map with the routes data from the routes.csv file
*/
void loadRoutes(unordered_map<string, vector<route>>& routes) {

    ifstream file;
    file.open("routes.csv");
    string line;
    vector<route> val;
    int count = 0;
    string tmp;
    
    //reading the file
    while(!file.eof()) {
        vector<string> tmpArr;
        getline(file, line);

        //string stream to be passed to the getline method for further splitting
        stringstream s(line);

        if (count == 0) {
            count++;
            continue;
        }

        //splitting the line into a vector
        while(getline(s, tmp, ',')) {
            tmpArr.push_back(tmp);
        }

        //adding routes to unordered map
        route routeTmp;
        if (routes.find(tmpArr[2]) == routes.end()) {
            routeTmp.airportCode = tmpArr[4];
            routeTmp.airlineCode = tmpArr[0];
            routeTmp.stops = stoi(tmpArr[7]);
            val.push_back(routeTmp);
            routes[tmpArr[2]] =  val;
        } else {
            auto it = routes.find(tmpArr[2]);
            val = it->second;
            routeTmp.airportCode = tmpArr[4];
            routeTmp.airlineCode = tmpArr[0];
            routeTmp.stops = stoi(tmpArr[7]);
            val.push_back(routeTmp);
            routes[tmpArr[2]] = val;
        }

    }
}