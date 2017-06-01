/*
** my_socketext.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Sat May 13 17:11:17 2017 debrau_c
** Last update Fri May 19 16:35:39 2017 debrau_c
*/

#include <stdio.h>
#include <string.h>

char	*parse_name(char *buff)
{
  char	*ret;

  ret = NULL;
  if (!strncmp(buff, "USER ", strlen("USER "))
      && strlen(buff) > strlen("USER "))
    {
      if ((ret = strdup(&buff[strlen("USER ")])) == NULL)
	return (NULL);
    }
  return (ret);
}

char	*parse_pass(char *buff)
{
  char	*ret;

  ret = NULL;
  if (!strncmp(buff, "PASS", strlen("PASS") - 1))
    {
      if ((ret = strdup(&buff[strlen("PASS")])) == NULL)
	return (NULL);
    }
  return (ret);
}
