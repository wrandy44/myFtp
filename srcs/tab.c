/*
** tab.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 14:19:03 2017 debrau_c
** Last update Tue May 16 00:42:08 2017 debrau_c
*/

#include <stdlib.h>
#include "my_str.h"

char		**tab_from_str(char *s, char delim)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	nb_tab;
  char		**res;

  i = j = 0;
  nb_tab = str_count_char(s, delim) + 2;
  if ((res = malloc(sizeof(char *) * (nb_tab))) == NULL)
    return (NULL);
  while (s[i])
    {
      if (s[i] == delim || i == 0)
	{
	  if (i != 0 && (res[j] = strcdup(&s[i + 1], delim)) == NULL)
	    return (NULL);
	  else if (i == 0 && (res[j] = strcdup(&s[i], delim)) == NULL)
	    return (NULL);
	  j++;
	}
      i++;
    }
  res[j] = NULL;
  return (res);
}

void		tab_free(char **s)
{
  unsigned int	i;

  i = 0;
  while (s[i])
    {
      free(s[i]);
      i++;
    }
  free(s);
}

unsigned int	tab_size(char **t)
{
  unsigned int	i;

  i = 0;
  while (t[i])
    i++;
  return (i);
}
