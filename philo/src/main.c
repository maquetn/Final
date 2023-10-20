/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:45:02 by marvin            #+#    #+#             */
/*   Updated: 2023/10/19 22:45:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;
	int		ret;

	if (ac < 5 || ac > 6)
		return (ft_error("Wrong amount of arguments (min. 5 to 6)"));
	ret = init_manager(&rules, av);
	if (ret == WRONG_ARGS)
		return (ft_error("At least one wrong argument."));
	else if (ret == MUTEX_FAIL)
		return (ft_error("pthread_mutex_init() failed"));
	else if (ret == MALLOC_FAIL)
		return (ft_error("malloc() failed"));
	ret = philo_threads(&rules);
	if (ret)
	{
		while (--ret >= 0)
			pthread_join(rules.phi[ret].thread_id, NULL);
		while (++ret < rules.nb_philo)
			pthread_mutex_destroy(&rules.forks[ret]);
		pthread_mutex_destroy(&(rules.state_write));
		free(rules.forks);
		free(rules.phi);
		return (ft_error("pthread_create() failed"));
	}
	return (EXIT_SUCCESS);
}
