/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:26:13 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/11 16:20:37 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo	t_philo;

typedef struct s_data
{
	int					id;
	long				start_time;
	int					count;
	int					flag;
	pthread_t			*thread;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	t_philo				*access;
}						t_data;

typedef struct philo
{
	int					n_philo;
	long				start_simutaltion;
	int					t_die;
	int					index;
	int					t_eat;
	int					flag;
	int					t_sleep;
	int					is_die;
	int					n_repeat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*print;
	pthread_t			*philo;
	t_data				*thread_mutex;
}						t_philo;

typedef enum UPCODE
{
	CREAT,
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
}						t_upcode;

typedef struct elemet
{
	int					i;
	int					num;
	int					sign;
}						t_el;

# define INT_MIN -2147483648
# define INT_MAX 2147483647

int						ft_atoi(char *str);
int						ft_strlen(char *str);
t_philo					*fill_struct(int ac, char **av);
void					ft_putstr(char *str, int fd);
int						safe_mutex_handle(pthread_mutex_t *fork,
							t_upcode UPCODE);
int						ft_free(t_philo *data, int index);
int						init_data(t_philo *data);
long					get_current_time(void);
void					ft_check_die(t_data *philo);
int						should_stop(t_data *philo, int n, int n_meals);
void					odd(t_philo *data);
void					even(t_philo *data);

#endif