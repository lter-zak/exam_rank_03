/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:10:59 by lter-zak          #+#    #+#             */
/*   Updated: 2022/11/16 15:34:05 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

char *get_next_line(int fd);
#endif
