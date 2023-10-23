/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:31:56 by grinella          #+#    #+#             */
/*   Updated: 2023/10/23 16:52:07 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Funzione per far mangiare un filosofo
void	eat(t_philosopher *philosopher, t_table *table)
{
	int	left_fork;
	int	right_fork;

	left_fork = philosopher->id;
	right_fork = (philosopher->id + 1) % table->num_philosophers;
	pthread_mutex_lock(&table->forks[left_fork]);// Acquisizione della forchetta sinistra
	pthread_mutex_lock(&table->forks[right_fork]);// Acquisizione della forchetta destra
	printf("%ld %d is eating\n", get_timestamp(), philosopher->id);// Filosofo mangia
	usleep(table->time_to_eat * 1000);// Simulazione del tempo necessario per mangiare
	pthread_mutex_unlock(&table->forks[left_fork]);// Rilascio delle forchette
	pthread_mutex_unlock(&table->forks[right_fork]);
	// Filosofo ha finito di mangiare
}

// Funzione per far pensare un filosofo
void	think(t_philosopher *philosopher)
{
	printf("%ld %d is thinking\n", get_timestamp(), philosopher->id);
	usleep(table->time_to_think * 1000);
}

void	sleep(t_philosopher *philosopher)
{
	printf("%ld %d is sleeping\n", get_timestamp(), philosopher->id);
	usleep(table->time_to_sleep * 1000);
}

// Funzione per inizializzare il tavolo e i filosofi
void	initialize_table(t_table *table)
{
	// Inizializza il tavolo, i filosofi e i mutex per le forchette
	table->num_philosophers = 5; // Numero di filosofi
	table->time_to_eat = 200;    // Tempo per mangiare in millisecondi
	table->time_to_sleep = 200;  // Tempo per dormire in millisecondi
	table->time_to_think = 200;  // Tempo per pensare in millisecondi

	// Inizializzazione dei mutex per le forchette
	for (int i = 0; i < table->num_philosophers; i++)
	{
		pthread_mutex_init(&table->forks[i], NULL);
	}

	// Altre inizializzazioni specifiche del tavolo e dei filosofi
}
// Funzione per il comportamento di un filosofo
void	*philosopher_thread(void *arg)
{
	t_philosopher *philosopher = (t_philosopher *)arg;
	t_table *table = philosopher->table;

	while (1)
	{
		// Il filosofo pensa
		think(philosopher);
		// Il filosofo cerca di acquisire le forchette per mangiare
		int left_fork = philosopher->id;
		int right_fork = (philosopher->id + 1) % table->num_philosophers;

		// Acquisizione della forchetta sinistra
		pthread_mutex_lock(&table->forks[left_fork]);
		printf("%ld %d has taken a fork\n", get_timestamp(), philosopher->id);
		// Acquisizione della forchetta destra
		pthread_mutex_lock(&table->forks[right_fork]);
		printf("%ld %d has taken a fork\n", get_timestamp(), philosopher->id);
		// Il filosofo mangia
		eat(philosopher, table);
		// Rilascio delle forchette
		pthread_mutex_unlock(&table->forks[left_fork]);
		pthread_mutex_unlock(&table->forks[right_fork]);
		// Il filosofo dorme
		sleep(philosopher);
	}
	return (NULL);
}

// Funzione per inizializzare il tavolo e i filosofi
void initialize_table(t_table *table)
{
	// Implementazione per l'inizializzazione del tavolo e dei filosofi
}

int main(int argc, char *argv[])
{
	// Implementazione per l'analisi dei parametri della riga di comando

	// Inizializza il tavolo e i filosofi
	t_table table;
	initialize_table(&table);

	// Avvia i thread dei filosofi
	for (int i = 0; i < table.num_philosophers; i++)
	{
		pthread_create(&table.philosophers[i].thread, NULL, philosopher_thread, &table.philosophers[i]);
	}

	// Implementazione per gestire il monitoraggio o la terminazione dei thread dei filosofi

	return (0);
}
