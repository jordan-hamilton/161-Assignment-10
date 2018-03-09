Asssignment 10

You will be writing a (rather primitive) online store simulator. It will have three classes: Product, Customer and Store. To make things a little simpler for you, I am supplying you with the three .hpp files. You will write the three implementation files. You should not alter the provided .hpp files.

Here are descriptions of methods for the three classes:

Product:

*A Product object represents a product with an ID code, title, description, price and quantity available.*

* constructor - takes as parameters five values with which to initialize the Product's idCode, title, description, price, and quantity available
* get methods - return the value of the corresponding data member
* decreaseQuantity - decreases the quantity available by one


Customer:

*A Customer object represents a customer with a name and account ID. Customers must be members of the Store to make a purchase. Premium members get free shipping.*

* constructor - takes as parameters three values with which to initialize the Customer's name, account ID, and whether the customer is a premium member
* get methods - return the value of the corresponding data member
* isPremiumMember - returns whether the customer is a premium member
* addProductToCart - adds the product ID code to the Customer's cart
* emptyCart - empties the Customer's cart


Store:

*A Store object represents a store, which has some number of products in its inventory and some number of customers as members.*

* addProduct - adds a product to the inventory
* addMember - adds a customer to the members
* getProductFromID - returns pointer to product with matching ID. Returns NULL if no matching ID is found.
* getMemberFromID - returns pointer to customer with matching ID. Returns NULL if no matching ID is found.
productSearch - return a **sorted** vector of ID codes for every product whose title or description contains the search string. The first letter of the search string should be case-insensitive, i.e. a search for "wood" should match Products that have "Wood" in their title or description, and a search for "Wood" should match Products that have "wood" in their title or description. You may use [string::find() and string::npos](http://www.cplusplus.com/reference/string/string/find/?kw=string%3A%3Afind) You may assume that the search string will consist of a single word.
* addProductToMemberCart - If the product isn't found in the inventory, return "product ID not found". If the member isn't found in the members, return "member ID not found". If both are found and the product is still available, call the member's addProductToCart method to add the product and then return "product added to cart". If the product was not still available, return "product out of stock". **This function does not need to check how many of that product are available - just that there is at least one. It should also not change how many are available - that happens during checkout.** The same product can be added multiple times if the customer wants more than one of something.
* checkOutMember - If the member ID isn't found, return -1. Otherwise return the charge for the member's cart. This will be the total cost of all the items in the cart, **not including any items that are not in the inventory or are out of stock**, plus the shipping cost. If a product is not out of stock, you should add its cost to the total and decrease the available quantity of that product by 1. Note that it is possible for an item to go out of stock during checkout. For example, if the customer has two of the same product in their cart, but the store only has one of that product left, the customer will be able to buy the one that's available, but won't be able to buy a second one, because it's now out of stock. For premium members, the shipping cost is $0. For normal members, the shipping cost is 7% of the total cost of the items in the cart. When the charge for the member's cart has been tabulated, the member's cart should be emptied, and the charge amount returned.


You must submit these files: **Product.cpp**, **Customer.cpp**, and **Store.cpp**. You do not need to submit the .hpp files.

In the main method you use for testing, you should only need to #include Store.hpp. Remember that your compile command needs to list all of the .cpp files.
