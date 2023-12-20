/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:38:19 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/12/19 10:38:20 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;
char	*get_next_line(int fd);
int		len_till_nl(t_list *list);
int		got_new_line(t_list *list);
char	*get_line(t_list *list);
void	ft_append(t_list **list, char *buf, int fd);
void	copy_str(t_list *list, char *str);
void	create_list(t_list **list, int fd);
void	clean_the_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
t_list	*ft_lstlast(t_list *list);

#endif
