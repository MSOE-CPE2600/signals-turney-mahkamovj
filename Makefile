# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRC = signal_handler.c signal_alarm.c signal_segfault.c signal_sigaction.c recv_signal.c send_signal.c

# Executable names (same as source filenames without .c)
TARGETS = $(SRC:.c=)

# Default target: build all programs
all: $(TARGETS)

# Generic build rule
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# ==========================================================
# Run targets
# ==========================================================

run-handler: signal_handler
	@echo "Running Signal Handler demo (Part 2)..."
	./signal_handler

run-alarm: signal_alarm
	@echo "Running Alarm Signal demo (SIGALRM)..."
	./signal_alarm

run-segfault: signal_segfault
	@echo "Running Segmentation Fault demo (SIGSEGV)..."
	./signal_segfault

run-sigaction: signal_sigaction
	@echo "Running Sigaction demo (SIGUSR1)..."
	@echo "Run 'kill -SIGUSR1 <PID>' from another terminal after it starts."
	./signal_sigaction

run-recv: recv_signal
	@echo "Running Receiver (for Part 4)..."
	./recv_signal

run-send: send_signal
	@echo "Running Sender (for Part 4)..."
	@echo "Usage: ./send_signal <receiver_pid>"
	@echo "Example: ./send_signal 12345"

# ==========================================================
# Utility targets
# ==========================================================

# Remove all compiled binaries
clean:
	rm -f $(TARGETS)
	@echo "All binaries cleaned."

# Display help information
help:
	@echo ""
	@echo "Available make commands:"
	@echo "  make all             - Compile all programs"
	@echo "  make run-handler     - Run Part 2: signal_handler"
	@echo "  make run-alarm       - Run Part 3: signal_alarm"
	@echo "  make run-segfault    - Run Part 3: signal_segfault"
	@echo "  make run-sigaction   - Run Part 3: signal_sigaction"
	@echo "  make run-recv        - Run Part 4: recv_signal"
	@echo "  make run-send        - Run Part 4: send_signal"
	@echo "  make clean           - Remove all executables"
	@echo ""