/*
** main.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
**
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
**
** Started on  Thu May 11 16:22:48 2017 debrau_c
** Last update Sat May 20 22:24:07 2017 debrau_c
*/

#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_str.h"
#include "my_tab.h"
#include "my_ftp.h"

void	parse_cmd(t_client *cli, char *buff)
{
  char	cmd[30];

  modify_to_crlf(buff);
  get_cmd(cmd, buff);
  if (!go_function(cli, cmd, buff))
    client_write(cli, R_500);
}

void		go_fork(t_client *client, char *home)
{
  unsigned int	pid;
  char		buffer[BUFF_SIZE];

  pid = fork();
  if (pid == 0)
    {
      while (!client->done)
	{
	  if (client_fill_buff(client, &buffer, BUFF_SIZE) < 0)
	    return ;
	  authentify(client, buffer, home);
	  while (client->pass_ok && client->name_ok && !client->done)
	    {
	      if (client_fill_buff(client, &buffer, BUFF_SIZE) < 0)
		return ;
	      parse_cmd(client, buffer);
	    }
	}
      client_free(client);
      exit(0);
    }
}

int			main(int argc, char **argv)
{
  int			socket;
  struct sockaddr_in	adr;
  int			ads;
  int			new_fd;
  t_client		*new_client;

  bzero(&adr, sizeof(struct sockaddr_in));
  bzero(&ads, sizeof(socklen_t));
  if (main_checker(argc, argv)
      || (socket = init_socket(atoi(argv[1]))) < 0)
    return (1);
  while (1)
    {
      new_fd = accept(socket, (struct sockaddr*)&adr, (socklen_t*)(&ads));
      if (new_fd != 0)
	{
	  if ((new_client = client_init(new_fd)) == NULL)
	    return (1);
	  write(new_fd, R_220, strlen(R_220));
	  go_fork(new_client, argv[2]);
	  close(new_fd);
	}
    }
  close(socket);
  return (0);
}
