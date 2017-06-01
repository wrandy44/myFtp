/*
** clientext.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Sat May 20 19:23:20 2017 debrau_c
** Last update Sun May 21 23:26:19 2017 debrau_c
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_ftp.h"

unsigned int	my_ustrlen(void *str)
{
  char		*p;
  unsigned int	i;

  p = (char *)str;
  i = 0;
  while (p[i])
    i++;
  return (i);
}

int		client_write(t_client *cli, char *s)
{
  return (write(cli->sock, s, strlen(s)));
}

int		client_write_data(t_client *cli, void *s)
{
  unsigned char	*str;
  unsigned int	i;

  str = (unsigned char *)s;
  i = 0;
  while (str[i])
    {
      if (str[i] != '\r' && str[i + 1] != '\n')
	{
	  if (write(cli->data_sock, &str[i], 1) == 0)
	    return (-1);
	}
      else{
	if (write(cli->data_sock, "\n", 1) == 0)
	  return (-1);
	i++;
      }
      i++;
    }
  return (1);
}

int		client_read_data(t_client *cli,
				 void *ptr,
				 unsigned int size)
{
  return (read(cli->data_sock, ptr, size));
}
