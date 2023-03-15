# DEFINE VARIABLES
# Compiler: g++ for C++ and gcc for C programs
CC = g++

# Tells the compiler to compile the stuff that comes after it
CFLAGS = -c

# Source files
SOURCES = main.cpp Product.cpp

# Object files: files created from compiling source files
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

# COMMANDS
# Build executable and remove the object files
all: $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o: *.h
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
