
CC = g++
CFLAGS = -I/home/stub/repos/SFML/include
LDFLAGS = -L/home/stub/repos/SFML/build/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# List your source files here
SOURCES = main.cpp asteroid.cpp ship.cpp projectile.cpp collisions.cpp

# Generate a list of object files from the source files
OBJECTS = $(SOURCES:.cpp=.o)

all: sfml-app

sfml-app: $(OBJECTS)
	$(CC) $(OBJECTS) -g -o asteroids $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f snake $(OBJECTS)
