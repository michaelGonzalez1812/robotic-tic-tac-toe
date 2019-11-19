# robotic-tic-tac-toe

## Previous Instalations ##

gwsocket [![Build Status](https://travis-ci.org/allinurl/gwsocket.svg?branch=master)](http://travis-ci.org/allinurl/gwsocket) [![gwsocket](http://gwsocket.io/badge?v0.1)](http://gwsocket.io)
========

## Installation ##
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

## Build from GitHub ##
```
$ git clone https://github.com/allinurl/gwsocket.git
$ cd gwsocket
$ autoreconf -fiv
$ ./configure
$ make
# make install
```

## Command Line / Config Options ##
The following options can be supplied to the command line.


| Command Line Option          | Description                                                         |
| ---------------------------- | --------------------------------------------------------------------|
| `-p --port`                  | Specifies the port to bind.                                         |
| `-h --help`                  | Command line help.                                                  |
| `-V --version`               | Display version information and exit.                               |
| `--access-log=<path/file>`   | Specifies the path/file for the access log.                         |
| `--addr=<addr>`              | Specifies the address to bind.                                      |
| `--echo-mode`                | Set the server to echo all received messages.                       |
| `--max-frame-size=<bytes>`   | Maximum size of a websocket frame.                                  |
| `--origin=<origin>`          | Ensure clients send the specified origin header upon handshake.     |
| `--pipein=<path/file>`       | Creates a named pipe (FIFO) that reads from on the given path/file. |
| `--pipeout=<path/file>`      | Creates a named pipe (FIFO) that writes to the given path/file.     |
| `--strict`                   | Parse messages using strict mode. See man page for more details.    |
| `--ssl-cert=<cert.crt>`      | Path to SSL certificate.                                            |
| `--ssl-key=<priv.key>`       | Path to SSL private key.                                            |

## Run the RFS6455 connector ##

Yo can choose your port and address

```
gwsocket --access-log=/tmp/access.log -p 3000 --addr=192.168.0.6
```


## Run the Server ##

```
gcc -o server.o server.c
./server.o
```