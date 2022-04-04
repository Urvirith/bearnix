# ARM GCC COMPILER CALL - AARCH64

# Toolchain To Use
TOOLCHAIN	:= aarch64-none-elf-
CC		    := $(TOOLCHAIN)gcc		# c compiler
AS			:= $(TOOLCHAIN)as		# assembler
LD 			:= $(TOOLCHAIN)ld 		# linker
OBJ 		:= $(TOOLCHAIN)objcopy	# Object Copy
READELF		:= $(TOOLCHAIN)readelf  # Read Elf

# -Os				Optimize for Size
# -mcpu=cortex-m4	Compile for the ARM M4 Processor
# mthumb			Target the MTHUMB Instruction Set
# -ftlo				Set Linker Time Optimisations
ARCH 		:= a53
TARGET_ARCH := -mcpu=cortex-$(ARCH)
FREESTAND 	:= -ffreestanding
WALL		:= -Wall -Wextra
LINKTIME	:= -flto
OPTFLAGS	:= -Os
CFLAGS	  	:= $(OPTFLAGS) $(TARGET_ARCH) $(FREESTAND) $(WALL)
ASFLAGS		:= $(TARGET_ARCH)
LDFLAGS 	:= -T
OBJFLAGS	:= -O binary

INC_DIR   := inc
SRC_DIR   := src
START_DIR := startup
LINK_DIR  := linker
OBJ_DIR	  := obj
BIN_DIR	  := bin
KER_DIR   := kernel
HAL_DIR   := bcm2837_hal
LIB_DIR   := lib

#ONLY ONE
STARTUP		:= startup.s

#ONLY ONE
LINKER		:= linker.ld

OBJS :=	$(OBJ_DIR)/main.o

HAL_OBJS := $(OBJ_DIR)/main.o

#	EXAMPLE OF AUTOMATIC VARIABLES
#	%.o: %.c %.h common.h
#		$(CC) $(CFLAGS) -c $<
#
#	$@ Looks at the target
#	(Target)
#	%.o: 			%.c %.h common.h
#	
#	$< Looks at the first source
#			(First Source)
#	%.o: 	%.c 					%.h common.h
#		$(CC) $(CFLAGS) -c $<
#	$^ Looks at the first source
#			(All Source)
#	%.o: 	%.c %.h common.h
#		$(CC) $(CFLAGS) -c $^
release: $(BIN_DIR)/kernel8.img

# Build An IMG 
$(BIN_DIR)/kernel8.img: $(BIN_DIR)/main.elf
	$(OBJ) $(OBJFLAGS) $^ $@

# Build An ELF 
$(BIN_DIR)/main.elf: $(KER_DIR)/$(LINK_DIR)/$(LINKER) $(OBJS) $(BIN_DIR)/startup.o
	$(LD) $(OPTFLAGS) -s $(LDFLAGS) $^ -o $@

# Build Dependances
$(BIN_DIR)/startup.o: $(KER_DIR)/$(START_DIR)/$(STARTUP)
	$(AS) -c $< $(ASFLAGS) -o $@

$(OBJ_DIR)/%.o: $(KER_DIR)/$(SRC_DIR)/%.c 
	$(CC) -I $(KER_DIR)/$(INC_DIR) -I $(LIB_DIR)/$(INC_DIR) $(CFLAGS) -c  $< -o $@

hal: $(BIN_DIR)/hal.bin

# Build An BIN 
$(BIN_DIR)/hal.bin: $(BIN_DIR)/hal.elf
	$(OBJ) $(OBJFLAGS) $^ $@

# Build An ELF 
$(BIN_DIR)/hal.elf: $(HAL_OBJS)
	$(LD) $(OPTFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(HAL_DIR)/$(SRC_DIR)/%.c
	$(CC) -I $(HAL_DIR)/$(INC_DIR) -I $(LIB_DIR)/$(INC_DIR) $(CFLAGS) -c  $< -o $@

read:
	$(READELF) -a $(BIN_DIR)/hal.elf

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/*.elf
	rm -f $(BIN_DIR)/*.bin
	rm -f $(BIN_DIR)/*.img

run:
	qemu-system-aarch64 -M raspi3b -kernel bin/kernel8.img -serial stdio

setup:
	mkdir obj
	mkdir bin

# To Move The Rules
#sudo cp ./rules/*.rules /etc/udev/rules.d/