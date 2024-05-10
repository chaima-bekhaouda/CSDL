CC = g++
CFLAGS = -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
GOL_SRC = $(wildcard src/gol*.cpp)

TUI_SRC = $(wildcard src/tui*.cpp)
TUI_EXECUTABLE = game-of-life-tui

GUI_SRC = $(wildcard src/gui*.cpp)
GUI_EXECUTABLE = game-of-life-gui


tui: $(wildcard src/gol*.cpp) $(wildcard src/tui*.cpp)
	$(CC) $(CFLAGS) $^ -o $(TUI_EXECUTABLE)

gui: $(wildcard src/gol*.cpp) $(wildcard src/gui*.cpp)
	$(CC) $^ $(CFLAGS) -o $(GUI_EXECUTABLE)

clean:
	rm -f $(TUI_EXECUTABLE) $(GUI_EXECUTABLE)