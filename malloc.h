#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <unistd.h>
# include <stdlib.h>



typedef struct s_malloc
{
	void			*data;
	struct s_malloc	*next;
}	t_malloc;

t_malloc	*new_data(void *new, t_malloc *data);
void		add_data(t_malloc *new, t_malloc **data);
void		*ft_malloc(size_t size, t_malloc **tmp);
void		ft_free_malloc(t_malloc *data);

#endif