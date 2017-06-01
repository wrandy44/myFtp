/*
** my_tab.h for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/Server
** 
** Made by debrau_c
** Login   <carl.debrauwere@epitech.eu>
** 
** Started on  Fri May 12 16:00:04 2017 debrau_c
** Last update Fri May 12 17:42:39 2017 debrau_c
*/

#ifndef MY_TAB_H_
# define MY_TAB_H_

char            **tab_from_str(char *s, char delim);
void            tab_free(char **s);
unsigned int	tab_size(char **t);

#endif /* !MY_TAB_H_ */
