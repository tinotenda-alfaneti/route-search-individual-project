// C++ program for the haversine formula
// C++ program for the
// haversine formula
#include "main.h"
using namespace std;

/**
 * precondition: code and the airportCodes
 * postcondition: a vector with the longitude and latitude
*/
vector<double> getLongLat(string code, vector<airport>& airportCodes) {
    vector<double> res;
    for(airport apt : airportCodes) {
        if(apt.code.compare(code) == 0) {
            res.push_back(apt.lat);
            res.push_back(apt.lon);
        } 
    }
    return res;
}

/**
 * precondition: airport codes for the two different airports to be calculated distance for
 * postcondition: the distance between the two airports
*/
double calculateDistance(string code1, string code2) {
    vector<string> cityCountries;
    vector<airport> airportCodes;
    loadData(&cityCountries, &airportCodes);
    vector<double> airport1 = getLongLat(code1, airportCodes);
    vector<double> airport2 = getLongLat(code2, airportCodes);
    return haversine(airport1[0], airport1[1], airport2[0], airport2[1]);
}
double haversine(double lat1, double lon1, double lat2, double lon2) {
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}