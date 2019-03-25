#include "header.h"

int     searchPrice(struct s_art **arts, char *name)
{
        int i;
		struct  s_art *tmp;

		i = -1;
        while ((tmp = arts[++i]))
			if (!strcmp(tmp->name, name))
				return (tmp->price);
        return (-1);
}
