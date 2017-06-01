/*
** noop.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:28:19 2017 debrau_c
** Last update Fri May 19 16:27:44 2017 debrau_c
*/

#include "my_ftp.h"

void	func_noop(t_client *cli, char *line)
{
  (void)line;
  client_write(cli, "200 NOOP ok."CRLF);
}

