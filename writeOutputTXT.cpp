#include "main.h"

using namespace std;

/**
 * precondition: output should not be null, the distance should be greater than zero
 * postcondition: the distance, the string of paths, and the stops are written to an output file
*/
void writeOutput(string output, double distance, int stops, int flights) {
    ofstream file;
    file.open("outputFile.txt");
    file << output << endl;
    file << "Total flights: ";
    file << flights << endl;
    file << "Total additional stops: ";
    file << stops << endl;
    file << "Distance: ";
    file << distance;
    file << "KM" << endl;
    file << "Optimality Criteria: Flights";

    
    cout << "Goal found and captured successful" << endl;
    cout << "Read outputFile.txt for a detailed output" << endl;
}
