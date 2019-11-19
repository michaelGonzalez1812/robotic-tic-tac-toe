libraries: libarduinoseriallib.a

libarduinoseriallib.a: arduino-serial-lib.o
	#Create an static library
	ar rv lib/libarduinoseriallib.a lib/arduino-serial-lib.o
	ranlib lib/libarduinoseriallib.a

arduino-serial-lib.o: lib/arduino-serial-lib.c include/arduino-serial-lib.h
	gcc -c lib/arduino-serial-lib.c -o lib/arduino-serial-lib.o -Iinclude -Llib
