# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as


all: Machine.elf


#additional rules for files
Machine.elf: ${COMMON_OBJECTS} led.o main.o state_machine.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^


load: Machine.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf *~


main.o: led.h
led.o: led.c led.h
state_machine.o: state_machine.c state_machine.h led.h
wdInterruptHandler.o: stateMachines.h
