/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:32:03 by buozcan           #+#    #+#             */
/*   Updated: 2023/10/21 19:36:56 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ll;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set,*s1))
		s1++;
	ll = ft_strlen(s1);
	while (ll && ft_strchr(set, s1[ll - 1]))
		ll--;
	return (ft_substr(s1, 0, ll));
}
