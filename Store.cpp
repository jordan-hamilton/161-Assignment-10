/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/15/2018
 ** Description: This implements a class representing a store. Data
 ** members include vectors that represent the product inventory and
 ** customers who are store members. Methods add pointers to products
 ** and customer objects to the vectors, search for products and
 ** members by ID, search for products by title or description
 **
 *********************************************************************/

#include <algorithm>
#include <cctype>

#include "Store.hpp"

void Store::addProduct(Product* ptrProduct) {
  if (ptrProduct) {
      inventory.push_back(ptrProduct);
  }
}

void Store::addMember(Customer* ptrCustomer) {
  if (ptrCustomer) {
    members.push_back(ptrCustomer);
  }
}

Product* Store::getProductFromID(std::string idCodeSearch) {

  for (Product* product : inventory) {

    if (product) {

      if (idCodeSearch == product->getIdCode()) {
        return product;
      }

    }
  }

  // Return NULL if no product ID matched during the for loop.
  return NULL;
}

Customer* Store::getMemberFromID(std::string accountIDSearch) {

  for (Customer* customer : members) {

    if (customer) {
      if (accountIDSearch == customer->getAccountID()) {
        return customer;
      }
    }
  }

  // Return NULL if no account ID matched during the for loop.
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

  // Loop through all products in the inventory vector to find a match.
  for (Product* product : inventory) {
    if (product) {

      // Access the product's getTitle method if the pointer was
      // valid, then search the returned string for the string passed
      // and our temporary string. Add the product's ID to the end
      // of our method's vector if the search if found.
      if (product->getTitle().find(search) != std::string::npos || product->getTitle().find(tempString) != std::string::npos) {
        productCodes.push_back(product->getIdCode());
      } else if (product->getDescription().find(search) != std::string::npos || product->getDescription().find(tempString) != std::string::npos) {

        // Repeat the process from the title search for the product's
        // description if we couldn't find our search parameter in
        // the product's title.
        productCodes.push_back(product->getIdCode());
      }
    }
  }

  // Sort the vector of matching products, then return the vector.
  std::sort(productCodes.begin(), productCodes.end());

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

  // Define and initialize an accumulator for the total cost of the
  // cart and a counter of items we'll need to process while looping
  // through the cart vector.
  double total = 0.0;
  int items = 0;

  // Define pointer varaibles for the customer and the products
  // in this customer's cart.
  Customer* payingCustomer;
  Product* productInCart;

  // Return a flag value if we couldn't find the account in our
  // members vector.
  if ( !getMemberFromID(accountIDIn) ) {
    return -1;
  } else {

    // Assign the customer to our pointer variable if we found the ID
    // in the members vector.
    payingCustomer = getMemberFromID(accountIDIn);

    // Loop through the cart vector to process all product ID codes.
    while ( items < payingCustomer->getCart().size() ) {

      if ( getProductFromID( payingCustomer->getCart().at(items) ) ) {

        // If the product is found in inventory, assign it to our pointer variable.
        productInCart = getProductFromID( payingCustomer->getCart().at(items) );

        if ( productInCart->getQuantityAvailable() > 0 ) {

          // If the product is still in stock, add its price to the total
          // and decrease the quantity in the inventory.
          total += productInCart->getPrice();
          productInCart->decreaseQuantity();
        }
      }

      items++;
    }
  }

  // Empty the customer's cart now that we've processed all items.
  payingCustomer->emptyCart();

  // Return the total after looping through the cart vector, but add
  // the shipping cost if the customer wasn't a premium member.
  if (payingCustomer->isPremiumMember()) {
    return total;
  } else {
    return total * 1.07;
  }
}
