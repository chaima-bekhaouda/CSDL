CC = g++
CFLAGS = -I include/
GOL_SRC = $(wildcard src/gol*.cpp)

TUI_SRC = $(wildcard src/tui*.cpp)
TUI_EXECUTABLE = game-of-life-tui

GUI_SRC = $(wildcard src/gui*.cpp)
GUI_EXECUTABLE = game-of-life-gui


tui: $(GOL_SRC) $(TUI_SRC)
	$(CC) $(CFLAGS) $^ -o $(TUI_EXECUTABLE)

gui: $(GOL_SRC) $(GUI_SRC)
	$(CC) $(CFLAGS) $^ -o $(GUI_EXECUTABLE)

clean:
	rm -f $(TUI_EXECUTABLE) $(GUI_EXECUTABLE)