default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega2560 -c -o led.o led.c
	avr-gcc -mmcu=atmega2560 -o led.bin led.o
	avr-objcopy -O ihex -R .eeprom led.bin led.hex
	sudo avrdude -v -D -c wiring -p atmega2560 -P /dev/ttyUSB0 -b 115200 -U flash:w:led.hex
