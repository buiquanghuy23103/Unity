/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyrotiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 09:03:47 by osyrotiu          #+#    #+#             */
/*   Updated: 2018/10/26 09:12:24 by osyrotiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	else
	{
		free(*as);
		*as = (void *)0;
	}
}