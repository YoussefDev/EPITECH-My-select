/*
** list_control.c for my_select in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_my_select
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Sat Jan 10 15:00:42 2015 Youssef Sayyouri
** Last update Sun Jan 11 15:53:20 2015 Youssef Sayyouri
*/

#include "include/my_select.h"

int		get_buff(char buff[2], int *i, t_list *list, struct termios old)
{
  if (list_len(list) < 1)
    {
      *i = 1;
      set_backup(&old);
      return (0);
    }
  if ((buff[0] == 10 && buff[1] == 0 && buff[2] == 0) ||
      (buff[0] == 27 && buff[1] == 0 && buff[2] == 0))
    {
      *i = (buff[0] == 27 && buff[1] == 0 && buff[2] == 0) ? 1 : 2;
      screen_clear();
      if (set_backup(&old) == -1)
	return (-1);
    }
  else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
    arrow_top(list);
  else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
    arrow_bottom(list);
  else if (buff[0] == 32 && buff[1] == 0 && buff[2] == 0)
    key_space(list);
  else if (buff[0] == 127 && buff[1] == 0 && buff[2] == 0)
    del_key(list);
  else if (buff[0] == 27 && buff[1]== 91 && buff[2] == 51)
    del_key(list);
  return (0);
}

void		key_space(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp && tmp->cursor == 0)
    tmp = tmp->next;
  if (tmp->selected == 0)
    {
      tmp->selected = 1;
      if (tmp->next != list)
	tmp->next->cursor = 1;
      else
	tmp->next->next->cursor = 1;
      tmp->cursor = 0;
    }
  else if (tmp->selected == 1)
    tmp->selected = 0;
}

void		del_key(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  while (tmp && tmp->cursor == 0)
    tmp = tmp->next;
  if (tmp->next != list)
    tmp->next->cursor = 1;
  else
    tmp->next->next->cursor = 1;
  del_elem(tmp);
}

void		arrow_bottom(t_list *list)
{
  t_list        *tmp;

  if (list_len(list) != 1)
    {
      tmp = list->next;
      while (tmp && tmp->cursor == 0)
	tmp = tmp->next;
      if (tmp->prev != list)
	tmp->prev->cursor = 1;
      else
	tmp->prev->prev->cursor = 1;
      tmp->cursor = 0;
    }
}

void	arrow_top(t_list *list)
{
  t_list        *tmp;

  if (list_len(list) != 1)
    {
      tmp = list->next;
      while (tmp && tmp->cursor == 0)
	tmp = tmp->next;
      if (tmp->next != list)
	tmp->next->cursor = 1;
      else
	tmp->next->next->cursor = 1;
      tmp->cursor = 0;
    }
}
