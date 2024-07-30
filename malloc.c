#include "malloc.h"

void	*ft_malloc(size_t size, t_malloc **tmp)
{
	static t_malloc	*data;
	void			*new;

	new = malloc(size);
	if (!new)
	{
		ft_free_malloc(data);
		exit(1);
	}
	add_data(new_data(new, data), &data);
	*tmp = data;
	return (new);
}

t_malloc	*new_data(void *new, t_malloc *data)
{
	t_malloc	*new_data;

	new_data = malloc(sizeof(t_malloc));
	if (!new_data)
		ft_free_malloc(data);
	new_data->data = new;
	new_data->next = NULL;
	return (new_data);
}

void	add_data(t_malloc *new, t_malloc **data)
{
	t_malloc	*tmp;

	tmp = *data;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!tmp)
		*data = new;
	else
		tmp->next = new;
}

void	ft_free_malloc(t_malloc *data)
{
	t_malloc	*tmp;

	tmp = data;
	while (tmp)
	{
		free(tmp->data);
		tmp = tmp->next;
	}
	tmp = data;
	while (data)
	{
		tmp = data;
		data = data->next;
		free(tmp);
	}
	exit(1);
}
