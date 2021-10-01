/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:47:36 by kkawano           #+#    #+#             */
/*   Updated: 2021/08/12 20:33:30 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	num;

	if (lst == NULL)
		return (0);
	num = 1;
	while (lst->next != NULL)
	{
		num++;
		lst = lst->next;
	}
	return ((int)num);
}
