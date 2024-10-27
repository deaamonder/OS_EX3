# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11 -pg

# Target executable
TARGET1 = kosaraju_adjList
TARGET2 = kosaraju_adjMatrix
TARGET3 = kosaraju_deque
TARGET4 = kosaraju_list

# Source files
SRCS1 = kosaraju_adjList.cpp 
SRCS2 = kosaraju_adjMatrix.cpp 
SRCS3 = kosaraju_deque.cpp 
SRCS4 = kosaraju_list.cpp

# Object files
OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)
OBJS3 = $(SRCS3:.cpp=.o)
OBJS4 = $(SRCS4:.cpp=.o)


# Default rule
all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) 
# Linking
$(TARGET1): $(OBJS1)
	$(CXX) $(CXXFLAGS) -o $(TARGET1) $(OBJS1)

$(TARGET2): $(OBJS2)
	$(CXX) $(CXXFLAGS) -o $(TARGET2) $(OBJS2)

$(TARGET3): $(OBJS3)
	$(CXX) $(CXXFLAGS) -o $(TARGET3) $(OBJS3)

$(TARGET4): $(OBJS4)
	$(CXX) $(CXXFLAGS) -o $(TARGET4) $(OBJS4)

# Compiling
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
clean:
	rm -f $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4) $(TARGET3) $(TARGET4) $(TARGET1) $(TARGET2)

# Phony targets
.PHONY: all clean