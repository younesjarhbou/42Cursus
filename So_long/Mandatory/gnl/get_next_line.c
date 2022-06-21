/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjarhbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 05:05:44 by yjarhbou          #+#    #+#             */
/*   Updated: 2022/01/04 05:05:45 by yjarhbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*tmp = 0;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			ret;
	int			nl;

	if (!tmp)
		tmp = ft_strdup("");
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret >= 0)
	{
		buff[ret] = 0;
		tmp = ft_strjoin(tmp, buff);
		nl = get_nposition(tmp);
		if (nl != -1)
			return (get_line(&line, &tmp, nl));
		if (!ret && !tmp[0])
			break ;
		if (!ret)
			return (get_rest(&tmp, 0));
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(tmp);
	tmp = NULL;
	return (NULL);
}

char	*get_line(char **line, char **tmp, int nl)
{
	*line = ft_substr(*tmp, 0, nl + 1);
	*tmp = get_rest(tmp, nl + 1);
	return (*line);
}

char	*get_rest(char **str, int nl)
{
	char	*reminder;
	int		rlen;

	rlen = ft_strlen(*str + nl);
	reminder = ft_substr(*str, nl, rlen);
	free(*str);
	*str = NULL;
	return (reminder);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*sub_str;
	int				i;
	size_t			substr_len;

	if (!s)
		return (0);
	str = (char *)s;
	substr_len = ft_strlen(str);
	if (len < substr_len)
		substr_len = len;
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	sub_str = (char *)malloc(substr_len + 1);
	if (!sub_str)
		return (0);
	str += start;
	i = 0;
	while (*str && substr_len--)
		sub_str[i++] = *str++;
	sub_str[i] = '\0';
	return (sub_str);
}

int	get_nposition(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
