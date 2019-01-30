#include "Wolf.hpp"

Wolf::Wolf() { this->maxHealth = 80; }

std::shared_ptr<Monster> Wolf::create() {
  auto ptr = shared_from_this();
  //  return nul5lptr;
  return std::make_shared<Monster>(ptr);
}
