/*
** my_str.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 14:17:55 2017 debrau_c
** Last update Fri May 12 19:23:48 2017 debrau_c
*/

#include <stdlib.h>

unsigned int	strcharpos(const char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\r' && str[i + 1] == '\n')
	return (i);
      i++;
    }
  return (i);
}

unsigned int	str_count_char(const char *s, char c)
{
  unsigned int	i;
  unsigned int	nb;

  nb = 0;
  i = -1;
  while (s[++i])
    if (s[i] == c)
      nb++;
  return (nb);
}

unsigned int	strclen(const char *s, char c)
{
  unsigned int	i;

  i = 0;
  while (s[i] && s[i] != c)
    i++;
  return (i);
}

char		*strcdup(const char *s, char c)
{
  char		*res;
  unsigned int	i;

  i = 0;
  if ((res = malloc(strclen(s, c) + 1)) == NULL)
    return (NULL);
  while (s[i] && s[i] != c)
    {
      res[i] = s[i];
      i++;
    }
  res[i] = 0;
  return (res);
}

