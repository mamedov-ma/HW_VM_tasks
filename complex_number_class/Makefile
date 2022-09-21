CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=test.cpp complex.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=complex

all: $(SOURCES) $(EXECUTABLE)
	make clean
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)