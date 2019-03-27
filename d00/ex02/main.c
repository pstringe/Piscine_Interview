#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int cmpstr(void *v1, void *v2) 
{ 
    char *a1 = *(char**)v1; 
    char *a2 = *(char**)v2; 
    return strcmp(a1, a2); 
} 
  
int cmpart(void* v1, void* v2)
{
	struct s_art *a1 = (struct s_art*)v1;
	struct s_art *a2 = (struct s_art*)v2;
	
	return (cmpstr(a1->name, a2->name));
}

void swap(void* v1, void* v2, int size) 
{ 
    char buffer[size]; 
  
    memcpy(buffer, v1, size); 
    memcpy(v1, v2, size); 
    memcpy(v2, buffer, size); 
} 
  
void _qsort(void* v, int size, int left, int right, int (*comp)(void*, void*)) 
{ 
    void *vt, *v3; 
    int i, last, mid = (left + right) / 2; 
    if (left >= right) 
        return; 
    void* vl = (char*)(v + (left * size)); 
    void* vr = (char*)(v + (mid * size)); 
    swap(vl, vr, size); 
    last = left; 
    for (i = left + 1; i <= right; i++) { 
        vt = (char*)(v + (i * size)); 
        if ((*comp)(vl, vt) > 0) { 
            ++last; 
            v3 = (char*)(v + (last * size)); 
            swap(vt, v3, size); 
        } 
    } 
    v3 = (char*)(v + (last * size)); 
    swap(vl, v3, size); 
    _qsort(v, size, left, last - 1, comp); 
    _qsort(v, size, last + 1, right, comp); 
} 
  
void	sortArts(struct s_art **arts)
{
	int size;

	size = -1;
	while (arts[++size]);
	_qsort(arts, sizeof(struct s_art*), 0, --size, cmpart);
}
int main(void)
{
	struct s_art **arts;

	arts = getArts(); //parsing the file and put it in an array

	/*-------------------
	launch your test here
	--------------------*/
	sortArts(arts);
	for (int i = 0; i <= 10; i++)
		printf("%d: %s\n", i, arts[i]->name);

	printf("price: %d\n", searchPrice(arts, 75, "\"A Yankee in Petrograd\" Vol. 9 Yankee Go Home by Jim Dollar (Marietta Saginyan)"));
	printf("price: %d\n", searchPrice(arts, 75, "\"#1 - 1966\""));
	printf("price: %d\n", searchPrice(arts, 75, "not an art piece"));
	return (0);
}



// Function used for the test
// Don't go further :)

#define FILENAME "art.txt"

char	*readFile(void)
{
	char *fcontent = NULL;
	int size = 0;
	FILE *fp;

	if (NULL == (fp = fopen(FILENAME, "r")))
		return (NULL);
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	if (NULL == (fcontent = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	fread(fcontent, 1, size, fp);
	fclose(fp);
	return (fcontent);
}

char	**split(char *str, char *delimiter){
	char **tab;
	int count;
	int a;
	int pos;
	int len_delimiter;
	int len_substring;

	len_delimiter = strlen(delimiter);
	len_substring = 0;
	count = 0;
	//first counting the number of substring
	for (int i = 0; str[i]; i++){
		if (strncmp(str + i, delimiter, len_delimiter) == 0) {
			if (len_substring > 0){
				len_substring = 0;
				count += 1;
			}
			i += len_delimiter - 1;
		} else {
			len_substring += 1;
		}
	}
	if (len_substring > 0){
		count += 1;
	}
	if (NULL == (tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	tab[(a = 0)] = NULL;
	len_substring = 0;
	pos = 0;
	//then get the substring :)
	for (int i = 0; str[i]; i++){
		if (strncmp(str + i, delimiter, len_delimiter) == 0) {
			if (len_substring > 0){
				tab[(a++)] = strndup(str + pos, len_substring);
				len_substring = 0;
			}
			i += len_delimiter - 1;
			pos = i + 1;
		} else {
			len_substring += 1;
		}
	}
	if (len_substring > 0){
		tab[(a++)] = strndup(str + pos, len_substring);
	}
	tab[a] = NULL;
	return (tab);
}

void	getArts_leave(void){
	dprintf(STDERR_FILENO, "failed to load the file.\n");
	exit(0);
}

struct s_art *getArts_createStruct( char *line ){
	struct s_art *piece;
	char **tab;

	if (NULL == (piece = malloc(sizeof(struct s_art))))
		return (NULL);
	if (NULL == (tab = split(line, " => ")))
		return (NULL);
	if (tab[0] != NULL)
		piece->name = strdup(tab[0]);
	else
		return (NULL);
	if (tab[1] != NULL)
		piece->price = atoi(tab[1]);
	else
		return (NULL);

	for (int i = 0; tab[i] ; i++){
		free(tab[i]);
	} free(tab);

	return (piece);
}

struct s_art **getArts(void)
{
	char *file;
	struct s_art **art;
	int art_size;
	int	art_index;

	dprintf(STDOUT_FILENO, "loading the file... ");
	if (NULL == (file = readFile()))
		getArts_leave();

	//creating the array
	art_size = 0;
	for (int i = 0; file[i]; i++){
		if (file[i] == '\n')
			art_size += 1;
	}
	if (NULL == (art = malloc(sizeof(struct s_art *) * (art_size + 1))))
		getArts_leave();
	art[(art_index = 0)] = NULL;

	//filling the array
	char **tab = split(file, "\n");
	struct s_art *tmp;
	for(int i = 0; tab[i]; i++){
		tmp = getArts_createStruct(strdup(tab[i]));
		if (tmp)
			art[(art_index++)] = tmp; 
	}
	art[(art_index)] = NULL;

	for (int i = 0; tab[i] ; i++){
		free(tab[i]);
	} free(tab);

	dprintf(STDOUT_FILENO, "finish!\n");
	return (art);
}
