/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:47:19 by vdragomi          #+#    #+#             */
/*   Updated: 2021/05/26 20:01:19 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* itoa () function in C language converts int data type to string data type.
*/
static int	ft_get_nbr_size(int n, int sign)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 2;
	else
	{
		while (n)
		{
			n /= 10;
			size++;
		}
		size = size + sign + 1;
	}
	return (size);
}

static int	ft_check_sign(int *n)
{
	int	sign;

	sign = 0;
	if (*n < 0)
	{
		*n *= -1;
		sign = 1;
	}
	return (sign);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	char	*rtn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = ft_check_sign(&n);
	size = ft_get_nbr_size(n, sign);
	rtn = (char *)(ft_calloc(size, sizeof(char)));
	if (rtn)
	{
		while (size - 1)
		{
			rtn[size - 2] = n % 10 + '0';
			n /= 10;
			size--;
		}
		if (sign)
			*rtn = '-';
	}
	return (rtn);
}
