/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:49:08 by adandres          #+#    #+#             */
/*   Updated: 2018/06/25 18:30:33 by adandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_ok(char *str)
{
	int i;
	int j;
	int c;

	c = 0;
	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[c])
		c++;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j] || str[i] == '+' || str[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (c);
}

int		check_str(char *str, char *base)
{
	int i;
	int j;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] == '\f' || str[i] == '\r' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		j = 0;
		while (base[j] && str[i] != base[j])
		{
			if (str[i] != base[j])
				j++;
		}
		if (str[i] != base[j])
			return (0);
		i++;
	}
	return (1);
}

int		str_trad(char c, char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int neg;
	int result;

	neg = 1;
	j = base_ok(base);
	i = 0;
	result = 0;
	if (base_ok(base) && check_str(str, base))
	{
		while (str[i] == '\f' || str[i] == '\r' || str[i] == '\t' || str[i] ==
	' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				neg = -1;
			i++;
		}
		while (str[i] && str[i] != '+' && str[i] != '-')
		{
			result = result * j + str_trad(str[i], base);
			i++;
		}
	}
	return (result * neg);
}
