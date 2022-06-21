/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjarhbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:50:58 by yjarhbou          #+#    #+#             */
/*   Updated: 2022/05/25 21:51:02 by yjarhbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H 

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	handler(int sig, siginfo_t *info, void *ucontext);
void	reset(char *c, int *a, int pid);
int		ft_atoi(const char *str);
int		ft_strlen(char *str_error);
void	error(char *str_error);
void	ft_putstr(char *str);
void	ft_putnbr(int n);

#endif
