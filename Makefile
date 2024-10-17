CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# The target executable
TARGET = car_test

# Object files needed for the target
OBJS = main.o car.o perf.o

# Default target that builds the application
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.cpp
main.o: main.cpp car.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile car.cpp
car.o: car.cpp car.hpp
	$(CXX) $(CXXFLAGS) -c car.cpp

# Rule to compile perf.cpp
perf.o: perf.cpp perf.hpp
	$(CXX) $(CXXFLAGS) -c perf.cpp

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean