/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:31:21 by grinella          #+#    #+#             */
/*   Updated: 2023/10/23 17:20:59 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
// # include "libft.h"

typedef struct s_philosopher
{
	int			id;
	pthread_t	thread;
}	t_philosopher;

typedef struct s_table
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat_required;
	int				time_to_think;
	pthread_mutex_t	*forks;
}		t_table;

void		*philosopher_thread(void *arg);
void		initialize_table(t_table *table);

#endif
