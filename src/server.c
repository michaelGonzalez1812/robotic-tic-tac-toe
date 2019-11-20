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
  const char* serialport = "/dev/ttyACM0";
  //baudio
  int baud = 9600;
  //file descriptor
  int fd = -1;
  //string to write
  const char* str = malloc(500);
  const char* final = "\n\t";


  //string to concatenate
  //lvl 2
  const char* horizontal22 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
  const char* horizontal21 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
  const char* horizontal20 = "wwwwwwww";
  const char* vertical22 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  const char* vertical21 = "a";
  const char* vertical20 = "ddddddddddddddddddddddddddddd";

  //lvl 1
  const char* horizontal12 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
  const char* horizontal11 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
  const char* horizontal10 = "wwwwwwwwwwwwwwwwwwwww";
  const char* vertical12 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  const char* vertical11 = "aaaaaaaaa";
  const char* vertical10 = "dddddddddddddddddddddddd";

  //lvl 0
  const char* horizontal02 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
  const char* horizontal01 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
  const char* horizontal00 = "wwwwwwwwwwwwwwwwwwwwwwwwwww";
  const char* vertical02 = "aaaaaaaaaaaaaaaaaaaaaa";
  const char* vertical01 = "aaaaaaa";
  const char* vertical00 = "ddddddddd";

  //logo0
  const char* logo1 = "sssssssssss";
  //logo1
  const char* logo2 = "aaaaaaaaaaaaaaa";
  //logo2
  const char* logo3 = "sssssssssssaaaaaaaaaaa";

  //pencil down
  const char* down = "ooooooooooooo";

  //pencil up
  const char* up = "lllllll";

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
          strcpy(str,horizontal00);
          strcpy(str,vertical00);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal00);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal00);
          strcpy(str,vertical00);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          printf("%s/n",str);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '1'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal00);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal00);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal00);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '2'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal00);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal00);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal00);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '3'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal01);
          strcpy(str,vertical00);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal01);
          strcpy(str,vertical00);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal01);
          strcpy(str,vertical00);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '4'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal01);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal01);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal01);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '5'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal01);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal01);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal01);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '6'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal02);
          strcpy(str,vertical00);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal02);
          strcpy(str,vertical00);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal02);
          strcpy(str,vertical00);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '7'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal02);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal02);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal02);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '8'){
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal02);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal02);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal02);
          strcpy(str,vertical02);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
    }
    else if(size == '1'){
      if(position == '0'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal10);
          strcpy(str,vertical10);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal10);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal10);
          strcpy(str,vertical10);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '1'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal10);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal10);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal10);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '2'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal10);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal10);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal10);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '3'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal11);
          strcpy(str,vertical10);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal11);
          strcpy(str,vertical10);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal11);
          strcpy(str,vertical10);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '4'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal11);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal11);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal11);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '5'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal11);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal11);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal11);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '6'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal12);
          strcpy(str,vertical10);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal12);
          strcpy(str,vertical10);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal12);
          strcpy(str,vertical10);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '7'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal12);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal12);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal12);
          strcpy(str,vertical11);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '8'){
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal12);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal12);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal12);
          strcpy(str,vertical12);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
    }
    else if(size == '2'){
      if(position == '0'){
       if(position == '0'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal20);
          strcpy(str,vertical20);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal20);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal20);
          strcpy(str,vertical20);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        }
      }
      else if(position == '1'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal20);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal20);
          strcpy(str,vertical01);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal20);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '2'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal20);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal20);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal20);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '3'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal21);
          strcpy(str,vertical20);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal21);
          strcpy(str,vertical20);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal21);
          strcpy(str,vertical20);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '4'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal21);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal21);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal21);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '5'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal21);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal21);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal21);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '6'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal22);
          strcpy(str,vertical20);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal22);
          strcpy(str,vertical20);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal22);
          strcpy(str,vertical20);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '7'){
        //write to de fie
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal22);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal22);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal22);
          strcpy(str,vertical21);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
      else if(position == '8'){
        if(logo == '1'){
          //logo one line
          strcpy(str,horizontal22);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo1);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '2'){
          //logo 2 lines
          strcpy(str,horizontal22);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo2);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
        else if(logo == '3'){
          //logo 3 lines
          strcpy(str,horizontal22);
          strcpy(str,vertical22);
          strcpy(str,down);
          strcpy(str,logo3);
          strcpy(str,up);
          strcpy(str,final);
          serialport_write(fd,str);
          str = "";
        }
      }
    }
  }
  else{
    if(win == '1'){
      str = "";
    }
    else{
      str = "";
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