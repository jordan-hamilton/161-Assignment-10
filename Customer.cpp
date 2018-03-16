/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/15/2018
 ** Description: This implements a class representing a customer. Data
 ** members represent the customer's shopping cart, name, account ID,
 ** and whether or not he or she is a premium member of a store.
 ** Methods add products to the customer's cart by product code, and
 ** remove all items from the cart.
 *********************************************************************/

 #include "Customer.hpp"

 Customer::Customer(std::string nameIn, std::string accountIDIn, bool premiumMemberIn) {
   name = nameIn;
   accountID = accountIDIn;
   premiumMember = premiumMemberIn;
 }

 std::string Customer::getAccountID() {
   return accountID;
 }

 std::vector<std::string> Customer::getCart() {
   return cart;
 }

/*********************************************************************
** Description: Adds a string representing a product code to the end
** of the cart vector.
*********************************************************************/
 void Customer::addProductToCart(std::string idCodeIn) {
   cart.push_back(idCodeIn);
 }

 bool Customer::isPremiumMember() {
   return premiumMember;
 }

/*********************************************************************
** Description: Empties the cart vector using the vector's built-in
** clear function.
*********************************************************************/
 void Customer::emptyCart() {
   cart.clear();
 }
