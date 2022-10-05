CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=test.cpp complex.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tests

all: $(SOURCES) $(EXECUTABLE)
	./tests
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


	

