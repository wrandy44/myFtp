/*
** cwd.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:31:24 2017 debrau_c
** Last update Sat May 20 22:17:16 2017 debrau_c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_ftp.h"

void	func_cwd(t_client *cli, char *line)
{
  char	*data;

  if (!(data = get_data_from_line(line)))
    {
      client_write(cli, "550 Failed to change directory."CRLF);
      return;
    }
  if (client_checkpath(cli, data) != 0)
    client_write(cli, "550 Failed to change directory."CRLF);
  else if (chdir(data) < 0)
    client_write(cli, "550 Failed to change directory."CRLF);
  else
    client_write(cli, "250 Directory successfully changed."CRLF);
  free(data);
}
