/*
** mkd.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Tue May 16 13:26:18 2017 debrau_c
** Last update Tue May 16 14:54:24 2017 debrau_c
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_ftp.h"

void	func_mkd(t_client *cli, char *line)
{
  char	*data;

  if ((data = get_data_from_line(line)) == NULL)
    return ;
  if (client_checkpath(cli, data))
    {
      mkdir(data, 0755);
      client_write(cli, R_257);
    }
  else
    {
      client_write(cli, R_XXX);
    }

  free(data);
}
