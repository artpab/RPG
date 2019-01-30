/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Field.cpp
 * Author: goti
 *
 * Created on January 6, 2019, 12:12 PM
 */

#include "IField.hpp"
#include "iostream"
#include "stdio.h"

IField::IField() {}

// IField::IField(std::shared_ptr<ITerrainModel> ptr):_model_ptr(ptr){

//};

IField::~IField() {}

void IField::assignMonster(std::shared_ptr<Monster> m_ptr) {
  monster_ptr = m_ptr;
  containsMonster = true;
}

bool IField::monsterAvailable() { return containsMonster; }
