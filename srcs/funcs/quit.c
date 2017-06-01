/*
** quit.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:27:13 2017 debrau_c
** Last update Mon May 15 21:52:16 2017 debrau_c
*/

#include "my_ftp.h"

void	func_quit(t_client *cli, char *line)
{
  (void)line;
  client_write(cli, R_221);
  cli->done = 1;
}
