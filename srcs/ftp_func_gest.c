/*
** ftp_func_gest.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 16:26:44 2017 debrau_c
** Last update Fri May 19 15:48:40 2017 debrau_c
*/

#include <stdio.h>
#include <string.h>
#include "my_ftp.h"
#include "my_str.h"

void	func_cmd_init(char (*cmd)[NB_CMD][20])
{
  strcpy(cmd[0][0], "CWD");
  strcpy(cmd[0][1], "CDUP");
  strcpy(cmd[0][2], "QUIT");
  strcpy(cmd[0][3], "DELE");
  strcpy(cmd[0][4], "PWD");
  strcpy(cmd[0][5], "PORT");
  strcpy(cmd[0][6], "LIST");
  strcpy(cmd[0][7], "SYST");
  strcpy(cmd[0][8], "RETR");
  strcpy(cmd[0][9], "HELP");
  strcpy(cmd[0][10], "STOR");
  strcpy(cmd[0][11], "PASV");
  strcpy(cmd[0][12], "MKD");
  strcpy(cmd[0][13], "NOOP");
}

void	func_fptr_init(fptr (*funcs)[NB_CMD])
{
  (*funcs)[0] = func_cwd;
  (*funcs)[1] = func_cdup;
  (*funcs)[2] = func_quit;
  (*funcs)[3] = func_dele;
  (*funcs)[4] = func_pwd;
  (*funcs)[5] = func_port;
  (*funcs)[6] = func_list;
  (*funcs)[7] = func_syst;
  (*funcs)[8] = func_retr;
  (*funcs)[9] = func_help;
  (*funcs)[10] = func_stor;
  (*funcs)[11] = func_pasv;
  (*funcs)[12] = func_mkd;
  (*funcs)[13] = func_noop;
}

int	go_function(t_client *cli, char *command, char *line)
{
  char	cmd[NB_CMD][20];
  fptr	funcs[NB_CMD];
  unsigned int	i;

  func_cmd_init(&(cmd));
  func_fptr_init(&(funcs));
  i = -1;
  while (++i < NB_CMD)
    {
      if (!strcmp(cmd[i], command))
	{
	  funcs[i](cli, line);
	  return (1);
	}
    }
  return (0);
}

char		*get_data_from_line(const char *line)
{
  char		*ret;
  unsigned int	pos;

  ret = NULL;
  if ((pos = strfindchar(line, ' ')) != strlen(line))
    ret = strcdup(&line[pos + 1], '\r');
  return (ret);
}
