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

    // Loop through the
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

  // Define a vector of strings we'll use to store then return products
  // that match our search.
  std::vector<std::string> productCodes;

  // Create a temporary string with the opposite case on the first
  // character of the string that was passed so we can search
  // with both an uppercase and lowercase first character.
  std::string tempString = search;

  if (std::islower(search.at(0))) {
    tempString.at(0) = std::toupper(tempString.at(0));
  } else {
    tempString.at(0) = std::tolower(tempString.at(0));
  }

  for (Product* product : inventory) {
    if (product) {

      // Access the product's getTitle method if the pointer was
      // valid, then search the return value for the string passed
      // and our temporary string. Add the product's ID to the end
      // of our method's vector if the search if found.
      if (product->getTitle().find(search) != std::string::npos || product->getTitle().find(tempString) != std::string::npos) {
        std::cout << "Found " << search << " by title: ID Code " << product->getIdCode() << std::endl;
        productCodes.push_back(product->getIdCode());
      } else if (product->getDescription().find(search) != std::string::npos || product->getDescription().find(tempString) != std::string::npos) {

        // Repeat the process from the title search for the product's
        // description if we couldn't find our search parameter in
        // the product's title.
        productCodes.push_back(product->getIdCode());
        std::cout << "Found this product by description: ID Code " << product->getIdCode() << std::endl;
      } else {
        std::cout << "Couldn't find a product matching the word " << search << " in this iteration." << std::endl;
      }
    }
  }

  std::sort(productCodes.begin(), productCodes.end());
  for (int count = 0; count < productCodes.size(); count++) {
    std::cout << "productCodes: " << productCodes.at(count) << std::endl;
  }
  return productCodes;
}

std::string Store::addProductToMemberCart(std::string idCodeIn, std::string accountIDIn) {
     if (!getProductFromID(idCodeIn)) {
       return "product ID not found";
     } else if (!getMemberFromID(accountIDIn)) {
       return "member ID not found";
     } else if (getProductFromID(idCodeIn)->getQuantityAvailable() < 1) {
       return "product out of stock";
     } else {
       getMemberFromID(accountIDIn)->addProductToCart(idCodeIn);
       return "product added to cart";
     }
}

double Store::checkOutMember(std::string accountIDIn) {
  //If the member ID isn't found, return -1.  Otherwise return the
  //charge for the member's cart.  This will be the total cost of
  //all the items in the cart, not including any items that are not
  //in the inventory or are out of stock, plus the shipping cost.
  //If a product is not out of stock, you should add its cost to the
  //total and decrease the available quantity of that product by 1.
  //Note that it is possible for an item to go out of stock during
  //checkout.  For example, if the customer has two of the same
  //product in their cart, but the store only has one of that product
  //left, the customer will be able to buy the one that's available,
  //but won't be able to buy a second one, because it's now out of stock.
  //For premium members, the shipping cost is $0.  For normal members,
  //the shipping cost is 7% of the total cost of the items in the cart.
  //When the charge for the member's cart has been tabulated, the member's
  //cart should be emptied, and the charge amount returned.
}
