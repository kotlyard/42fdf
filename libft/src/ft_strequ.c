/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:40:15 by dkotlyar          #+#    #+#             */
/*   Updated: 2017/11/22 13:41:55 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
