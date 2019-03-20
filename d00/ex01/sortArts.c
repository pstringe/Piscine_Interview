#include "header.h"

void	sortArts(struct s_ars **arts)
{
	int sorted;
	int i;
	sorted = 0;

	tmp = *arts;
	while (!sorted)
	{
		if (cmp(tmp, tmp + 1) < 0)
			swap(tmp, tmp + 1);
		i = -1;
		while (arts[++i])
			if (cmp(arts[i], arts[i + 1]) < 0)
				break ;
		if (!arts[i])
			sorted = 1;		
	}
}
