#include "Bear.hpp"

Bear::Bear() { this->maxHealth = 200; }

std::shared_ptr<Monster> Bear::create() {
  //  auto ptr = shared_from_this();
  return std::make_shared<Monster>(shared_from_this());
}
