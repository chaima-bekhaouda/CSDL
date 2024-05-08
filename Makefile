CC = g++
CFLAGS = -I include/
GOL_SRC = $(wildcard src/gol*.cpp)

TUI_SRC = $(wildcard src/tui*.cpp)
TUI_EXECUTABLE = game-of-life-tui


tui: $(GOL_SRC) $(TUI_SRC)
	$(CC) $(CFLAGS) $^ -o $(TUI_EXECUTABLE)

clean:
	rm -f $(TUI_EXECUTABLE)