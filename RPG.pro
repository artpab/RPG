TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -L/usr/lib -lncurses


SOURCES += main.cpp \
    source/Controllers/Builders/FieldBuilder.cpp \
    source/Controllers/GameController.cpp \
    source/Controllers/MapController.cpp \
    source/Fields/TerrainModels/ForestModel.cpp \
    source/Fields/TerrainModels/ITerrainModel.cpp \
    source/Fields/TerrainModels/PlainsModel.cpp \
    source/Fields/TerrainModels/WaterModel.cpp \
    source/Fields/Forest.cpp \
    source/Fields/IField.cpp \
    source/Fields/Plains.cpp \
    source/Fields/Water.cpp \
    source/MapIO/MapReader.cpp \
    source/MapIO/MapWriter.cpp \
    source/View/Display/Display.cpp \
    source/Monsters/Animals/IAnimal.cpp \
    source/Monsters/IBreed.cpp \
    source/Monsters/Monster.cpp \
    source/Monsters/Animals/Wolf.cpp \
    source/Monsters/MonsterGenerator.cpp \
    source/Monsters/Animals/Bear.cpp \
    source/Controllers/Builders/PerlinNoise.cpp

HEADERS += \
    source/Controllers/Builders/FieldBuilder.hpp \
    source/Controllers/GameController.hpp \
    source/Controllers/MapController.hpp \
    source/Fields/TerrainModels/ForestModel.hpp \
    source/Fields/TerrainModels/ITerrainModel.hpp \
    source/Fields/TerrainModels/PlainsModel.hpp \
    source/Fields/TerrainModels/WaterModel.hpp \
    source/Fields/Forest.hpp \
    source/Fields/IField.hpp \
    source/Fields/Plains.hpp \
    source/Fields/Water.hpp \
    source/MapIO/MapReader.hpp \
    source/MapIO/MapWriter.hpp \
    source/View/Display/Display.hpp \
    source/Monsters/Animals/IAnimal.hpp \
    source/Monsters/IBreed.hpp \
    source/Monsters/Monster.hpp \
    source/Monsters/Animals/Wolf.hpp \
    source/Monsters/MonsterGenerator.hpp \
    source/Monsters/Animals/Bear.hpp \
    source/Controllers/Builders/PerlinNoise.hpp
