MKDIR   := mkdir
RMDIR   := rm -rf
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
EXE     := $(BIN)/main.exe
CFLAGS  := -I$(INCLUDE) -std=gnu11
LDLIBS  := -lm
LDFLAS  := 

.PHONY: all run clean 

all: $(EXE)
	./bin/main.exe

$(EXE): $(OBJS) | $(BIN)
	echo $^
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	$(MKDIR) $@

run: $(EXE)
    $<

clean:
	$(RMDIR) $(OBJ) $(BIN)