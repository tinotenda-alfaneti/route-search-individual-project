#include "main.h"

int main() {
    vector<string> cityCountries;
    vector<airport> airportCodes;
    loadData(&cityCountries, &airportCodes);
    
    // get inputs from inputs file
    vector<string> sourceDest = readInputs("inputs.csv");
    string start;
    string destination;
    for (int i = 0; i < cityCountries.size(); i++) {
        if (sourceDest[0].compare(cityCountries[i]) == 0) {
            start = airportCodes[i].code;
        }
        if (sourceDest[1].compare(cityCountries[i]) == 0) {
            destination = airportCodes[i].code;
        }

    }

    if (start.empty() || destination.empty()) {
        throw cityNotFound();
    }
    
    perfomRouteSearch(start, destination);
    
}