CC     = gcc 
FLAGS  = -std=gnu99 
CFLAGS = -Wall -Wextra -O3 -combine -fwhole-program


TARGET = SudukuSolver
SOURCES = $(shell echo src/*.c)
HEADERS = $(shell echo include/*.h)
OBJECTS = $(SOURCES:.c=.o)


