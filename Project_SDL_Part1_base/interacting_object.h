//
// Created by xplo on 06/11/2021.
//

#pragma once
#include "headers.h"

class interacting_object {
protected:
  std::set<std::string> properties_;

public:

  interacting_object(const std::set<std::string>& properties);
  ~interacting_object() = default;

  virtual void interact(std::shared_ptr<interacting_object> otherObject) = 0;
  void addProperty(std::string property);
  bool deleteProperty(std::string property);
  bool hasProperty(std::string property);
  [[nodiscard]] std::set<std::string> getProperties() const;
  std::set<std::string>& getProperties();
};