/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/15/2018
 ** Description: This implements a class representing a product. Data
 ** members represent the product's code, title, description, price,
 ** and quantity in stock. A method decreases the quantity in stock
 ** by 1.
 *********************************************************************/

#include "Product.hpp"

Product::Product(std::string idCodeIn, std::string titleIn, std::string descriptionIn, double priceIn, int quantityIn) {
  idCode = idCodeIn;
  title = titleIn;
  description = descriptionIn;
  price = priceIn;
  quantityAvailable = quantityIn;
}

std::string Product::getIdCode() {
  return idCode;
}

std::string Product::getTitle() {
  return title;
}

std::string Product::getDescription() {
  return description;
}

double Product::getPrice() {
  return price;
}

int Product::getQuantityAvailable() {
  return quantityAvailable;
}

/*********************************************************************
** Description: Decreases the value of the quantityAvailable data
** member by 1 when called.
*********************************************************************/
void Product::decreaseQuantity() {
  quantityAvailable--;
}
