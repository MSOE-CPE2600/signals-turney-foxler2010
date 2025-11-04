CC := gcc
CFLAGS := -c -Wall -Werror
LDFLAGS := -lm
SOURCES := signal_handler.c
OBJECTS := $(SOURCES:.c=.o)
EXECUTABLE := signal_handler

all: $(SOURCES) $(EXECUTABLE)

debug: $(SOURCES) $(OBJECTS)
	$(CC) -g $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(TEST_OBJECTS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d
