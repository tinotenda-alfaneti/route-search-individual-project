#include "main.h"
using namespace std;

/**
 * precondition: pointers to the cityCountries vector and and airportCodes vector
 * postcondition: loading the two vectors with the required data
*/
void loadData(vector<string> *cityCountries, vector<airport> *airportCodes)
{
    
    string tmp;
    string line;
    ifstream file;
    int count = 0;

    file.open("airports.csv");
    double x, y;
    
    // reading the airports file
    while (!file.eof()) {
        vector<string> tmpArr;
        getline(file, line);
        stringstream s(line);
        if (count == 0) {
            count++;
            continue;
        }
        while(getline(s, tmp, ',')) {

            tmpArr.push_back(tmp);

        }
        if (tmpArr[4].compare("\\N") != 0) 
        {
            airport tmpAirport;
            tmp = tmpArr[2] + "," + tmpArr[3];
            cityCountries->push_back(tmp);

            //converting from string to double
            stringstream st(tmpArr[6]);
            st >> x;
            tmpAirport.lat = x;
            stringstream sy(tmpArr[7]);
            sy >> y;
            tmpAirport.lon = y;

            //adding the airport code
            tmpAirport.code = tmpArr[4];
            airportCodes->push_back(tmpAirport);
            
        }
    }
    file.close();

    
}
