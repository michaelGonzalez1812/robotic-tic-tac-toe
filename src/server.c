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
  //printf("%s\n",commands);
	int init_size = strlen(commands);
  char delim1[] = ",";

  //split to get the commands
  char *ptr = strtok(commands, delim1);

  char position = commands[7];
  char logo = commands[18];
  char size = commands[27];
  char win = commands[35];

  printTicTacToe(position, logo, size, win);
}

void printTicTacToe(char position, char logo, char size, char win){
  //port to connect
  printf("position %c\n",position);
  printf("logo %c\n",logo);
  printf("size %c\n",size);
  printf("win %c\n\n",win);
  const char* serialport = "/dev/ttyACMard1";
  //baudio
  int baud = 9600;
  //file descriptor
  int fd = -1;


  //string to concatenate
  //lvl 2
  const char* horizontal22 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\r";
  const char* horizontal21 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\r";
  const char* horizontal20 = "wwwwwwww\n\r";
  const char* vertical22 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n\r";
  const char* vertical21 = "a";
  const char* vertical20 = "ddddddddddddddddddddddddddddd\n\r";

  //lvl 1
  const char* horizontal12 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\r";
  const char* horizontal11 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\r";
  const char* horizontal10 = "wwwwwwwwwwwwwwwwwwwww\n\r";
  const char* vertical12 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n\r";
  const char* vertical11 = "aaaaaaaaa\n\r";
  const char* vertical10 = "dddddddddddddddddddddddd\n\r";

  //lvl 0
  const char* horizontal02 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\r";
  const char* horizontal01 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\r";
  const char* horizontal00 = "wwwwwwwwwwwwwwwwwwwwwwwwwww\n\r";
  const char* vertical02 = "aaaaaaaaaaaaaaaaaaaaaa\n\r";
  const char* vertical01 = "aaaaaaa\n\r";
  const char* vertical00 = "ddddddddd\n\r";

  //logo0
  const char* logo1 = "sssssssssss\n\r";
  //logo1
  const char* logo2 = "aaaaaaaaaaaaaaa\n\r";
  //logo2
  const char* logo3 = "sssssssssssaaaaaaaaaaa\n\r";

  //pencil down
  const char* down = "oooooooooooooo\n\r";

  //pencil up
  const char* up = "lllllll\n\r";

  //init conection
  fd = serialport_init(serialport,baud);
  //flush the wrong data
  serialport_flush(fd);

  //size of the draw
  if(win == '0'){
    if(size == '0'){
      if(position == '0'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical00);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical00);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '1'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
        }
      }
      else if(position == '2'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal00);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '3'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical00);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical00);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical00);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '4'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '5'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal01);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '6'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal02);
          serialport_write(fd,vertical00);
          serialport_write(fd,down);
          serialport_write(fd,logo1);
          serialport_write(fd,up);
          
          
          
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal02);
          serialport_flush(fd);
          serialport_write(fd,vertical00);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal02);
          serialport_flush(fd);
          serialport_write(fd,vertical00);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '7'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal02);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal02);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal02);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '8'){
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal02);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal02);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal02);
          serialport_flush(fd);
          serialport_write(fd,vertical02);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
    }
    else if(size == '1'){
      if(position == '0'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical10);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical10);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '1'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '2'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal10);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '3'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical10);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical10);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical10);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '4'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '5'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal11);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '6'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical10);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical10);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical10);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '7'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical11);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '8'){
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal12);
          serialport_flush(fd);
          serialport_write(fd,vertical12);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
    }
    else if(size == '2'){
      if(position == '0'){
       if(position == '0'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical20);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical20);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        }
      }
      else if(position == '1'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical01);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '2'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal20);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '3'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical20);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical20);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical20);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '4'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '5'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal21);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '6'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical20);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical20);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical20);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '7'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical21);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
      else if(position == '8'){
        if(logo == '1'){
          //logo one line
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo1);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '2'){
          //logo 2 lines
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo2);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
        else if(logo == '3'){
          //logo 3 lines
          serialport_write(fd,horizontal22);
          serialport_flush(fd);
          serialport_write(fd,vertical22);
          serialport_flush(fd);
          serialport_write(fd,down);
          serialport_flush(fd);
          serialport_write(fd,logo3);
          serialport_flush(fd);
          serialport_write(fd,up);
          serialport_flush(fd);
        }
      }
    }
  }
  else{
    if(win == '1'){
      if(logo == '1'){
          serialport_write(fd,logo1);
          serialport_flush(fd);
      }
    }
  }

  //close the file
  serialport_close(fd);
}

int main (void) {
	//printf("%c\n", position); 
	//printf("%c\n", logo); 
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
	//printf("%c\n", position); 
	//printf("%c\n", logo); 