/*
** syst.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:20:59 2017 debrau_c
** Last update Mon May 15 21:21:10 2017 debrau_c
*/

#include "my_ftp.h"

void	func_syst(t_client *cli, char *line)
{
  (void)line;
  client_write(cli, R_215);
}
