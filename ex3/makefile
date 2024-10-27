CXX = g++

CXXFLAGS = -Wall -std=c++11

TARGET = kosaraju

SRC = main.cpp

OBJS = main.o 

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 