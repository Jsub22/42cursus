/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:13:10 by subjeong          #+#    #+#             */
/*   Updated: 2024/12/20 17:53:34 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_unsigned(unsigned int n);
int		ft_print_dec(int n);
int		ft_print_hex(unsigned int n, char type);
int		ft_print_ptr(void *ptr);
int		ft_print_str(char *str);

char	*ft_uitoha(unsigned int n, char type);
char	*ft_uitoa(unsigned int n);
char	*ft_ptoa(uintptr_t n);
#endif