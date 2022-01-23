CC ?= cc
RM ?= rm
PROGRAM ?= jebpview

CFLAGS ?=
EXTRA_CFLAGS ?= -std=c99 -Wall -Wextra -Wpedantic -Wconversion -Wstrict-prototypes -Wmissing-prototypes
SDL_CFLAGS ?= $(shell sdl2-config --cflags)
ALL_CFLAGS ?= $(EXTRA_CFLAGS) $(CFLAGS) $(SDL_CFLAGS)

LDFLAGS ?=
EXTRA_LDFLAGS ?=
SDL_LDFLAGS ?= $(shell sdl2-config --libs)
ALL_LDFLAGS ?= $(EXTRA_LDFLAGS) $(LDFLAGS) $(SDL_LDFLAGS)

all:
	$(CC) -c jebp.c -o jebp.o $(ALL_CFLAGS)
	$(CC) jebpview.c -o $(PROGRAM) $(ALL_CFLAGS) $(ALL_LDFLAGS)

clean:
	$(RM) jebp.o $(PROGRAM)

debug:
	$(MAKE) all CFLAGS='-g -DJEBP_LOG_ERRORS $(CFLAGS)'

release:
	$(MAKE) all CFLAGS='-O3 -Werror -Wno-error=unused-function $(CFLAGS)'

.PHONY: all clean debug release
