#=======================================================================
#   @file
#   @brief  RX65N Makefile
#   @author 平松邦仁 (hira@rvf-rc45.net)
#	@copyright	Copyright (C) 2018 Kunihito Hiramatsu @n
#				Released under the MIT license @n
#				https://github.com/hirakuni45/RX/blob/master/LICENSE
#=======================================================================
TARGET		=	nesemu

DEVICE		=	R5F565NE

FATFS_VER	=	ff12b

BUILD		=	release

VPATH		=	../ emu

ASOURCES	=	common/start.s

CSOURCES	=	common/init.c \
				common/vect.c \
				common/syscalls.c \
				$(FATFS_VER)/src/ff.c \
				$(FATFS_VER)/src/option/unicode.c \
				common/time.c \
				./emu/log.c \
				./emu/bitmap.c \
				./emu/cpu/nes6502.c \
				./emu/nes/mmclist.c \
				./emu/nes/nes.c \
				./emu/nes/nes_mmc.c \
				./emu/nes/nes_pal.c \
				./emu/nes/nes_ppu.c \
				./emu/nes/nes_rom.c \
				./emu/nes/nesinput.c \
				./emu/nes/nesstate.c \
				./emu/sndhrdw/fds_snd.c \
				./emu/sndhrdw/mmc5_snd.c \
				./emu/sndhrdw/nes_apu.c \
				./emu/sndhrdw/vrcvisnd.c \
				./emu/mappers/map000.c \
				./emu/mappers/map001.c \
				./emu/mappers/map002.c \
				./emu/mappers/map003.c \
				./emu/mappers/map004.c \
				./emu/mappers/map005.c \
				./emu/mappers/map007.c \
				./emu/mappers/map008.c \
				./emu/mappers/map009.c \
				./emu/mappers/map011.c \
				./emu/mappers/map015.c \
				./emu/mappers/map016.c \
				./emu/mappers/map018.c \
				./emu/mappers/map019.c \
				./emu/mappers/map024.c \
				./emu/mappers/map032.c \
				./emu/mappers/map033.c \
				./emu/mappers/map034.c \
				./emu/mappers/map040.c \
				./emu/mappers/map041.c \
				./emu/mappers/map042.c \
				./emu/mappers/map046.c \
				./emu/mappers/map050.c \
				./emu/mappers/map064.c \
				./emu/mappers/map065.c \
				./emu/mappers/map066.c \
				./emu/mappers/map070.c \
				./emu/mappers/map073.c \
				./emu/mappers/map075.c \
				./emu/mappers/map078.c \
				./emu/mappers/map079.c \
				./emu/mappers/map085.c \
				./emu/mappers/map087.c \
				./emu/mappers/map093.c \
				./emu/mappers/map094.c \
				./emu/mappers/map099.c \
				./emu/mappers/map160.c \
				./emu/mappers/map229.c \
				./emu/mappers/map231.c \
				./emu/mappers/mapvrc.c \
				./emu/libsnss/libsnss.c

PSOURCES	=	main.cpp

USER_LIBS	=	stdc++ m

LDSCRIPT	=	../RX65x/$(DEVICE).ld

USER_DEFS	=	SIG_RX65N F_ICLK=120000000 F_FCLK=60000000 F_PCLKA=120000000 F_PCLKB=60000000 F_PCLKD=60000000 FAT_FS

MCU_TARGET	=	

INC_SYS		=

INC_APP		=	. ../ ../RX600 ../RX56x \
				./emu ./emu/cpu ./emu/nes ./emu/mappers ./emu/sndhrdw ./emu/libsnss

# OPTIMIZE	=	-Os
OPTIMIZE	=	-O3

CP_OPT		=	-Wall -Werror \
				-Wno-unused-variable \
				-Wno-unused-function \
				-Wno-unused-but-set-variable \
				-Wno-maybe-uninitialized \
				-fno-exceptions

CC_OPT		=	-Wall -Werror \
				-Wno-unused-variable \
				-Wno-unused-function \
				-Wno-maybe-uninitialized \
				-Wno-unused-but-set-variable \
				-Wno-strict-aliasing \
				-fno-exceptions

SYSINCS		=	$(addprefix -I, $(INC_SYS))
APPINCS		=	$(addprefix -I, $(INC_APP))
AINCS		=	$(SYSINCS) $(APPINCS)
CINCS		=	$(SYSINCS) $(APPINCS)
PINCS		=	$(SYSINCS) $(APPINCS)
LIBINCS		=	$(addprefix -L, $(LIB_ROOT))
DEFS		=	$(addprefix -D, $(USER_DEFS))
LIBS		=	$(addprefix -l, $(USER_LIBS))

# You should not have to change anything below here.
AS			=	rx-elf-as
CC			=	rx-elf-gcc
CP			=	rx-elf-g++
AR			=	rx-elf-ar
LD			=	rx-elf-ld
OBJCOPY		=	rx-elf-objcopy
OBJDUMP		=	rx-elf-objdump
SIZE		=	rx-elf-size

# AFLAGS        = -Wa,-adhlns=$(<:.s=.lst),-gstabs
# AFLAGS        =	-Wa,-adhlns=$(<:.s=.lst)
# ALL_ASFLAGS    = -x assembler-with-cpp $(ASFLAGS) $(DEFS)
ALL_ASFLAGS    = $(AFLAGS) $(MCU_TARGET) $(DEFS)

# Override is only needed by avr-lib build system.

CFLAGS		=	-std=gnu99 $(CC_OPT) $(OPTIMIZE) $(MCU_TARGET) $(DEFS)
PFLAGS		=	-std=c++14 $(CP_OPT) $(OPTIMIZE) $(MCU_TARGET) $(DEFS)
# override LDFLAGS	= $(MCU_TARGET) -nostartfiles -Wl,-Map,$(TARGET).map,-fdata-sections,-ffunction-sections,-falign-jumps,-fno-function-cse,-funit-at-a-time --select-lib=newlib -T $(LDSCRIPT)
# override LDFLAGS	= $(MCU_TARGET) -nostartfiles -Wl,-Map,$(TARGET).map,--cref,--gc-sections -T $(LDSCRIPT)

override LDFLAGS = $(MCU_TARGET) -nostartfiles -Wl,-Map,$(TARGET).map -T $(LDSCRIPT)

OBJCOPY_OPT	=	--srec-forceS3 --srec-len 32

OBJECTS	=	$(addprefix $(BUILD)/,$(patsubst %.s,%.o,$(ASOURCES))) \
			$(addprefix $(BUILD)/,$(patsubst %.c,%.o,$(CSOURCES))) \
			$(addprefix $(BUILD)/,$(patsubst %.cpp,%.o,$(PSOURCES)))

DOBJECTS =	$(addprefix $(BUILD)/,$(patsubst %.c,%.o,$(CSOURCES))) \
			$(addprefix $(BUILD)/,$(patsubst %.cpp,%.o,$(PSOURCES)))

DEPENDS =   $(patsubst %.o,%.d, $(DOBJECTS))

.PHONY: all clean
.SUFFIXES :
.SUFFIXES : .rc .hpp .s .h .c .cpp .d .o

all: $(BUILD) $(TARGET).elf text

$(TARGET).elf: $(OBJECTS) $(LDSCRIPT) Makefile
	$(CC) $(LDFLAGS) $(LIBINCS) -o $@ $(OBJECTS) $(LIBS)
	$(SIZE) $@

$(BUILD)/%.o: %.s
	mkdir -p $(dir $@); \
	$(AS) -c $(AOPT) $(AFLAGS) $(AINCS) -o $@ $<

$(BUILD)/%.o : %.c
	mkdir -p $(dir $@); \
	$(CC) -c $(COPT) $(CFLAGS) $(CINCS) $(CCWARN) -o $@ $<

$(BUILD)/%.o : %.cpp
	mkdir -p $(dir $@); \
	$(CP) -c $(POPT) $(PFLAGS) $(PINCS) $(CPWARN) -o $@ $<

$(BUILD)/%.d: %.c
	mkdir -p $(dir $@); \
	$(CC) -MM -DDEPEND_ESCAPE $(COPT) $(CFLAGS) $(APPINCS) $< \
	| sed 's/$(notdir $*)\.o:/$(subst /,\/,$(patsubst %.d,%.o,$@) $@):/' > $@ ; \
	[ -s $@ ] || rm -f $@

$(BUILD)/%.d: %.cpp
	mkdir -p $(dir $@); \
	$(CP) -MM -DDEPEND_ESCAPE $(POPT) $(PFLAGS) $(APPINCS) $< \
	| sed 's/$(notdir $*)\.o:/$(subst /,\/,$(patsubst %.d,%.o,$@) $@):/' > $@ ; \
	[ -s $@ ] || rm -f $@

clean:
	rm -rf $(BUILD) $(TARGET).elf $(TARGET).mot $(TARGET).lst $(TARGET).map

clean_depend:
	rm -f $(DEPENDS)

lst:  $(TARGET).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

# Rules for building the .text rom images

text: mot lst

bin: $(TARGET).bin
mot: $(TARGET).mot
lst: $(TARGET).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.mot: %.elf
	$(OBJCOPY) $(OBJCOPY_OPT) -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
#	$(OBJCOPY) -j .vects -j .text -j .data -O binary $< $@

tarball:
	tar cfvz $(subst .elf,,$(TARGET))_$(shell date +%Y%m%d%H).tgz \
	*.[hc]pp Makefile ../common/*/*.[hc]pp ../common/*/*.[hc]

bin_zip:
	$(LK) $(LFLAGS) $(LIBS) $(OBJECTS) $(ICON_OBJ) $(LIBN) -mwindows -o $(TARGET) 
	rm -f $(subst .exe,,$(TARGET))_$(shell date +%Y%m%d%H)_bin.zip
	zip $(subst .exe,,$(TARGET))_$(shell date +%Y%m%d%H)_bin.zip *.exe *.dll res/*.*

run:
	rx_prog -d RX64M --progress --erase --write --verify $(TARGET).mot

-include $(DEPENDS)