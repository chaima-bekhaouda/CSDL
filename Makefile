CC = g++
CFLAGS = -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

GUI_EXECUTABLE = game-of-life-gui



gui: $(wildcard src/gol*.cpp) $(wildcard src/gui*.cpp)
	$(CC) $^ $(CFLAGS) -o $(GUI_EXECUTABLE)

clean:
	rm -f $(TUI_EXECUTABLE) $(GUI_EXECUTABLE)