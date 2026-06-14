CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
#LDFLAGS= --specs=nano.specs -mcpu=$(MACH) -mthumb -mfloat-abi=soft -T stm32_ls.ld -Wl,-Map=final.map
LDFLAGS_SH= --specs=rdimon.specs -mcpu=$(MACH) -mthumb -mfloat-abi=soft -T stm32_ls.ld -Wl,-Map=final.map

all:main.o led.o stm32_startup.o syscalls.o final.elf

semi:main.o led.o stm32_startup.o syscalls.o final_sh.elf

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@

led.o:led.c
	$(CC) $(CFLAGS) $^ -o $@

syscalls.o:syscalls.c
	$(CC) $(CFLAGS) $^ -o $@
	
stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@
	
final.elf:main.o led.o stm32_startup.o syscalls.o
	$(CC) $(LDFLAGS) $^ -o $@

final_sh.elf:main.o led.o stm32_startup.o
	$(CC) $(LDFLAGS_SH) $^ -o $@

clean:
	rm -rf *.o *.elf
	
load:
	openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg

