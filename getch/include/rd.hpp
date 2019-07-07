/*
** rd.h for rd in /home/alies_a/perso/simple-getch
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri May 13 11:51:08 2016 alies_a
** Last update Tue Mar 20 17:14:38 2018 Aurelien
*/

#ifndef RD_H_
# define RD_H_

# include "ch.hpp"

# define RD_LINE ((rd->history->lines)[rd->history->pos])
# define HISTORY_SIZE (10)

typedef struct s_history
{
  char *lines[HISTORY_SIZE];
  int pos;
  int cur_pos;
} t_history;

typedef struct s_rd
{
  int fd;
  int curs;
  t_history *history;
} t_rd;

typedef int(*t_action)(t_rd *rd, int key);

typedef struct s_act
{
  t_action func;
  int key;
} t_act;

/*
** Notes:
** rd_clear will change curs pos, but not line*
*/

void    history_init(t_rd *rd);
void    history_down(t_history *history);
void    history_up(t_history *history);
int     history_cpy_line(t_rd *rd);
void    history_free();

void    rd_disp(t_rd *rd);
void    rd_clear(t_rd *rd, int size);
int	rd_add_char(t_rd *rd, char c);
void    rd_rm_char(char *str, int pos);
int	rd_key(t_rd *rd, int key);

void	rd_put(t_rd const *rd, char c);
void	rd_putstr(t_rd const *rd, char const *str);

int	rd_char(t_rd *rd, int key);
int     rd_left(t_rd *rd, int key);
int     rd_right(t_rd *rd, int key);
int     rd_up(t_rd *rd, int key);
int     rd_back(t_rd *rd, int key);
int     rd_down(t_rd *rd, int key);

#endif
