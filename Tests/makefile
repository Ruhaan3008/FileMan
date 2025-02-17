# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O -pedantic

# Source files
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = test.exe

# Default target
all: $(TARGET) 

# Compile and link
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile each .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build
clean:
	del $(TARGET)
	del $(OBJS)
	del *.txt

re:
	make clean
	make
	type nul > del_test.txt

run:
	.\$(TARGET)