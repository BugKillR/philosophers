/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:59:09 by kkeskin           #+#    #+#             */
/*   Updated: 2025/10/02 00:59:09 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *num)
{
	long	res;
	long	sign;
	long	i;

	res = 0;
	sign = 1;
	i = 0;
	while (num[i] && num[i] == ' ')
		i++;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= num[i] && num[i] <= '9')
	{
		res = (res * 10) + (num[i] - '0');
		i++;
	}
	return (res * sign);
}
