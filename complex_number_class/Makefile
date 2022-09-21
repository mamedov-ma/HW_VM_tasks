CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp complex.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=complex

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
