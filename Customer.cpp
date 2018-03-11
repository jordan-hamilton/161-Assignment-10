/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/08/2018
 ** Description: Class implementation file template.
 *********************************************************************/

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

 void Customer::addProductToCart(std::string idCodeIn) {
   cart.push_back(idCodeIn);
 }

 bool Customer::isPremiumMember() {
   return premiumMember;
 }

 void Customer::emptyCart() {
   cart.clear();
 }
