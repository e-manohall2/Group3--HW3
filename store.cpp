//code for store class here
#include "store.h"
#include "transaction.h"
#include "person.h"
#include <string>
using std::string;
Store::Store(){
    num_customers_=0;
    num_products_=0;
    num_transactions_=0;
}
//Hopefully this overloads the equals operator 
// bool operator==(Person other){

// }

void Store::num_customers(int customer_count){
    num_customers_=customer_count;
}
int Store::num_customers(){
    return num_customers_;
}

void Store::num_products(int product_count){
    num_products_=product_count;
}
int Store::num_products(){
    return num_products_;
}

void Store::num_transactions(int transaction_count){
    num_transactions_=transaction_count;
}
int Store::num_transactions(){
    return num_transactions_;
}

bool Store::add_customer(Person customer){
    if(num_customers_>=100){
        return false;
    }
    customers_[num_customers_++]=customer; //hopefully works, if not will just move the increase ouside of the brackets
    return true;
}

bool Store::update_customer(int index, Person customer){
    if(customers_[index].name()==customer.name()){
        customers_[index]=customer;
        return true;
    }
    return false;
}

Person Store::get_customer(int index){
    return customers_[index];
}

bool Store::add_product(product item){
    if(num_products_==100){
        return false;
    }
    products_[num_products_++]=item;
    return true;
}

product Store::get_product(int index){
    return products_[index];
}

bool Store::add_transaction(transaction ntransaction){
    if(num_transactions_==100){
        return false;
    }
    transactions_[num_transactions_++]=ntransaction;
    return true;
}

transaction Store::get_transaction(int index){
    return transactions_[index];
}

bool Store::make_purchase(Person p, product item, int number){
    credit_card card = p.person_credit_card();
    if(card.make_purchase(item.price*number)){
        p.person_credit_card(card);  
        transaction t;
        t.customer = p;
        t.purchased_item = item;
        t.quantity = number;
        t.transaction_number=num_transactions_+1;
        transactions_[num_transactions_++]=t;
        customers_[find_customer(p)]=p;
        return true;
    }
    return false;
}

	
string Store::product_info(){
    string ret = "Products:\n";
    for(int i=0;i<num_products_;i++){
        ret+=products_[i].product_info()+"\n";
    }
    return ret;
}


string Store::transaction_info(){
    string ret = "All Transactions:\n";
    for(int i=0;i<num_transactions_;i++){
        ret+=transactions_[i].transaction_info()+"\n";
    }
    return ret;
}

string Store::customer_info(){
    string ret = "Customers:\n";
    for(int i=0;i<num_customers_;i++){
        ret+=customers_[i].person_info()+"\n";
    }
    return ret;
}


string Store::store_info(){
    return "Store Info:\n\n"+customer_info()+"\n\n"+product_info()+"\n\n"+transaction_info();
}


string Store::purchase_history(Person p){
    string ret = p.name()+" Transaction History:\n";
    for(int i=0;i<num_transactions_;i++){
        if(p.person_info()==transactions_[i].customer.person_info()){
            ret+=transactions_[i].transaction_info()+"\n";
        }
    }
    return ret;
}


int Store::find_customer(Person cust){
    for(int i=0;i<num_customers_;i++){
        if(customers_[i].name()==cust.name()){
            return i;
        }
    }
    return -1;
}
 

