# Define the compiler and the flags
CXX = g++
CXXFLAGS = -fprofile-arcs -ftest-coverage -std=c++11 -g -Wall -Wextra -pedantic 

# Define the target executables
TEST_TARGET = TestingMain
DEMO_TARGET = DemoMain

# Find all .cpp files except the mains and convert them to .o files
SRCS = $(filter-out TestingMain.cpp DemoMain.cpp, $(wildcard *.cpp))
OBJS = $(SRCS:.cpp=.o)

# Targets to choose
all: $(TEST_TARGET)

# Compile TestingMain target
$(TEST_TARGET): $(OBJS) TestingMain.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(OBJS) TestingMain.o

# Compile DemoMain target
$(DEMO_TARGET): $(OBJS) DemoMain.o
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(OBJS) DemoMain.o

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run TestingMain with valgrind
run: $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET) 2> valgrind_log.txt

# Run DemoMain with valgrind
run-demo: $(DEMO_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(DEMO_TARGET) 2> valgrind_log.txt

# Run TestingMain with gdb
debug: $(TEST_TARGET)
	gdb -ex run --args ./$(TEST_TARGET) 2>&1 | tee gdb_log.txt

# Run DemoMain with gdb
debug-demo: $(DEMO_TARGET)
	gdb -ex run --args ./$(DEMO_TARGET) 2>&1 | tee gdb_log.txt

# Clean up the build files
clean:
	rm -f $(OBJS) $(TEST_TARGET) $(DEMO_TARGET) TestingMain.o DemoMain.o valgrind_log.txt gdb_log.txt *.gcno *.gcda *.gcov

# Phony targets
.PHONY: all run run-demo debug debug-demo clean
