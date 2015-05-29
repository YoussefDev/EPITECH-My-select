/*
** my_select.h for my_select in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_my_select/include
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Wed Dec 17 12:38:31 2014 Youssef Sayyouri
** Last update Sun Jan 11 15:48:28 2015 Youssef Sayyouri
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

# include <termios.h>

typedef struct	s_list
{
  char		*str;
  int		selected;
  int		cursor;
  struct s_list *next;
  struct s_list *prev;
}		t_list;

t_list	*create_list();
void	show_list(t_list *list);
void	my_putchar(char c);
void	my_putstr(char *str);
void	arrow_bottom(t_list *list);
void	arrow_top(t_list *list);
void	list_free(t_list **list);
void	del_key(t_list *list);
void	del_elem(t_list *list);
void	key_space(t_list *list);
void	show_selected(t_list *list);
int	my_select(t_list *list, struct termios old);
int	get_buff(char buff[2], int *i, t_list *list, struct termios old);
int	raw_mode(struct termios *t);
int	set_backup(struct termios *t);
int	add_on_top(t_list *list, char *str);
int	my_puts(int c);
int	manage_arg(int ac, char **av, t_list *list);
int	screen_clear();
int	list_len(t_list *list);

#endif /* !MY_SELECT_H_ */
