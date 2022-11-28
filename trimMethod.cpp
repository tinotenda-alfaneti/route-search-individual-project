#include "main.h"
using namespace std;

//values considered whitespaces
string WHITESPACE = " \n\t\f\v\r";

//trim the left side of the string
string ltrimString(string str) {
    size_t trimStr = str.find_first_not_of(WHITESPACE);
    return (trimStr == string::npos ? "" : str.substr(trimStr));
}

//trim the right side of the string
string rtrimString(string str) {
    size_t trimStr = str.find_last_not_of(WHITESPACE);
    return (trimStr == string::npos ? "" : str.substr(0, trimStr + 1));

}

//trim both sides of the string
string trimString(string str) {
    return ltrimString(rtrimString(str));
}