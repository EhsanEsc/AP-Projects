CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
CFLAGS = -std=c++11 -Wall -Werror -I$(INCLUDE_DIR)

EXECUTABLE_FILE = Scheduler.out

OBJECTS = \
	$(BUILD_DIR)/CommandHandler.o \
	$(BUILD_DIR)/Core.o \
	$(BUILD_DIR)/Main.o \
	$(BUILD_DIR)/Process.o \
	$(BUILD_DIR)/Thread.o \
	$(BUILD_DIR)/ThreadScheduler.o \

CommandHandlerSensitivityList = \
	$(SRC_DIR)/CommandHandler.cpp \

CoreSensitivityList = \
	$(SRC_DIR)/Core.cpp \
	$(INCLUDE_DIR)/Core.h \
	$(INCLUDE_DIR)/Thread.h \

ProcessSensitivityList = \
	$(SRC_DIR)/Process.cpp \
	$(INCLUDE_DIR)/Process.h \
	$(INCLUDE_DIR)/Thread.h \
	$(INCLUDE_DIR)/ThreadScheduler.h \
	$(INCLUDE_DIR)/Core.h

ThreadSchedulerSensitivityList = \
	$(SRC_DIR)/ThreadScheduler.cpp\
	$(INCLUDE_DIR)/ThreadScheduler.h \
	$(INCLUDE_DIR)/Process.h \
	$(INCLUDE_DIR)/Thread.h \
	$(INCLUDE_DIR)/Core.h

ThreadSensitivityList = \
	$(SRC_DIR)/Thread.cpp \
	$(INCLUDE_DIR)/Thread.h

MainSensitivityList = \
	$(SRC_DIR)/Main.cpp \
	$(INCLUDE_DIR)/CommandHandler.h

all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/CommandHandler.o: $(CommandHandlerSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/CommandHandler.cpp -o $(BUILD_DIR)/CommandHandler.o

$(BUILD_DIR)/Core.o: $(CoreSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Core.cpp -o $(BUILD_DIR)/Core.o

$(BUILD_DIR)/Process.o: $(ProcessSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Process.cpp -o $(BUILD_DIR)/Process.o

$(BUILD_DIR)/ThreadScheduler.o: $(ThreadSchedulerSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ThreadScheduler.cpp -o $(BUILD_DIR)/ThreadScheduler.o

$(BUILD_DIR)/Thread.o: $(ThreadSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Thread.cpp -o $(BUILD_DIR)/Thread.o

$(BUILD_DIR)/Main.o: $(MainSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Main.cpp -o $(BUILD_DIR)/Main.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out
