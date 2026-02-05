CC      := gcc
LD      := ld
UIDLC   := ../../util/uidlc/build/uidlc
CFLAGS  := -I../../include -O -Wall -Wextra -Wno-unused-parameter -c $(if debug,-g,)
LDFLAGS := -L../../build -lultk -lSDL3

OUTPUT  := build/onebutton
SRCS    := src/onebutton.c
OBJS    := build/onebutton.o build/onebutton.uib.o

build: $(OUTPUT)

clean:
	rm -f $(wildcard build/*.o) $(wildcard build/*.uib)

clean_all: clean
	rm -f $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

build/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@

build/%.uib.o: build/%.uib
	$(LD) -r -b binary $< -o $@

build/%.uib: src/%.uidl
	$(UIDLC) $< -o $@

.PHONY: build clean clean_all
