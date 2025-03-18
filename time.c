/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamsin <achamsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:35:01 by achamsin          #+#    #+#             */
/*   Updated: 2025/03/18 09:35:03 by achamsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	current_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	p_sleep(t_data *data, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = current_time() + sleep_time;
	while (current_time() < wake_up)
	{
		if (has_simulation_stopped(data))
			break ;
		usleep(100);
	}
}

void	sim_start_delay(time_t start_time)
{
	while (current_time() < start_time)
		continue ;
}
