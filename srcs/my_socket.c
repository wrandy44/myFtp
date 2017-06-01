/*
** socket.c for zad in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 14:23:18 2017 debrau_c
** Last update Sun May 21 11:36:18 2017 debrau_c
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_ftp.h"

int			init_socket(unsigned int port)
{
  int			sock;
  struct protoent	*pe;
  struct sockaddr_in	addr;

  pe = getprotobyname("TCP");
  if ((sock = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);
  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    return (-1);
  if (listen(sock, 10) == -1)
    return (-1);
  return (sock);
}

int	client_open_data(t_client *cli,
			 t_host_info myHostInf)
{
  struct protoent       *pe;
  struct sockaddr_in    sin;
  struct hostent        *hostinfo;

  pe = getprotobyname("TCP");
  if ((cli->data_sock = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  if (!(hostinfo = gethostbyname(myHostInf.address)))
    return (-1);
  sin.sin_addr = *(struct in_addr *) hostinfo->h_addr_list[0];
  sin.sin_port = htons(myHostInf.port);
  sin.sin_family = AF_INET;
  if (connect(cli->data_sock,
	      (struct sockaddr *)&sin,
	      sizeof(struct sockaddr_in)) < 0)
    {
      client_write(cli, "500 Illegal PORT command."CRLF);
      return (-1);
    }
  return (cli->data_sock);
}

int	client_open_directory(t_client *cli, char *home)
{
  char	cwd[1024];

  if (cli->home != NULL)
    free(cli->home);
  if (!(cli->dir = opendir(home))
      || chdir(home) < 0
      || !getcwd(cwd, sizeof(cwd))
      || (cli->home = strdup(cwd)) == NULL)
    return (1);
  return (0);
}

int	authentify(t_client *cli, char *buffer, char *home)
{
  if (!cli->name_ok)
    {
      if ((cli->name = parse_name(buffer)) == NULL)
	return (1);
      if (write(cli->sock, R_331, strlen(R_331)) < 0)
	return (1);
      cli->name_ok = 1;
    }
  else if (!cli->pass_ok)
    {
      if ((cli->pass = parse_pass(buffer)) == NULL)
	return (1);
      if (write(cli->sock, R_230, strlen(R_230)) < 0
	  || client_open_directory(cli, home))
	return (1);
      cli->pass_ok = 1;
    }
  return (0);
}

int			init_passive(unsigned short *port)
{
  int			sock;
  struct protoent	*pe;
  struct sockaddr_in	addr;

  if (!(pe = getprotobyname("TCP"))
      || (sock = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  *port = 2000;
  addr.sin_port = htons(*port);
  while (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0
	 && *port != 9000)
    {
      *port = *port + 1;
      addr.sin_port = htons(*port);
    }
  if (*port == 9000 || listen(sock, 1) < 0)
    return (-1);
  return (sock);
}
