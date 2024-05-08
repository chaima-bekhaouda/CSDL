CC = g++
CFLAGS = -I include/
SRC = $(wildcard src/*.cpp)
EXECUTABLE = game-of-life


$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLE)