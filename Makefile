CC      := gcc
LD      := ld
CFLAGS  := -Iinclude -Wall -Wextra -Wno-unused-parameter -c $(if debug,-g,)
LDFLAGS :=

OUTPUT_STATIC := build/libultk.a
OUTPUT_SHARED := build/libultk.so

SRCS    := $(shell find src -name '*.c')
SRCS_BE := $(shell find backend/$(backend) -name '*.c')
OBJS    := $(patsubst src/%.c,build/%.o,$(SRCS))
OBJS_BE := $(patsubst %.c,build/%.o,$(SRCS_BE))

build: build_static #build_shared

build_static: $(OUTPUT_STATIC)

build_shared: $(OUTPUT_SHARED)

test: build test/onebutton/build/onebutton

clean:
	rm -f build/*.o build/backend/*/*.o

clean_all: clean
	rm -f $(OUTPUT_STATIC) $(OUTPUT_SHARED)

backend: $(OBJS_BE)

backend_check:
ifndef backend
	@echo "error: specify a backend"
	@false
endif

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) $< -o $@

src/%.c:: src/%.h

$(OBJS_BE):: backend_check

build/backend/$(backend)/%.o: backend/$(backend)/%.c
	@mkdir -p build/backend/$(backend)
	$(CC) $(CFLAGS) $< -o $@

backend/$(backend)/%.c:: backend/$(backend)/backend.h include/ultk/ultk_backend_api.h

$(OUTPUT_STATIC): $(OBJS) $(OBJS_BE)
	ar rcs $@ $^

test/onebutton/build/onebutton: $(OUTPUT_STATIC)
	cd test/onebutton && $(MAKE) clean && $(MAKE)

.PHONY: build build_static build_shared backend backend_check test clean clean_all