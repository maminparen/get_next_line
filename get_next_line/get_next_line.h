/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:33:41 by hzona             #+#    #+#             */
/*   Updated: 2021/10/13 11:34:09 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

#endif