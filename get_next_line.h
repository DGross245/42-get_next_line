/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:35:50 by dgross            #+#    #+#             */
/*   Updated: 2022/05/19 12:08:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <unistd.h> // size_t 

char	*keep_line(char *string);
char	*malloc_line(char *string);
char	*read_line(int fd, char *string);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_memcpy(void *dst, void *src, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t size);
size_t	ft_strlen(char *s);

#endif