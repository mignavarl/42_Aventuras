/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:22:12 by mignavar          #+#    #+#             */
/*   Updated: 2024/01/30 12:53:25 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		pr_next(char c, va_list args, int p);
int		pr_char(char c);
int		pr_int(int n);
int		pr_unsign(int n);
int		pr_str(char *str);
int		pr_hex(size_t n);
int		pr_hex_m(size_t n);
int		pr_void(size_t n);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);

#endif