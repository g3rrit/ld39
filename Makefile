TARGET_EXEC ?= a.out

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
PSRC_DIRS ?= ./pearsrc

PCC = ~/Desktop/projects/pearC/comp/v3/build/comp.out

SRCS = $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
PSRCS = $(shell find $(PSRC_DIRS) -name *.pear)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

SDLFLAGS = -Ilibs/sdl/Headers -lSDL2 -lSDL2_image

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP $(shell pkg-config -lSDL2_image --cflags --libs sdl2)

LDFLAGS += $(shell pkg-config --cflags --libs sdl2)

all: 
	$(PCC) -of ~/Desktop/projects/pearcproj/ld39/src $(PSRCS)	
	gcc $(SRCS) -o $(BUILD_DIR)/$(TARGET_EXEC) $(INC_FLAGS) $(SDLFLAGS)

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p

