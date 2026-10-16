#include "credit_card.h"
#include <string>
using std::string;
using std::to_string;


string credit_card::credit_card_info(){
    string ret = "Card Number: "+ to_string(cc_number)+ "\nCard Balance: "+to_string(current_balance) +"\nCard Limit: "+to_string(limit)+"\n";
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
