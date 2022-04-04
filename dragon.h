/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:35:04 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/04 16:37:58 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAGON_H
# define DRAGON_H

# define MAX_BLOCKS 1030

typedef struct s_bigint
{
	unsigned int	len;
	unsigned int	blocks[MAX_BLOCKS];
}	t_bigint;

#endif
