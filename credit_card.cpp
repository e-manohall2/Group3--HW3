#include "credit_card.h"
#include <string>
using std::string;
using std::to_string;
#include <sstream>
#include <iomanip>


string credit_card::credit_card_info(){
    
    std::ostringstream balance_stream, limit_stream;

    balance_stream << std::fixed << std::setprecision(2) << current_balance;
    limit_stream << std::fixed << std::setprecision(2) << limit;

    string ret = "Card Number: " + to_string(cc_number) +
                 "\nCard Balance: " + balance_stream.str() +
                 "\nCard Limit: " + limit_stream.str() + "\n";

    return ret;
}

bool credit_card::make_purchase(double purchase_amount){
    if(purchase_amount+current_balance<limit){
        current_balance+=purchase_amount;
        return true;
    }
    return false;
}
bool credit_card::make_payment(double payment_amount){
    if(payment_amount>current_balance){
        return false;
    }
    current_balance-=payment_amount;
    return true;

}

//implementation code for credit_card struct here
