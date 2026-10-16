#include "product.h"
#include <string>
using std::string;
using std::to_string;


string product::product_info(){
    string ret = "Name: "+name+"\nDescription: "+description+"\nPrice: "+to_string(price)+"\n";
    return ret;
}
//code for product struct here

