/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:46:20 by marvin            #+#    #+#             */
/*   Updated: 2023/10/19 22:46:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	print_action(t_philo *philo, int end_flag, int status)
{
	char	*arr[6];

	arr[DIED] = "died";
	arr[EATING] = "is eating";
	arr[SLEEPING] = "is sleeping";
	arr[THINKING] = "is thinking";
	arr[FORK_1] = "has taken a fork";
	arr[FORK_2] = arr[FORK_1];
	sem_wait(philo->sem_write);
	printf("%ld %d %s\n", get_time() - philo->rules->start_time,
		philo->id + 1, arr[status]);
	if (!end_flag)
		sem_post(philo->sem_write);
}
