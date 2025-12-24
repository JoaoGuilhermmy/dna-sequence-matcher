CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = dnaprofiler
SOURCES = main.cpp Database.cpp DNA.cpp UserInterface.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)