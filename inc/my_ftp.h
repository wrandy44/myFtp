/*
** myftp.h for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 16:11:20 2017 debrau_c
** Last update Sun May 21 23:20:07 2017 debrau_c
*/

#ifndef MY_FTP_H_
# define MY_FTP_H_

# include <arpa/inet.h>
# include <sys/socket.h>
# include <netdb.h>
# include <ifaddrs.h>
# include <dirent.h>
# define BUFF_SIZE 512
# define CRLF "\r\n"
# define R_120 "120 Service ready in nnn minutes."CRLF
# define R_125 "125 Data connection already open; transfer starting."CRLF
# define R_150 "150 File status okay; about to open data connection."CRLF
# define R_200 "200 Command okay."CRLF
# define R_214 "214 HELP message"CRLF
# define R_215 "215 Unix powa"CRLF
# define R_220 "220 (vsFTPd 3.0.0)"CRLF
# define R_221 "221 Goodbye."CRLF
# define R_226 "226 Closing data connection."CRLF
# define R_227 "227 Entering Passive Mode (%s,%d,%d)."CRLF
# define R_230 "230 Login successful."CRLF
# define R_250 "250 Requested file action okay, completed."CRLF
# define R_257 "257 \"/\" created"CRLF
# define R_331 "331 Please specify the password."CRLF
# define R_332 "332 Need account for login."CRLF
# define R_500 "500 Unknown command."CRLF
# define R_XXX "xxx unrecognized command"CRLF
# define NB_CMD 14

typedef struct	s_client
{
  int		sock;
  int		data_sock;
  char		*name;
  char		*pass;
  char		name_ok;
  char		pass_ok;
  DIR		*dir;
  int		pasv_sock;
  char		passive;
  int		done;
  char		*home;
}		t_client;

typedef struct	host_info
{
  char		address[20];
  short		port;
}		t_host_info;

union		short_byte{
  unsigned short	shorty;
  unsigned char		bytes[2];
};

typedef void	(*fptr)(t_client *, char *);

int		init_passive(unsigned short *port);
int		client_write(t_client *cli, char *s);
int		client_write_data(t_client *cli, void *s);
void		client_close_data(t_client *cli);
t_client	*client_init(int sock);
int		client_read_data(t_client *cli,
				 void *ptr,
				 unsigned int size);
void		client_free(t_client *);
int	client_checkpath(t_client *cli, char *path);
void		client_check_path(t_client *, char *);
int		client_fill_buff(t_client *cli,
				 void *ptr,
				 unsigned int size);
void	func_cwd(t_client *cli, char *line);
void	func_retr(t_client *cli, char *line);
void	func_pwd(t_client *cli, char *line);
void	func_port(t_client *cli, char *line);
void	func_list(t_client *cli, char *line);
void	func_syst(t_client *cli, char *line);
void	func_cdup(t_client *cli, char *line);
void	func_quit(t_client *cli, char *line);
void	func_dele(t_client *cli, char *line);
void	func_help(t_client *cli, char *line);
void	func_noop(t_client *cli, char *line);
void	func_stor(t_client *cli, char *line);
void	func_pasv(t_client *cli, char *line);
void	func_mkd(t_client *cli, char *line);
int	init_socket(unsigned int port);
int	client_open_data(t_client *cli,
			 t_host_info myHostInf);
void		get_host_info_name(t_host_info *info, char **tab);
void		get_host_info_port(t_host_info *info, char **tab);
t_host_info	get_host_info_by_line(char *line);
void	get_cmd(char *cmd, char *buff);
void	modify_to_crlf(char *s);
int	go_function(t_client *cli, char *command, char *line);
char	*parse_pass(char *buff);
int	authentify(t_client *cli, char *buffer, char *);
char	*parse_name(char *buff);
char		*get_data_from_line(const char *line);
void	func_cmd_init(char (*cmd)[NB_CMD][20]);
int	main_checker(int argc, char** argv);

#endif /* !MY_FTP_H_ */
