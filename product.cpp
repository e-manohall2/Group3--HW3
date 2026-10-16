#include "product.h"
#include <string>
using std::string;
using std::to_string;
#include <sstream>
#include <iomanip>


string product::product_info(){
    std::ostringstream price_stream;

    price_stream << std::fixed << std::setprecision(2) << price;

    string ret = "Name: "+name+"\nDescription: "+description+"\nPrice: "+price_stream.str()+"\n";
    return ret;
}
//code for product struct here

