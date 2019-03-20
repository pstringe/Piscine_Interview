#include "header.h"

int main(void)
{
	struct s_arts *tmp;
	struct s_arts **arts;

	arts = malloc(4 * sizeof(s_arts));
	arts[3] = NULL;

	arts[1]->name = "c";
	arts[2]->name = "d";
	arts[3]->name = "a";
	
	arts[1]->price = 100;
	arts[2]->price = 200;
	arts[3]->price = 300;

	sortArts(arts);
	
	tmp = *arts;
	while (tmp)
	{
		printf("%s\n"arts->name);
		tmp = tmp->next;
	}
	return(0);
}
