/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:18:20 by adandres          #+#    #+#             */
/*   Updated: 2018/08/24 03:05:22 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_file(int fd, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->content = ft_strdup("");
	tmp->content_size = fd;
	ft_lstadd(list, tmp);
	tmp = *list;
	return (tmp);
}

int				ft_strchr_len(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	return (i);
}

char			*ft_free(char **s1, int i)
{
	char *tmp;

	tmp = ft_strdup(*s1 + i + 1);
	free(*s1);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list;
	t_list			*file;
	int				i;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	file = get_file(fd, &list);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!(file->content = ft_strjoin(file->content, buf)))
			return (-1);
		if (ft_strchr(file->content, '\n'))
			break ;
	}
	if (i < BUFF_SIZE && !(ft_strlen(file->content)))
		return (0);
	i = ft_strchr_len(file->content, '\n');
	*line = ft_strsub(file->content, 0, i);
	if (i < (int)ft_strlen(file->content))
		file->content = ft_free((char**)&file->content, i);
	else
		ft_strclr(file->content);
	return (1);
}
