# Brief:  Biblioteca de info1 para C
# Author: Javier Balloffet <jballoffet@frba.utn.edu.ar>
# Date:   Apr 10, 2021

################################################################
# LIBRARY INFORMATION                                          #
################################################################

VERSION                  = 1.0.0
MAJOR_VERSION            = $(shell echo $(VERSION) | cut -d'.' -f1)

LIB_NAME                 = info1
LIB_BASENAME             = lib$(LIB_NAME)
STATIC_LIB               = $(LIB_BASENAME).a
SHARED_LIB_BASE          = $(LIB_BASENAME).so
SHARED_LIB_MAJOR_VERSION = $(LIB_BASENAME).so.$(MAJOR_VERSION)
SHARED_LIB               = $(LIB_BASENAME).so.$(VERSION)

################################################################
# SOURCES, HEADERS, OBJECTS, LIBRARIES AND EXECUTABLES         #
################################################################

BIN_DIR         = bin
BUILD_DIR       = build
INC_DIR         = include
SRC_DIR         = src
TEST_DIR        = test
INSTALL_DIR     = /usr/local

LIB_SOURCE      = $(SRC_DIR)/info1.c
LIB_HEADER_NAME = info1.h
LIB_HEADER      = $(INC_DIR)/$(LIB_HEADER_NAME)
LIB_OBJ         = $(BUILD_DIR)/info1.o

TEST_SOURCE     = $(TEST_DIR)/main.c
TEST_OBJ        = $(BUILD_DIR)/main.o
TEST_EXEC       = app

################################################################
# COMPILER AND ARGUMENTS                                       #
################################################################

CC           = gcc
CFLAGS       = -Wall -I$(INC_DIR)
LIB_LDFLAGS  = -Wl,-soname,$(SHARED_LIB_MAJOR_VERSION)
TEST_LDFLAGS = -L./$(BIN_DIR) -l$(LIB_NAME)

################################################################
# MAKE TARGETS                                                 #
################################################################

## all:        Builds libinfo1 library, both as static and shared libraries.
.PHONY: all
all: $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(LIB_SOURCE) $(LIB_HEADER) Makefile
	@echo '[BUILD] Building $@'
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)
	@$(CC) $(CFLAGS) -c -o $(LIB_OBJ) $(LIB_SOURCE)
	@ar rcs $(BIN_DIR)/$@ $(LIB_OBJ)

$(SHARED_LIB): $(LIB_SOURCE) $(LIB_HEADER) Makefile
	@echo '[BUILD] Building $@'
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)
	@$(CC) $(CFLAGS) -c -fPIC -o $(LIB_OBJ) $(LIB_SOURCE)
	@$(CC) -shared $(LIB_LDFLAGS) -o $(BIN_DIR)/$@ $(LIB_OBJ)

## test:       Compiles, links and executes test app.
.PHONY: test
test: $(STATIC_LIB)
	@echo '[TEST] Building test app'
	@$(CC) $(CFLAGS) -c -o $(TEST_OBJ) $(TEST_SOURCE)
	@$(CC) -o $(BIN_DIR)/$(TEST_EXEC) $(TEST_OBJ) $(TEST_LDFLAGS)
	@./$(BIN_DIR)/$(TEST_EXEC)

## clean:      Removes generated binaries.
.PHONY: clean
clean:
	@echo '[CLEAN] Cleaning workspace'
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

## install:    Installs the library under `/usr/local` (requires root access).
.PHONY: install
install: all
	@echo '[INSTALL] Installing libinfo1'
	@mkdir -p $(addprefix $(INSTALL_DIR)/, lib include)
	@cp $(addprefix $(BIN_DIR)/, $(STATIC_LIB) $(SHARED_LIB)) $(INSTALL_DIR)/lib
	@ln -sf $(SHARED_LIB) $(INSTALL_DIR)/lib/$(SHARED_LIB_BASE)
	@ln -sf $(SHARED_LIB) $(INSTALL_DIR)/lib/$(SHARED_LIB_MAJOR_VERSION)
	@cp $(LIB_HEADER) $(INSTALL_DIR)/include
	@ldconfig $(INSTALL_DIR)/lib

## uninstall:  Uninstalls the library (requires root access).
.PHONY: uninstall
uninstall:
	@echo '[UNINSTALL] Uninstalling libinfo1'
	@rm -f $(INSTALL_DIR)/include/$(LIB_HEADER_NAME)
	@rm -f $(addprefix $(INSTALL_DIR)/lib/, $(STATIC_LIB) $(SHARED_LIB) $(SHARED_LIB_BASE) $(SHARED_LIB_MAJOR_VERSION))
	@ldconfig $(INSTALL_DIR)/lib

## help:       Shows help.
.PHONY: help
help:
	@sed -n 's/^## //p' Makefile
