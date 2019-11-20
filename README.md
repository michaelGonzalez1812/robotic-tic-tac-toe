# robotic-tic-tac-toe

## Previous Instalations ##


Installing gwsocket is pretty easy. Just download, extract and compile it with:

```
$ wget http://tar.gwsocket.io/gwsocket-0.3.tar.gz
$ tar -xzvf gwsocket-0.3.tar.gz
$ cd gwsocket-0.3/
$ ./configure
$ make
# make install
```
No dependencies needed. How nice isn't it :), well almost, you need `gcc`, `make`, etc.

## Instructions for APP



## Instructions for Driver

##Compiling and loading modules
go to class directory and the execute the following command
```
./comp.sh
```

if is necessary give execurion permission to the script
```
chmod +x comp.sh
```
This script compile and load the module to the kernel.
Notice this driver was writted to 4.19 linux kernel.

## Instructions for server

```
gcc -o server.o server.c
./server.o
```
