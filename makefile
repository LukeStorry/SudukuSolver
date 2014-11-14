#This makefile is much more complicated than it needs to be, butI was just using it as an exercise.
#Credit to https://felixcrux.com/blog/creating-basic-makefile for an excellent tutorial

CC     = gcc 
FLAGS  = -std=gnu99 -Iinclude
WFLAGS = -Wall -Wextra -pedantic -O3 -combine -fwhole-program


TARGET = SudukuSolver
SOURCES = $(shell echo src/*.c)
HEADERS = $(shell echo include/*.h)
OBJECTS = $(SOURCES:.c=.o)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin



all:$(TARGET)

$(TARGET): $(OBJECTS) $(HEADERS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJECTS)

warn: $(SOURCES) $(HEADERS)
	$(CC) $(FLAGS) $(WFLAGS) -o $(TARGET) $(SOURCES)

clean:
	-rm -f $(OBJECTS)
	-rm -f gmon.out


#%.o: %.c $(HEADERS) $(COMMON)
#	$(CC) $(FLAGS) $(CFLAGS) -c -o $@ $<


