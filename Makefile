CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = studentai
SOURCES = 2uzd.cpp
HEADERS = Papildai.hpp Studentas.hpp

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f $(TARGET)
