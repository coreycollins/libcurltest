SOURCES=test.c
EXECUTABLE=test

CURL_CFLAGS = $(shell curl-config --cflags)
CURL_LDFLAGS = $(shell curl-config --libs)

WARNINGS=-Wall -Wmissing-prototypes -Wpointer-arith -Wendif-labels -Wmissing-format-attribute -Wformat-security
# _POSIX_C_SOURCE=200809L enables strdup
CFLAGS=-c -std=c99 -D_POSIX_C_SOURCE=200809L $(CURL_CFLAGS) $(WARNINGS)
LDFLAGS=$(CURL_LDFLAGS)
CC=gcc
OBJECTS=$(SOURCES:.c=.o)

.PHONY: all clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(STATICLIB) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $< $(CFLAGS) -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)