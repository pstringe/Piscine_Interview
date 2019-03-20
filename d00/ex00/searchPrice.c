#include "header.h"

int     searchPrice(struct s_arts **arts, char *name);
{
        struct  s_art *tmp;

        tmp = *arts;
        while (tmp->name && tmp->price > 0)
                if (!strncmp(tmp->name, name))
                        return (tmp->price);
        return (-1);
}
