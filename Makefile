# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# List all source files
SOURCES = main.cpp \
          AmericanCallOption.cpp \
          AmericanOption.cpp \
          AmericanPutOption.cpp \
          AsianCallOption.cpp \
          AsianOption.cpp \
          AsianPutOption.cpp \
          BlackScholesMCPricer.cpp \
          BlackScholesPricer.cpp \
          CallOption.cpp \
          CRRPricer.cpp \
          EuropeanDigitalCallOption.cpp \
          EuropeanDigitalOption.cpp \
          EuropeanDigitalPutOption.cpp \
          EuropeanVanillaOption.cpp \
          MT.cpp \
          Option.cpp \
          PutOption.cpp

# Object files (same as source files but with .o extension)
OBJECTS = $(SOURCES:.cpp=.o)

# Name of the output binary
TARGET = main

# Default target
all: $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Rule to compile each source file into an object file
%.o: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	@echo "Cleaning up..."
	@rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	@./$(TARGET)
