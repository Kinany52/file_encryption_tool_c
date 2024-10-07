# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I include

# Directories
SRCDIR = src
BUILDDIR = build
BINDIR = $(BUILDDIR)
TESTDIR = test
TESTBINDIR = $(BUILDDIR)

# Output binary name for main program
TARGET = $(BINDIR)/encryption_tool

# Output binary name for tests
TEST_TARGET = $(TESTBINDIR)/test_encryption_tool

# Source and object files for the main program
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Source and object files for tests
TEST_SRCS = $(wildcard $(TESTDIR)/*.c)
TEST_OBJS = $(patsubst $(TESTDIR)/%.c, $(BUILDDIR)/%.o, $(TEST_SRCS))

# Exclude main.o from OBJS when building test executable
OBJS_NO_MAIN = $(filter-out $(BUILDDIR)/main.o, $(OBJS))

# Default rule (builds the main program)
all: $(TARGET)

# Build target for the main program
$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files to object files for the main program
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile source files to object files for tests
$(BUILDDIR)/%.o: $(TESTDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Test target (compiles and runs the tests)
test: $(TEST_TARGET)
	$(TEST_TARGET)

# Build target for the test executable
$(TEST_TARGET): $(TEST_OBJS) $(OBJS_NO_MAIN)
	mkdir -p $(TESTBINDIR)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS_NO_MAIN)

# Clean up the build directory
clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET) $(TEST_TARGET)