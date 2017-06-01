/*
** dele.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:31:07 2017 debrau_c
** Last update Mon May 15 21:34:56 2017 debrau_c
*/

#include <stdio.h>
#include "my_ftp.h"

void	func_dele(t_client *cli, char *line)
{
  char	*data;

  if (!(data = get_data_from_line(line)))
    {
      client_write(cli, R_XXX);
      return;
    }
  if (!remove(data))
    client_write(cli, R_250);
  else
    client_write(cli, R_XXX);
}

