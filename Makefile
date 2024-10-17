CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

TARGET = car_test

OBJS = main.o car.o perf.o


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

#main.cpp
main.o: main.cpp car.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

#car.cpp
car.o: car.cpp car.hpp
	$(CXX) $(CXXFLAGS) -c car.cpp

#perf.cpp
perf.o: perf.cpp perf.hpp
	$(CXX) $(CXXFLAGS) -c perf.cpp

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean