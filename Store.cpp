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
  /* If the product isn't found in the inventory, return "product ID not found".
     If the member isn't found in the members, return "member ID not found".
     If both are found and the product is still available, call the member's
     addProductToCart method to add the product and then return "product added
     to cart". If the product was not still available, return "product out of
     stock". This function does not need to check how many of that product are
     available - just that there is at least one. It should also not change how
     many are available - that happens during checkout.  The same product can be
     added multiple times if the customer wants more than one of something. */

}

double Store::checkOutMember(std::string accountIDIn) {

}
