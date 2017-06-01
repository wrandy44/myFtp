/*
** port.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:31:50 2017 debrau_c
** Last update Sat May 20 16:25:15 2017 debrau_c
*/

#include <stdio.h>
#include "my_ftp.h"

void	func_port(t_client *cli, char *line)
{
  if (client_open_data(cli, get_host_info_by_line(line)) < 0)
    client_write(cli, "500 Illegal PORT command."CRLF);
  else
    client_write(cli, R_200);
}
