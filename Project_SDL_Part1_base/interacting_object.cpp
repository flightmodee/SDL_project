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
bool interacting_object::hasProperty(std::string property) {
  if (properties_.count(property))
    return (true);
  else
    return (false);
}

interacting_object* interacting_object::whoIsFemale(const std::shared_ptr<interacting_object>& otherObject) {
  if (otherObject->hasProperty("female"))
    return (otherObject.get());

  else if (hasProperty("female"))
    return (this);
  else
    throw std::runtime_error("This shouldn't have happened at all.\n");
}

bool interacting_object::canMakeBabies(const std::shared_ptr<interacting_object> &otherObject) {
  if (this->hasProperty("female") && otherObject->hasProperty("male") || this->hasProperty("female") && otherObject->hasProperty("male"))
    if (!this->hasProperty("lamb") &&  otherObject->hasProperty("lamb"))
      return (true);

  return (false);
}