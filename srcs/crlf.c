/*
** crlf.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 16:17:14 2017 debrau_c
** Last update Sun May 21 11:19:47 2017 debrau_c
*/

#include <stdlib.h>
#include <string.h>
#include "my_tab.h"
#include "my_str.h"
#include "my_ftp.h"

void		get_host_info_name(t_host_info *info, char **tab)
{
  unsigned int	i;

  i = 0;
  if (tab_size(tab) == 6)
    {
      info->address[0] = 0;
      while (tab[i] && i < 4)
	{
	  strcat(info->address, tab[i]);
	  if (i != 3)
	    strcat(info->address, ".");
	  i++;
	}
    }
}

void		get_host_info_port(t_host_info *info, char **tab)
{
  int		a;
  int		b;

  info->port = 0;
  if (tab_size(tab) == 6)
    {
      a = atoi(tab[4]);
      b = atoi(tab[5]);
      info->port = (((short)a) << 8) | b;
    }
}

t_host_info	get_host_info_by_line(char *line)
{
  t_host_info	info;
  unsigned int	posSpace;
  char		**tab;

  info.address[0] = 0;
  info.port = 0;
  posSpace = strfindchar(line, ' ') + 1;
  if ((tab = tab_from_str(&line[posSpace], ',')) == NULL)
    return (info);
  get_host_info_name(&info, tab);
  get_host_info_port(&info, tab);
  tab_free(tab);
  return (info);
}

void	modify_to_crlf(char *s)
{
  unsigned int	pos;

  pos = strcharpos(s);
  s[pos] = 0;
}

void	get_cmd(char *cmd, char *buff)
{
  unsigned int	i;

  i = 0;
  while (buff[i] && buff[i] != ' ' && i < 30)
    {
      cmd[i] = buff[i];
      i++;
    }
  cmd[i] = 0;
}

