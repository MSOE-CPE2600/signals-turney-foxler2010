CC := gcc
CFLAGS := -c -Wall -Werror
LDFLAGS := 

SIG_HANDLER_SOURCES := signal_handler.c
SIG_HANDLER_EXECUTABLE := signal_handler
SIG_ALARM_SOURCES := signal_alarm.c
SIG_ALARM_EXECUTABLE := signal_alarm
SIG_SEGFAULT_SOURCES := signal_segfault.c
SIG_SEGFAULT_EXECUTABLE := signal_segfault
SIG_SIGACTION_SOURCES := signal_sigaction.c
SIG_SIGACTION_EXECUTABLE := signal_sigaction
RECV_SIGNAL_SOURCES := recv_signal.c
RECV_SIGNAL_EXECUTABLE := recv_signal
SEND_SIGNAL_SOURCES := send_signal.c
SEND_SIGNAL_EXECUTABLE := send_signal

# Do not modify vars below this line!!

# All executable names are targets, as well as "all" to make all executables,
# and "debug" which is the same as "all" but with "-g" added to the compile flags.

SIG_HANDLER_OBJECTS := $(SIG_HANDLER_SOURCES:.c=.o)
SIG_ALARM_OBJECTS := $(SIG_ALARM_SOURCES:.c=.o)
SIG_SEGFAULT_OBJECTS := $(SIG_SEGFAULT_SOURCES:.c=.o)
SIG_SIGACTION_OBJECTS := $(SIG_SIGACTION_SOURCES:.c=.o)
RECV_SIGNAL_OBJECTS := $(RECV_SIGNAL_SOURCES:.c=.o)
SEND_SIGNAL_OBJECTS := $(SEND_SIGNAL_SOURCES:.c=.o)

# cram all objects into one var to avoid long lists of vars
ALL_OBJECTS := $(SIG_HANDLER_OBJECTS) \
	$(SIG_ALARM_OBJECTS) \
	$(SIG_SEGFAULT_OBJECTS) \
	$(SIG_SIGACTION_OBJECTS) \
	$(RECV_SIGNAL_OBJECTS) \
	$(SEND_SIGNAL_OBJECTS)

# cram all executables into one var to avoid long lists of vars
ALL_EXECUTABLES := $(SIG_HANDLER_EXECUTABLE) \
	$(SIG_ALARM_EXECUTABLE) \
	$(SIG_SEGFAULT_EXECUTABLE) \
	$(SIG_SIGACTION_EXECUTABLE) \
	$(RECV_SIGNAL_EXECUTABLE) \
	$(SEND_SIGNAL_EXECUTABLE)

all: $(ALL_EXECUTABLES)

debug: CFLAGS += -g
debug: $(ALL_EXECUTABLES)

clean:
	rm -rf $(ALL_EXECUTABLES)
	rm -rf $(ALL_OBJECTS)
	rm -rf *.d

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(SIG_HANDLER_EXECUTABLE): $(SIG_HANDLER_OBJECTS)
	$(CC) $(LDFLAGS) $(SIG_HANDLER_OBJECTS) -o $@

$(SIG_ALARM_EXECUTABLE): $(SIG_ALARM_OBJECTS)
	$(CC) $(LDFLAGS) $(SIG_ALARM_OBJECTS) -o $@

$(SIG_SEGFAULT_EXECUTABLE): $(SIG_SEGFAULT_OBJECTS)
	$(CC) $(LDFLAGS) $(SIG_SEGFAULT_OBJECTS) -o $@

$(SIG_SIGACTION_EXECUTABLE): $(SIG_SIGACTION_OBJECTS)
	$(CC) $(LDFLAGS) $(SIG_SIGACTION_OBJECTS) -o $@

$(RECV_SIGNAL_EXECUTABLE): $(RECV_SIGNAL_OBJECTS)
	$(CC) $(LDFLAGS) $(RECV_SIGNAL_OBJECTS) -o $@

$(SEND_SIGNAL_EXECUTABLE): $(SEND_SIGNAL_OBJECTS)
	$(CC) $(LDFLAGS) $(SEND_SIGNAL_OBJECTS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d
