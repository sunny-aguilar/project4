# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	February 19 2019
# Description:	Makefile for Project 4 Fantasy Combat

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += game.o
OBJECTS += character.o
OBJECTS += dice.o
OBJECTS += vampire.o
OBJECTS += barbarian.o
OBJECTS += bluemen.o
OBJECTS += medusa.o
OBJECTS += harrypotter.o
OBJECTS += menu.o
OBJECTS += heroList.o

HPPs += game.hpp
HPPs += character.hpp
HPPs += dice.hpp
HPPs += vampire.hpp
HPPs += barbarian.hpp
HPPs += bluemen.hpp
HPPs += medusa.hpp
HPPs += harrypotter.hpp
HPPs += menu.hpp
HPPs += heroList.hpp


CPPs = main.cpp
CPPs += game.cpp
CPPs += character.cpp
CPPs += dice.cpp
CPPs += vampire.cpp
CPPs += barbarian.cpp
CPPs += bluemen.cpp
CPPs += medusa.cpp
CPPs += harrypotter.cpp
CPPs += menu.cpp
CPPs += heroList.cpp


# Targets needed to bring the executable up to date
Fight: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Fight $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

game.o: game.hpp

character.o: character.hpp

dice.o: dice.hpp

vampire.o: vampire.hpp

barbarian.o: barbarian.hpp

bluemen.o: bluemen.hpp

medusa.o: medusa.hpp

harrypotter.o: harrypotter.hpp

menu.o: menu.hpp

heroList.o: heroList.hpp


# Clean-up operations
clean:
	rm Fight *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Fight

zip:
	zip -D Project4_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf