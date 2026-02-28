CXX         = g++
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp
CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic
SOURCES     = $(wildcard *.cpp)
OBJECTS     = $(SOURCES:%.cpp=%.o)

main: main.o sudoku.o
	$(CXX) $(CXXFLAGS) $(SOURCES) -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

sudoku.o: sudoku.cpp
	$(CXX) $(CXXFLAGS) -c sudoku.cpp