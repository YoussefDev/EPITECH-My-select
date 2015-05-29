/*
** main.c for my_select in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_my_select
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Tue Dec 16 16:33:21 2014 Youssef Sayyouri
** Last update Sun Jan 11 15:42:55 2015 Youssef Sayyouri
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include "include/my_select.h"

int			main(int ac, char **av)
{
  t_list		*list;
  t_list		*tmp;
  struct termios	t;
  struct termios	old;

  list = create_list();
  if (tcgetattr(0, &t) == -1)
    {
      my_putstr("Error: tcgetattr failed");
      return (0);
    }
  old = t;
  if (manage_arg(ac, av, list) == -1)
    return (0);
  if (screen_clear() == -1)
    return (0);
  if (raw_mode(&t) == -1)
    return (0);
  tmp = list->next;
  tmp->cursor = 1;
  my_select(list, old);
  list_free(&list);
  return (0);
}

int			my_select(t_list *list, struct termios old)
{
  int			i;
  char			buff[2];

  i = 0;
  while (i < 1)
    {
      screen_clear();
      buff[0] = 0;
      buff[1] = 0;
      buff[2] = 0;
      show_list(list);
      if (read(0, buff, 3) == -1)
	{
	  my_putstr("Error: read failled");
	  return (0);
	}
      else
	if (get_buff(buff, &i, list, old) == -1)
	  return (0);
    }
  if (i == 2)
    show_selected(list);
  return (0);
}

void			del_elem(t_list *list)
{
  list->prev->next = list->next;
  list->next->prev = list->prev;
  free(list);
}

void			show_selected(t_list *list)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list->next;
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_puts);
  while (tmp != list)
    {
      if (tmp->selected == 1)
	{
	  my_putstr(tmp->str);
	  my_putchar(' ');
	  i++;
	}
      tmp = tmp->next;
    }
  if (i > 0)
    my_putchar('\n');
}
