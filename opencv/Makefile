CXX := g++
CXXFLAGS := -std=c++17 -Wall -O2
OPENCV := $(shell pkg-config --cflags --libs opencv4)
TARGET := webcam
SRC := camera01.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(OPENCV)

clean:
	rm -f $(TARGET)
