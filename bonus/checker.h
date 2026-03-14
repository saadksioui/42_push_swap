/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 01:34:42 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/24 09:43:25 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

// GET NEXT LINE
char	*line_clip(char **rest);
int		read_join(int fd, char **rest);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, size_t start, size_t len);

// CHECKER UTILS
void	checker_s_p(t_stack **a, t_stack **b, char *line);
void	checker_r(t_stack **a, t_stack **b, char *line);

int		ft_strcmp(const char *s1, const char *s2);

#endif