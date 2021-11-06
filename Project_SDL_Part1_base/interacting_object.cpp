//
// Created by xplo on 06/11/2021.
//

#include "interacting_object.h"

interacting_object::interacting_object(const std::set<std::string>& properties) : properties_{properties} {};

void interacting_object::addProperty(std::string property) {
  properties_.insert(property);
}

bool interacting_object::deleteProperty(std::string property) {
  if (properties_.count(property)) {
    properties_.erase(property);
    return (true);
  }
  else
    return (false);
}
std::set<std::string> interacting_object::getProperties() const {
  return properties_;
}

std::set<std::string>& interacting_object::getProperties(){
  return properties_;
}