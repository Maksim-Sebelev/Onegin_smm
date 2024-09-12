CC = g++
CFLAGS = -c -Wall
FILES_CPP = main.cpp sort.cpp helper_func.cpp color_output.cpp flags.cpp file_to_text.cpp
OBJECTS = $(FILES_CPP:.cpp=.o)
OBJECTS_H = $(FILES_CPP:.cpp=.h)

all: $(SOURCES) main


main: $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o: $(OBJECTS_H)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o hello

