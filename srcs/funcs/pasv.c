/*
** pasv.c for azd in /home/debrau_c/cours/psu/PSU_2016_myftp
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Mon May 15 21:28:50 2017 debrau_c
** Last update Sat May 20 22:25:34 2017 debrau_c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "my_ftp.h"
#include "my_str.h"

static int	get_ip(char host[NI_MAXHOST])
{
  struct ifaddrs *ifaddr;
  struct ifaddrs *ifa;
  int s;

  if (getifaddrs(&ifaddr) != -1)
    {
      ifa = ifaddr;
      while (ifa != NULL)
	{
	  s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
			  host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
	  if (ifa->ifa_addr->sa_family == AF_INET)
	    {
	      if (s != 0)
		return (0);
	      if (strcmp(host, "127.0.0.1"))
		return (0);
	    }
	  ifa = ifa->ifa_next;
	}
      freeifaddrs(ifaddr);
    }
  return (1);
}

static int		pasv_thread(t_client *cli, union short_byte port)
{
  char			host[NI_MAXHOST];
  char			pasv_string[200];
  struct sockaddr_in	adr;
  int			ads;

  bzero(&adr, sizeof(struct sockaddr_in));
  bzero(&ads, sizeof(socklen_t));
  get_ip(host);
  str_replaceall(host, '.', ',');
  sprintf(pasv_string, R_227, host, port.bytes[1], port.bytes[0]);
  client_write(cli, pasv_string);
  cli->data_sock = accept(cli->pasv_sock,
			  (struct sockaddr*)&adr,
			  (socklen_t*)(&ads));
  return cli->data_sock;
}

void			func_pasv(t_client *cli, char *line)
{
  union short_byte	port;

  (void)line;
  if ((cli->pasv_sock = init_passive(&port.shorty)) != -1)
    pasv_thread(cli, port);
  else
    client_write(cli, R_XXX);
}
