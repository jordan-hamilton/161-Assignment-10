/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/08/2018
 ** Description: Class implementation file template.
 *********************************************************************/

#include "Store.hpp"
#include <iostream>

void Store::addProduct(Product* ptrProduct) {
  if (ptrProduct) {
      inventory.push_back(ptrProduct);
      std::cout << "Product added." << std::endl;
  }
}

void Store::addMember(Customer* ptrCustomer) {
  if (ptrCustomer) {
    members.push_back(ptrCustomer);
    std::cout << "Member added." << std::endl;
  }
}

Product* Store::getProductFromID(std::string idCodeSearch) {
/* returns pointer to product with matching ID.  Returns NULL if no matching ID is found. */
  for (Product* product : inventory) {
    if (product) {
      std::cout << "Product ID found: " << product->getIdCode() << std::endl;
      if (idCodeSearch == product->getIdCode()) {
        std::cout << "Product ID " << idCodeSearch << " found in the store at the following memory location: " << std::endl;
        return product;
    }

    }
  }
  std::cout << "Couldn't detect product ID " << idCodeSearch << std::endl;
  return NULL;

}

Customer* Store::getMemberFromID(std::string accountIDSearch) {
/* returns pointer to customer with matching ID.  Returns NULL if no matching ID is found. */
  for (Customer* customer : members) {
    if (customer) {
      std::cout << "Account ID found: " << customer->getAccountID() << std::endl;
      if (accountIDSearch == customer->getAccountID()) {
        std::cout << "Account ID " << accountIDSearch << " found in the store at the following memory location: " << std::endl;
        return customer;
      }
    }
  }
  std::cout << "Couldn't detect account ID " << accountIDSearch << std::endl;
  return NULL;
}

std::vector<std::string> Store::productSearch(std::string str) {
  
}

std::string Store::addProductToMemberCart(std::string pID, std::string mID) {

}

double Store::checkOutMember(std::string mID) {

}
