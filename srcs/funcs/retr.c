/*
** retr.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:21:36 2017 debrau_c
** Last update Sun May 21 23:15:24 2017 debrau_c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_ftp.h"

void		func_retr(t_client *cli, char *line)
{
  int		fd;
  char		*data;
  unsigned char	buf[516];
  unsigned int	r;

  if ((data = get_data_from_line(line)) != NULL)
    {
      client_write(cli, R_150);
      if ((fd = open(data, O_RDONLY)) != -1)
	{
	  while ((r = read(fd, &buf, 515)) > 0)
	    {
	      buf[r] = 0;
	      client_write_data(cli, buf);
	    }
	  client_write(cli, R_226);
	  close(fd);
	}
      else
	client_write(cli, R_XXX);
    }
  else
    client_write(cli, R_XXX);
  client_close_data(cli);
  return ;
}
