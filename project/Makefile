all: libLcd.a gameMain.elf

CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -Os -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include -L../lib
CC = msp430-elf-gcc
AS = msp430-elf-as
AR = msp430-elf-ar

libLcd.a:   font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o drawUnique.o p2switches.o buzzer.o music.o
	$(AR) src $@ $^

buzzer.o: buzzer.c buzzer.h

music.o: music.c music.h

p2switches.o: p2switches.c p2switches.h

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h

lcdutils.o: lcdutils.c lcdutils.h

drawUnique.o: drawUnique.c drawUnique.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libLcd.a *.o *.elf

gameMain.elf: gameMain.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer

load: gameMain.elf
	msp430loader.sh $^



