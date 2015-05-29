/*
** term_opt.c for my_select in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_my_select
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Wed Jan  7 17:03:27 2015 Youssef Sayyouri
** Last update Wed Jan 21 14:13:42 2015 Youssef Sayyouri
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include "include/my_select.h"

int	raw_mode(struct termios *t)
{
  tputs(tgetstr("vi", NULL), 0, my_puts);
  t->c_lflag &= ~ICANON;
  t->c_lflag &= ~ECHO;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, t) == -1)
    {
      my_putstr("Error: tcsetattr failed (raw_mode)");
      return (-1);
    }
  return (0);
}

int	set_backup(struct termios *t)
{
  tputs(tgetstr("ve", NULL), 0, my_puts);
  if (tcsetattr(0, TCSANOW, t) == -1)
    {
      my_putstr("Error: tcsetattr failed (set_backup)");
      return (-1);
    }
  return (0);
}

int	screen_clear()
{
  if (tgetent(0, "xterm") != 1)
    {
      my_putstr("No such entry or terminfo database coud not be found\n");
      return (-1);
    }
  else
    {
      if (tputs(tgetstr("cl", NULL), 1, my_puts) == -1)
	{
	  my_putstr("Error: tputs failed ! (sreen_clear)");
	  return (-1);
	}
    }
  return (0);
}
