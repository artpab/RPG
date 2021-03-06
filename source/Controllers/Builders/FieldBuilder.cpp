#include "FieldBuilder.hpp"

FieldBuilder::FieldBuilder() {
    create_models();
}


FieldBuilder::~FieldBuilder() {
}

void FieldBuilder::create_models() {

    _models.emplace("Plains", std::make_shared<PlainsModel>());
    _models.emplace("Water", std::make_shared<WaterModel>());
    _models.emplace("Forest", std::make_shared<ForestModel>());
}

std::shared_ptr<Plains> FieldBuilder::createPlains(int x, int y) {
    return std::make_shared<Plains>(x, y, _models["Plains"]);
}

std::shared_ptr<Water> FieldBuilder::createWater(int x, int y) {
    return std::make_shared<Water>(x, y, _models["Water"]);
}

std::shared_ptr<Forest> FieldBuilder::createForest(int x, int y) {
    return std::make_shared<Forest>(x, y, _models["Forest"]);
}
