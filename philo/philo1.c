/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:12:10 by grinella          #+#    #+#             */
/*   Updated: 2023/10/23 18:21:18 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 
#include <sys/time.h>

long	get_timestamp(void)
{
	struct timeval	current_time;
	long			timestamp_ms;

	gettimeofday(&current_time, NULL);
	timestamp_ms = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (timestamp_ms);
}
