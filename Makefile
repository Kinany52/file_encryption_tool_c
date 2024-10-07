# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I include

# Directories
SRCDIR = src
BUILDDIR = build
BINDIR = $(BUILDDIR)

# Output binary name
TARGET = $(BINDIR)/encryption_tool

# Source and object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Default rule
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build directory
clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)