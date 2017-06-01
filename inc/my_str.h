/*
** my_str.h for zazzd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 14:22:04 2017 debrau_c
** Last update Sat May 13 13:40:55 2017 debrau_c
*/

#ifndef MY_STR_H_
# define MY_STR_H_

unsigned int	strcharpos(const char *str);
unsigned int	str_count_char(const char *s, char c);
unsigned int	strclen(const char *s, char c);
char		*strcdup(const char *s, char c);
unsigned int	strfindchar(const char *line, char c);
void		str_replaceall(char *s, char old, char new);

#endif /* !MY_STR_H_ */
