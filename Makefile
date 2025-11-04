CC := gcc
CFLAGS := -c -Wall -Werror
LDFLAGS := 

SIG_HANDLER_SOURCES := signal_handler.c
SIG_HANDLER_EXECUTABLE := signal_handler
SIG_ALARM_SOURCES := signal_alarm.c
SIG_ALARM_EXECUTABLE := signal_alarm

SIG_HANDLER_OBJECTS := $(SIG_HANDLER_SOURCES:.c=.o)
SIG_ALARM_OBJECTS := $(SIG_ALARM_SOURCES:.c=.o)

all: $(SIG_HANDLER_EXECUTABLE) $(SIG_ALARM_EXECUTABLE)

debug: CFLAGS += -g
debug: $(SIG_HANDLER_EXECUTABLE) $(SIG_ALARM_EXECUTABLE)

clean:
	rm -rf $(SIG_HANDLER_OBJECTS) $(SIG_ALARM_OBJECTS)
	rm -rf $(SIG_HANDLER_EXECUTABLE) $(SIG_ALARM_EXECUTABLE)
	rm -rf *.d

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(SIG_HANDLER_EXECUTABLE): $(SIG_HANDLER_OBJECTS)
	$(CC) $(LDFLAGS) $(SIG_HANDLER_OBJECTS) -o $@

$(SIG_ALARM_EXECUTABLE): $(SIG_ALARM_OBJECTS)
	$(CC) $(LDFLAGS) $(SIG_ALARM_OBJECTS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d
