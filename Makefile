CC = g++
CFLAGS = -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
TUI_EXECUTABLE = game-of-life-tui

GUI_EXECUTABLE = game-of-life-gui


tui: $(wildcard src/gol*.cpp) $(wildcard src/tui*.cpp)
	$(CC) $(CFLAGS) $^ -o $(TUI_EXECUTABLE)

gui: $(wildcard src/gol*.cpp) $(wildcard src/gui*.cpp)
	$(CC) $^ $(CFLAGS) -o $(GUI_EXECUTABLE)

clean:
	rm -f $(TUI_EXECUTABLE) $(GUI_EXECUTABLE)