CXX := g++
CXXFLAGS := -std=c++17 -Wall -O2 -fPIC
OPENCV := $(shell pkg-config --cflags --libs opencv4)
TARGET := ocl_webcam
SRC := opencl01.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(OPENCV)

clean:
	rm -f $(TARGET)