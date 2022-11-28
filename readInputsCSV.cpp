#include "main.h"
using namespace std;

/**
 * precondition: the filename
 * postcondition: vector of the splitted line
*/
vector<string> readInputs(string filename) {

    ifstream datafile;
    datafile.open(filename);
    vector<string> tmp;
    vector<string> cityCountry;
    string buff1;
    string buff2;

    //read inputs
    while (!datafile.eof()) {
        getline(datafile, buff1);

        stringstream s(buff1);

        while(getline(s, buff2, ',')) {
             
            tmp.push_back(trimString(buff2));
        }
    }
    string tmpstr = tmp[0] + "," + tmp[1];
    cityCountry.push_back(tmpstr);
    tmpstr = tmp[2] + "," + tmp[3];
    cityCountry.push_back(tmpstr);
    
    return cityCountry;
}