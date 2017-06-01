/*
** pwd.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:31:38 2017 debrau_c
** Last update Sun May 21 10:56:51 2017 debrau_c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my_ftp.h"

void	func_pwd(t_client *cli, char *line)
{
  char cwd[1024];

  (void)line;
  getcwd(cwd, sizeof(cwd));
  client_write(cli, "257 \"");
  if (strlen(&cwd[strlen(cli->home)]) == 0)
    client_write(cli, "/");
  else
    client_write(cli, &cwd[strlen(cli->home)]);
  client_write(cli, "\"");
  client_write(cli, CRLF);
}
