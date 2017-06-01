/*
** check_path.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Sat May 20 22:30:27 2017 debrau_c
** Last update Sat May 20 22:32:10 2017 debrau_c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_ftp.h"

static void	delete_last_dir(char *str)
{
  int	i;

  i = strlen(str) - 1;
  while (i >= 0 && str[i] != '/')
    {
      str[i] = '\0';
      i--;
    }
  if (i != -1)
    str[i] = 0;
}

int	client_checkpath(t_client *cli, char *path)
{
  char	cwd[1024];

  if (!getcwd(cwd, 1024))
    return (-1);
  if (strlen(path) > 200 && strlen(path) > 0) return (-1);
  if (strlen(path) == 2 && path[0] == '.' && path[1] == '.')
    {
      delete_last_dir(cwd);
      printf("CHECKPATH : [%s][%s]\n*******\n", cwd, cli->home);
      return (strncmp(cli->home, cwd, strlen(cli->home) -1));
    }
  if (path[0] != '/')
    {
      if (strlen(path) + strlen(cwd) > 1000)
	return (-1);
      strcat(cwd, path);
      return (strncmp(cli->home, cwd, strlen(cli->home) -1));
    }
  return (strncmp(cli->home, path, strlen(cli->home) -1));
}
