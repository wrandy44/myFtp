/*
** stor.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:22:26 2017 debrau_c
** Last update Sun May 21 23:29:20 2017 debrau_c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_ftp.h"

void		func_stor(t_client *cli, char *line)
{
  int		fd;
  char		*data;
  char		c;
  unsigned int	r;

  if ((data = get_data_from_line(line)) != NULL)
    {
      client_write(cli, R_150);
      if ((fd = open(data, O_WRONLY | O_CREAT, 0666)) != -1)
	{
	  while ((r = client_read_data(cli, &c, 1)) > 0)
	    write(fd, &c, 1);
	  client_write(cli, R_226);
	  close(fd);
	}
    }
  else
    client_write(cli, R_XXX);
  client_close_data(cli);
  return ;
}
