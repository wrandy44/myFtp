/*
** client.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 14:19:51 2017 debrau_c
** Last update Sun May 21 11:38:26 2017 debrau_c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_ftp.h"

int		client_fill_buff(t_client *cli,void *ptr, unsigned int size)
{
  int		r;
  char		*str;
  char		c;
  unsigned int	i;
  char		back_r;
  char		back_n;

  str = (char *)ptr;
  if (!size) return (size);
  str[0] = i = back_r = back_n = 0;
  while ((r = read(cli->sock, &c, 1)) > 0 && !back_r && !back_n && i < size - 1)
    {
      if (c != '\r' && c != '\n' && !(back_r = 0) && !(back_n = 0))
	{
	  str[i] = c;
	  i++;
	}
      else if (c == '\r') back_r = 1;
      else if (c == '\n') back_n = 1;
    }
  if (r < 0 || (r == 0 && i == 0))
    return (-1);
  return (str[i] = '\0', i);
}

void		client_close_data(t_client *cli)
{
  close(cli->data_sock);
  cli->data_sock = -1;
}

t_client	*client_init(int sock)
{
  t_client	*ret;

  if ((ret = malloc(sizeof(t_client))) == NULL)
    return (NULL);
  ret->name_ok = 0;
  ret->pass_ok = 0;
  ret->sock = sock;
  ret->done = 0;
  ret->name = NULL;
  ret->pass = NULL;
  ret->dir = NULL;
  ret->home = NULL;
  return (ret);
}

void	client_free(t_client *cli)
{
  free(cli->pass);
  free(cli->name);
  closedir(cli->dir);
  close(cli->sock);
  free(cli->home);
  free(cli);
}
