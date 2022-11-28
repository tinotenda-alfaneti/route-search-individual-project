#include "main.h"

using namespace std;

/**
 * precondition: the pointer to the last node, or the goal node
 * postcondition: the result vector with the nodes or the path taken to reach goal state
*/
vector<route> outputData(node *dest) {
    vector<route> res;

   
    for (node *ptr = dest; ptr != nullptr; ptr = ptr->prev) {
        res.insert(res.begin(), ptr->curr);
    }
    double distance;
    string path;
    int stops = res[0].stops;
    int flights = res.size() - 1;
    string prev;
    for (int i = 1; i < res.size(); i++) {
        prev = res[i - 1].airportCode;
        distance += calculateDistance(prev, res[i].airportCode);
        
        stops += res[i].stops;
        path += res[i].airlineCode + " from " + res[i - 1].airportCode + " to " + res[i].airportCode + "\n";

    }
    writeOutput(path, distance, stops, flights);
    return res;
}