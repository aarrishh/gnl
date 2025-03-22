/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arina <arina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:51:28 by arimanuk          #+#    #+#             */
/*   Updated: 2025/03/21 21:46:56 by arina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int	nl_exists(char *buffer);
int	ft_strlen(const char *str);
char	*left_over(char *str_join);
char	*get_next_line(int fd);
char	*cur_line(char *str_join);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif