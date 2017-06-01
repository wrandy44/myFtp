/*
** help.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:27:30 2017 debrau_c
** Last update Mon May 15 21:27:45 2017 debrau_c
*/

#include "my_ftp.h"

void	func_help(t_client *cli, char *line)
{
  char	cmd[NB_CMD][20];
  unsigned int	i;

  (void)line;
  func_cmd_init(&(cmd));
  client_write(cli, "214-The following commands are recognized.\n");
  i = 0;
  client_write(cli, "USER\tPASS\t");
  while (i < NB_CMD)
    {
      client_write(cli, cmd[i]);
      client_write(cli, "\t");
      i++;
    }
  client_write(cli, "\n");
  client_write(cli, R_214);
}
