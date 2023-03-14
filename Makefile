# Defines the C Compiler
CC := gcc

# Final file name
BINARY := out

# Code directory structure
SRCDIR := src
INCDIR := include	
BINDIR := bin
BUILDDIR := build

# Compiler flags
CFLAGS := -Wall -I$(INCDIR)
LDFLAGS := -lm -lSDL2

# %.o file names
NAMES := $(notdir $(basename $(wildcard $(SRCDIR)/*.c)))
OBJECTS :=$(patsubst %,$(BUILDDIR)/%.o,$(NAMES))


# Rule for link and generate the binary file
all: $(OBJECTS)
	@ if [ ! -d ./$(BINDIR) ]; then mkdir -p $(BINDIR);	fi
	$(CC) -o $(BINDIR)/$(BINARY) $+ $(LDFLAGS)

# Rule for object binaries compilation
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@ if [ ! -d ./$(BINDIR) ]; then mkdir -p $(BUILDDIR);fi
	$(CC) -c $^ -o $@ $(CFLAGS) 



# Clean BIN and BUILD dirs
.PHONY: clean
clean: 
	rm -rf $(BUILDDIR) $(BINDIR)
