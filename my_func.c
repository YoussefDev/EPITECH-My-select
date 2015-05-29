/*
** my_func.c for my_select in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_my_select
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Fri Jan  9 16:39:02 2015 Youssef Sayyouri
** Last update Sun Jan 11 15:54:10 2015 Youssef Sayyouri
*/

#include <unistd.h>
#include "include/my_select.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_puts(int c)
{
  write(1, &c, 1);
  return (0);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	{
	  my_putchar(str[i]);
	  i++;
	}
    }
  else
    my_putstr("Error: Null value is prohibited");
}

int	manage_arg(int ac, char **av, t_list *list)
{
  int	i;

  i = 1;
  if (ac < 2)
    {
      my_putstr("usage: ");
      my_putstr(av[0]);
      my_putstr(" [string] [string] [...]\n");
      return (-1);
    }
  while (av[i] != NULL)
    {
      add_on_top(list, av[i]);
      i++;
    }
  return (0);
}
