/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/08/2018
 ** Description: Class implementation file template.
 *********************************************************************/

#include <iostream>
#include <algorithm>
#include <cctype>

#include "Store.hpp"

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

std::vector<std::string> Store::productSearch(std::string search) {
  std::string tempString = search;
  std::vector<std::string> productCodes;

  if (std::islower(search.at(0))) {
    tempString.at(0) = std::toupper(tempString.at(0));
  } else {
    tempString.at(0) = std::tolower(tempString.at(0));
  }

  for (Product* product : inventory) {
    if (product) {
      if (product->getTitle().find(search) != std::string::npos || product->getTitle().find(tempString) != std::string::npos) {
        std::cout << "Found " << search << " by title: ID Code " << product->getIdCode() << std::endl;
        productCodes.push_back(product->getIdCode());
      } else if (product->getDescription().find(search) != std::string::npos || product->getDescription().find(tempString) != std::string::npos) {
        productCodes.push_back(product->getIdCode());
        std::cout << "Found this product by description: ID Code " << product->getIdCode() << std::endl;
      } else {
        std::cout << "Couldn't find a product matching the word " << search << " in this iteration." << std::endl;
      }
    }
  }

  std::sort(productCodes.begin(), productCodes.end());
  for (int count = 0; count < productCodes.size(); count++) {
    std::cout << "productCodes: " << productCodes.at(count);
  }
  return productCodes;
}

std::string Store::addProductToMemberCart(std::string pID, std::string mID) {

}

double Store::checkOutMember(std::string mID) {

}
