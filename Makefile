all: compile-lib compile-transporter

compile-lib:
	make -f lib/Makefile

compile-transporter:
	make -f src/Makefile