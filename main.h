#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_map>
#include "customtypes.h" 
using namespace std;



vector<string> readInputs(string filename);
string rtrimString(string str);
string ltrimString(string str);
string trimString(string str);
void writeOutput(string output, double distance, int stops, int flights);
void loadData(vector<string> *cityCountries, vector<airport> *airportData);
void loadRoutes(unordered_map<string, vector<route>>& routes);
int perfomRouteSearch(string start, string end);
vector<route> outputData(node *dest);
double haversine(double lat1, double lon1, double lat2, double lon2);
double calculateDistance(string code1, string code2);
vector<double> getLongLat(string code, vector<airport>& airportCodes);

class cityNotFound : public std::exception {
    public:
        string what ();
};


#endif