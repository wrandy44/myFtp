/*
** main_checker.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Sat May 20 19:25:19 2017 debrau_c
** Last update Sat May 20 19:29:32 2017 debrau_c
*/

#include <stdio.h>
#include "my_ftp.h"

int			usage(char *binname)
{
  printf("Usage : %s port path\n", binname);
  return (0);
}

int			check_path(char *path)
{
  DIR	*del;

  if ((del = opendir(path)) != NULL)
    closedir(del);
  return (!del);
}

int	main_checker(int argc, char** argv)
{
  if (argc != 3)
    return (usage(argv[0]), 1);
  if (check_path(argv[2]))
    return (printf("Directory not exist\n"), 1);
  return (0);
}
