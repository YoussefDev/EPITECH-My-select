/*
** list_func.c for my_select in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_my_select
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Sat Dec 20 16:33:16 2014 Youssef Sayyouri
** Last update Sun Jan 11 15:53:51 2015 Youssef Sayyouri
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include "include/my_select.h"

t_list		*create_list()
{
  t_list	*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->next = root;
    }
  return root;
}

int		add_on_top(t_list *list, char *str)
{
  t_list	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (-1);
  else
    {
      elem->str = str;
      elem->selected = 0;
      elem->cursor = 0;
      elem->prev = list->prev;
      elem->next = list;
      list->prev->next = elem;
      list->prev = elem;
      return (0);
    }
}

void		show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, my_puts);
  while (tmp != list)
    {
      if (tmp->cursor == 1)
	tputs(tgetstr("us", NULL), 0, my_puts);
      if (tmp->selected == 1)
	tputs(tgetstr("mr", NULL), 0, my_puts);
      my_putstr(tmp->str);
      if (tmp->cursor == 1)
	tputs(tgetstr("ue", NULL), 0, my_puts);
      if (tmp->selected == 1)
	tputs(tgetstr("me", NULL), 0, my_puts);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int		list_len(t_list *list)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      tmp = tmp->next;
      i++;
    }
  return i;
}

void		list_free(t_list **list)
{
  t_list	*tmp;
  t_list	*nxt;

  tmp = (*list)->next;
  while (tmp != (*list))
    {
      nxt = tmp->next;
      free(tmp);
      tmp = nxt;
    }
  free(*list), *list = NULL;
}

