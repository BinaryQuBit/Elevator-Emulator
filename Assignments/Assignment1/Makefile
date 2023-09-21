CC = g++
CCFLAGS = -Wextra -Wall -Wfloat-equal -Wconversion -Wparentheses -pedantic -Wunused-parameter -Wunused-variable -Wreturn-type -Wunused-function -Wredundant-decls -Wswitch-default -Wuninitialized -Winit-self -Werror

.PHONY: all clean

all: filter

filter: filter.cpp
	$(CC) $(CCFLAGS) -o filter filter.cpp

clean:
	rm -f filter
