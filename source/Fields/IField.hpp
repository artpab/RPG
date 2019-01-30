
#ifndef IFIELD_HPP
#define IFIELD_HPP

#include "../Monsters/Monster.hpp"
#include "TerrainModels/ITerrainModel.hpp"
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

// Preferably polimorphism mechanism will be used.

class IField {
protected:
  std::shared_ptr<ITerrainModel> _model_ptr;
  bool containsMonster = false;
  std::shared_ptr<Monster> monster_ptr;

public:
  IField();
  //    IField(std::shared_ptr<ITerrainModel>);
  IField(const IField &orig) = delete;
  virtual ~IField();
  virtual int getX() = 0;
  virtual int getY() = 0;
  virtual std::string printField() = 0;
  virtual std::string getType() = 0;
  virtual std::shared_ptr<ITerrainModel> getModelPtr() = 0;
  void assignMonster(std::shared_ptr<Monster> m_ptr);
  bool monsterAvailable();
  std::shared_ptr<Monster> getMonsterPtr() { return monster_ptr; };

  //    virtual void provideData() = 0;

private:
};

#endif /* IFIELD_HPP */
