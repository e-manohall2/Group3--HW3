#include "address.h"
#include <string>
using std::string;


string address::address_info(){
    string ret = "Address:\n"+address_line1+"\n"+address_line2+"\n"+city+"\n"+state+"\n"+zip+"\n";
    return ret;
}


//implementation code for address struct here


