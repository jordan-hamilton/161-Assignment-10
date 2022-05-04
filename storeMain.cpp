#include <iostream>

using std::cout;
using std::endl;

#include "Store.hpp"

int main() {
  Customer newGuy("Bro", "8675308", false);
  Customer newGirl("Jenny", "8675309", true);
  Product spardex("1001", "Spardex", "Stretches for dayyyyys", 10.02, 5);
  Product jammies("1002", "Jammies", "Oh so cozy", 3.01, 5);

  Store amazon;

  amazon.addMember(&newGuy);
  Customer* ptrNewGirl = &newGirl;
  amazon.addMember(ptrNewGirl);

  amazon.addProduct(&spardex);
  Product* ptrJammies = &jammies;
  amazon.addProduct(ptrJammies);

  cout << endl << "Searching for a \"Cozy\" product: " << endl;
  amazon.productSearch("Cozy");

  cout << endl << "Adding products to member cart: " << endl;
  cout << amazon.addProductToMemberCart("1001", "8675308") << endl;
  cout << amazon.addProductToMemberCart("1001", "8675308") << endl;
  cout << amazon.addProductToMemberCart("1002", "8675308") << endl;
  cout << amazon.addProductToMemberCart("1002", "8675308") << endl;
  cout << amazon.addProductToMemberCart("1002", "8675308") << endl;



  cout << endl << "Check-out time! " << amazon.checkOutMember("8675308");

  cout << endl << "Reading cart contents: " << endl;
  for (std::string item : newGirl.getCart()) {
    std::cout << "Cart item " << item << std::endl;
  }


  cout << endl << "Store tests: " << endl << endl <<
  amazon.getProductFromID("1002") << endl << endl <<
  amazon.getMemberFromID("8675309");

  cout << endl << "Customer rundown: " << endl <<
  "Account ID: " << newGuy.getAccountID() << endl <<
  "Premium membership status: " << newGuy.isPremiumMember() << endl;

  cout << endl << "Product rundown: " << endl <<
  "ID Code: " << jammies.getIdCode() << endl <<
  "Title: " << jammies.getTitle() << endl <<
  "Price: $"  << jammies.getPrice() << endl <<
  "Description: " << jammies.getDescription() << endl <<
  "Quantity in stock: " << jammies.getQuantityAvailable() << endl;

  cout << endl << "Decrementing quantity in stock..." << endl;
  jammies.decreaseQuantity();
  cout << "Current quantity in stock: " << jammies.getQuantityAvailable() << endl;

  cout << endl << "Adding product to cart for newGuy..." << endl;
  newGuy.addProductToCart(jammies.getIdCode());
  cout << "Cart contents: Product ID " << newGuy.getCart().at(0) << endl;

  cout << endl << "Emptying cart..." << endl << endl;
  newGuy.emptyCart();

  return 0;
}
