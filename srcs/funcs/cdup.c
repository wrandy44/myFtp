/*
** cdup.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:22:43 2017 debrau_c
** Last update Sat May 20 22:04:37 2017 debrau_c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my_ftp.h"

static void	rm_last_dir(char *str)
{
  int		i;

  i = strlen(str) - 1;
  while (i >= 0 && str[i] != '/')
    {
      str[i] = '\0';
      i--;
    }
  str[i] = '\0';
}

void	func_cdup(t_client *cli, char *line)
{
  char	cwd[1024];

  (void)line;
  getcwd(cwd, sizeof(cwd));
  rm_last_dir(cwd);
  if (strncmp(cli->home, cwd, strlen(cli->home)) == 0)
    {
      chdir("..");
      client_write(cli, "250 Directory successfully changed."CRLF);
    }
  else
    client_write(cli, "250 Directory successfully changed."CRLF);
}

