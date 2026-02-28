CXX       = g++
CXXFLAGS  = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic -g

SOURCES   = $(wildcard *.cpp)
OBJECTS   = $(SOURCES:.cpp=.o)

main.exe: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o main.exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main.exe