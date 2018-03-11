/*********************************************************************
 ** Author: Jordan Hamilton
 ** Date: 03/08/2018
 ** Description: Class implementation file template.
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

std::string getTitle() {
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

void Product::decreaseQuantity() {
  quantityAvailable--;
}
