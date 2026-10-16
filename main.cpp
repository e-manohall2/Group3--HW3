#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <limits>
#include <ctime>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

int main()
{

	cout.setf(std::ios::fixed);
	cout.setf(std::ios::showpoint);
	cout.precision(2);

	// create the store array

	Store store1;

	product products[100];

	int productCount = 0;

	//open product file
	ifstream productFile("products.txt");

	if (!productFile.is_open()){
		cout << "Could not open products.txt" << endl;
		return 1;
	}

	// Read the first line: the number of products.
	if (!(productFile >> productCount) || productCount < 1 || productCount > 100) {
    	cout << "Error: invalid product count." << endl;
   	    return 1;
	}

	productFile.ignore(
		std::numeric_limits<std::streamsize>::max(), '\n'
	);

	// loop to fill in products array
	for (int i = 0; i < productCount; i++){
		if (!getline(productFile, products[i].name) || 
		!getline(productFile, products[i].description) || 
		!(productFile >> products[i].price)) {
			cout << "Error, could not read product" << i + 1 << endl;
			return 1;
		}

		productFile.ignore(
        	std::numeric_limits<std::streamsize>::max(), '\n'
  	    );

	}

	productFile.close();

// create customer array
	Person customers[100];
	int customerCount = 0;

	ifstream peopleFile("people.txt");

	if (!peopleFile.is_open()){
		cout << "Could not open people.txt" << endl;
		return 1;
	}

	// get number of customers
	if (!(peopleFile >> customerCount) ||
    	customerCount < 1 || customerCount > 100) {
    	cout << "Error: invalid customer count." << endl;
    return 1;
}

	peopleFile.ignore(
 		std::numeric_limits<std::streamsize>::max(), '\n'
	);

	for(int i = 0; i < customerCount; i++){
		std::string name;
		std::string phone;
		address customerAddress;
		
		if (!getline(peopleFile, name) ||
			!getline(peopleFile, phone) ||
			!getline(peopleFile, customerAddress.address_line1) ||
			!getline(peopleFile, customerAddress.address_line2) ||
			!getline(peopleFile, customerAddress.city) ||
			!getline(peopleFile, customerAddress.state) ||
			!getline(peopleFile, customerAddress.zip)) {
				cout << "Error, could not read customer" << i + 1 << endl;
				return 1;
			}
		
		customers[i].name(name);
		customers[i].phone(phone);
		customers[i].person_address(customerAddress);
	}

	peopleFile.close();


	// credit card section, need to pull credit card info and match it to customer by name
	ifstream cardFile("credit_card.txt");

	if (!cardFile.is_open()){
		cout << "Error, could not open credit_card.txt" << endl;
		return 1;
	}

	int cardCount = 0;

	if (!(cardFile >> cardCount) ||
		cardCount < 1 || cardCount > 100){
		cout << "Error, invalid credit card count" << endl;
		return 1;
		}

	cardFile.ignore(
    	std::numeric_limits<std::streamsize>::max(), '\n'
	);

	for (int i = 0; i < cardCount; i++){
		std::string customerName;
		credit_card card;

		if (!getline(cardFile, customerName) ||
			!(cardFile >> card.cc_number
			           >> card.limit
					   >> card.current_balance)){
			cout << "Error, could not read credit card" << i + 1 << endl;
			return 1;
		}

    	cardFile.ignore(
        	std::numeric_limits<std::streamsize>::max(), '\n'
    	);

		// need to find customer with this name and save the card with them
		bool found = false;

		for (int j = 0; j < customerCount; j++){
			if (customers[j].name() == customerName){
				customers[j].person_credit_card(card); 
				found = true;
				break;
			}
		}

		if (!found){
			cout << "Error, could not match card to customer " << customerName << endl;
			return 1;
		}
	}

	cardFile.close();

	// add products to store
	for (int i = 0; i < productCount; i++){
		if (!store1.add_product(products[i])){
			cout << "Error, could not add product " << products[i].name << endl;
			return 1;
		}
	}


	for (int i = 0; i < customerCount; i++){
		if (!store1.add_customer(customers[i])){
			cout << "Error, could not add customer " << customers[i].name() << endl;
			return 1;
		}
	}

	cout << store1.store_info() << endl;

	// now that the initial store and customer info has 
	// been printed, need to run and print a random number of purchases

	// seed random number generator
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// randomly choose between 11 and 99 purchase attempts
	// int attemptCount = std::rand() % 89 + 11;
	int attemptCount = 5;
	cout << "\nSimulating " << attemptCount << " Transactions:\n\n" << endl;

	for (int i = 0; i < attemptCount; i++){
		// randomly pick customer, product, and quantity
		int customerIndex = std::rand() % customerCount;
    	int productIndex = std::rand() % productCount;
 		int quantity = std::rand() % 10 + 1;

		// note! this assumes card info is being updated in store, not here
		Person customer = store1.get_customer(customerIndex);
		product item = store1.get_product(productIndex);

		bool success = store1.make_purchase(customer, item, quantity);

		if (success){
			cout << "Successful Transaction!" << endl;

			// need to print transaction just added to store
			int lastIndex = store1.num_transactions() - 1;
			cout << store1.get_transaction(lastIndex).transaction_info();
		}
		else {
			cout << "Unsuccessful transaction!" << endl;
			cout << "Transaction details:" << endl;
        	cout << "Person:\n" << customer.person_info() << endl;
        	cout << "Product:\n" << item.product_info() << endl;
        	cout << "Purchase quantity: " << quantity << endl;
		}

		cout << endl;
	}

	// print out the updated customer info, store info, and transaction history
	cout << "\nFinal store information:\n";
	cout << store1.store_info() << endl;


}
