/*
** list.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:18:40 2017 debrau_c
** Last update Sun May 21 11:34:33 2017 debrau_c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_ftp.h"

void	func_list(t_client *cli, char *line)
{
  struct dirent *pp;

  (void)line;
  if (cli->dir != NULL)
    free(cli->dir);
  if (!(cli->dir = opendir("./")))
    return ;
  client_write(cli, R_150);
  if (cli->dir != NULL)
    {
      while ((pp = readdir (cli->dir))!=NULL)
	{
	  client_write_data(cli, pp->d_name);
	  client_write_data(cli, CRLF);
	}
      rewinddir(cli->dir);
    }
  client_write(cli, R_226);
  client_close_data(cli);
}
