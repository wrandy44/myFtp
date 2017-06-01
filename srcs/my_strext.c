/*
** my_strext.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 16:18:28 2017 debrau_c
** Last update Tue May 16 00:41:06 2017 debrau_c
*/

#include <string.h>

void		str_replaceall(char *s, char old, char new)
{
  unsigned int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == old)
	s[i] = new;
      i++;
    }
}

unsigned int	strfindchar(const char *line, char c)
{
  unsigned int	i;

  i = 0;
  while (line[i] && line[i] != c)
    i++;
  return (i);
}

void	revstr(char *s)
{
  int	max;
  int	i;
  char	tmp;

  i = 0;
  max = strlen(s);
  if (max < 2)
    return ;
  max--;
  while (i < max)
    {
      tmp = s[i];
      s[i] = s[max];
      s[max] = tmp;
      max--;
      i++;
    }
}
