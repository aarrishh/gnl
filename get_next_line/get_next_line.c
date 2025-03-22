/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arina <arina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:01:13 by arimanuk          #+#    #+#             */
/*   Updated: 2025/03/22 10:23:54 by arina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_exists(char *buffer)
{
	int i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*left_over(char *str_join)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str_join[i] && str_join[i] != '\n')
		i++;
	if (!str_join[i]) 
		return (NULL);
	int malloc_len = ft_strlen(str_join) - i;
	if (malloc_len <= 0)
		return (NULL);
	char *res = (char *)malloc((malloc_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i++;
	while (str_join[i])
		res[j++] = str_join[i++];
	res[j] = '\0';
	return(res);
}

char	*cur_line(char *str_join)
{
	int i;

	i = 0;
	while (str_join[i] && str_join[i] != '\n')
		i++;
	if (str_join[i] && str_join[i] == '\n')
		return (ft_substr(str_join, 0, i + 1));
	return (ft_substr(str_join, 0, i));
	
			
}


char	*get_next_line(int fd)
{
	static char*		result;
	char*				str_join = NULL;
	char*				buffer = NULL;
	ssize_t 			count_bytes = 1;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	while (nl_exists(buffer) == 0 && count_bytes != 0)
	{	 
		free(buffer);
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		count_bytes = read(fd, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(buffer);
			buffer = NULL;
			free(result);	
			result = NULL;
			return (NULL);
		}
		buffer[count_bytes] = '\0';
		str_join = ft_strjoin(result, buffer);
		if (result)
		{
			free(result);
			result = NULL;
		}
		result = str_join;
	}
	if (*result == '\0' && count_bytes == 0)
	{
		free(result);
		result = NULL;
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	result = left_over(str_join);
	char *return_str = cur_line(str_join);
	free(str_join);
	free(buffer);
	return (return_str);
}

// int main()
// {
// 	int a = open("file.txt", O_RDONLY);
	
//     char *res = get_next_line(a);
//     char *res1 = get_next_line(a);
//     char *res2 = get_next_line(a);
//     char *res3 = get_next_line(a);
//     char *res4 = get_next_line(a);
	
	
//     printf("ya zdzes->%s", res);
//     printf("ya zdzes->%s", res1);
//     printf("ya zdzes->%s", res2);
//     printf("ya zdzes->%s", res3);
//     printf("ya zdzes->%s", res4);
	

//     free(res);
//     free(res1);
//     free(res2);
//     free(res3);
//     free(res4);

//     close(a);
//     return 0;
// }