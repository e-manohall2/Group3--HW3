#include "person.h"
#include <string>
#include "address.h"
#include "credit_card.h"
using std::string;

void Person::name(string name){
    name_=name;
}
string Person::name(){
    return name_;
}

void Person::person_address(address addr){
    person_address_=addr;
}
address Person::person_address(){
    return person_address_;
}

void Person::person_credit_card(credit_card card){
    person_credit_card_=card;
}
credit_card Person::person_credit_card(){
    return person_credit_card_;
}

void Person::phone(string p){
    phone_=p;
}
string Person::phone(){
    return phone_;
}

Person::Person(){
    name_="John Doe";
    person_address_ = address();
    person_address_.state = "Some State";
    person_address_.city = "Some City";
    person_address_.zip = "12345";
    person_address_.address_line1 = "0123 green st";
    person_address_.address_line2 = "";
    phone_="123-456-7890";
    person_credit_card_ = credit_card();
    person_credit_card_.cc_number =11111111;
    person_credit_card_.current_balance=0;
    person_credit_card_.limit=0;
}
Person::Person(string name, string phone, address addr, credit_card cc){
    name_=name;
    phone_=phone;
    person_address_=addr;
    person_credit_card_=cc;
}

string Person::person_info(){
    string ret = "Name: "+name_+"\nPhone: "+phone_+"\nAddress: "+person_address_.address_info()+"\nCredit Card:\n"+person_credit_card_.credit_card_info()+"\n";
    return ret;  
}