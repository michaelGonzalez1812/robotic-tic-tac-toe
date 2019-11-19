/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Server 
 * ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>

static void read_message (int fd, fd_set set) {
  int bytes = 0;
  char buf[PIPE_BUF] = { 0 };

  FD_ZERO (&set);
  FD_SET (fd, &set);

  if ((select (fd + 1, &set, NULL, NULL, NULL)) < 1)
    exit (1);
  if (!FD_ISSET (fd, &set))
    return;

  if (read (fd, buf, PIPE_BUF) > 0)
    //printf ("%s\n", buf);
    command_identifier(buf);
}

//make the call to the library to move the robot
void command_identifier(char commands[]){
	int init_size = strlen(commands);
  char delim1[] = ",";

  //split to get the commands
  char *ptr = strtok(commands, delim1);

  char position = commands[7];
  char logo = commands[18];

	printf("%c\n", position); 
	printf("%c\n", logo); 

  printTicTacToe(position, logo);
}

void printTicTacToe(char position, char logo){
  //port to connect
  const char* serialport = "/dev/ttyACM0";
  //baudio
  int baud = 9600;
  //file descriptor
  int fd = -1;
  //string to write
  const char* str = "\n\t";

  //init conection
  fd = serialport_init(serialport,baud);
  //flush the wrong data
  serialport_flush(fd);

  if(position == '0'){
    //write to de fie
    if(logo == '1'){
      //logo one line
      serialport_write(fd,str);
    }
    else if(logo == '2'){
      //logo 2 lines
      serialport_write(fd,str);
    }
    else if(logo == '3'){
      //logo 3 lines
      serialport_write(fd,str);
    }
  }
  else if(position == '1'){
    //write to de fie
    if(logo == '1'){
      //logo one line
      serialport_write(fd,str);
    }
    else if(logo == '2'){
      //logo 2 lines
      serialport_write(fd,str);
    }
    else if(logo == '3'){
      //logo 3 lines
      serialport_write(fd,str);
    }
  }
  else if(position == '2'){
    //write to de fie
    serialport_write(fd,str);
  }
  else if(position == '3'){
    //write to de fie
    if(logo == '1'){
      //logo one line
      serialport_write(fd,str);
    }
    else if(logo == '2'){
      //logo 2 lines
      serialport_write(fd,str);
    }
    else if(logo == '3'){
      //logo 3 lines
      serialport_write(fd,str);
    }
  }
  else if(position == '4'){
    //write to de fie
    if(logo == '1'){
      //logo one line
      serialport_write(fd,str);
    }
    else if(logo == '2'){
      //logo 2 lines
      serialport_write(fd,str);
    }
    else if(logo == '3'){
      //logo 3 lines
      serialport_write(fd,str);
    }
  }
  else if(position == '5'){
    //write to de fie
    if(logo == '1'){
      //logo one line
      serialport_write(fd,str);
    }
    else if(logo == '2'){
      //logo 2 lines
      serialport_write(fd,str);
    }
    else if(logo == '3'){
      //logo 3 lines
      serialport_write(fd,str);
    }
  }
  else if(position == '6'){
    //write to de fie
    if(logo == '1'){
      //logo one line
      serialport_write(fd,str);
    }
    else if(logo == '2'){
      //logo 2 lines
      serialport_write(fd,str);
    }
    else if(logo == '3'){
      //logo 3 lines
      serialport_write(fd,str);
    }
  }
  else if(position == '7'){
    //write to de fie
    if(logo == '1'){
      //logo one line
      serialport_write(fd,str);
    }
    else if(logo == '2'){
      //logo 2 lines
      serialport_write(fd,str);
    }
    else if(logo == '3'){
      //logo 3 lines
      serialport_write(fd,str);
    }
  }
  else if(position == '8'){
    //write to de fie
    serialport_write(fd,str);
  }

  //close the file
  serialport_close(fd);
}

int main (void) {
  fd_set set;
  char *fifo = "/tmp/wspipeout.fifo";
  int fd = 0;

  if ((fd = open (fifo, O_RDWR | O_NONBLOCK)) < 0)
    exit (1);
  while (1){
    read_message(fd, set);
  }

  return 0;
}