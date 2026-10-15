#include "transaction.h"
#include <string>
using std::string;
using std::to_string;

string transaction::transaction_info(){
    string ret="Transaction #"+to_string(transaction_number)+":\n";
    ret+="Customer:\n"+customer.person_info()+"\n";
    ret+="Product:\n"+purchased_item.product_info()+"\n";
    ret+="Quantity: "+to_string(quantity)+"\n";
    return ret;
}
//code for transaction struct here
