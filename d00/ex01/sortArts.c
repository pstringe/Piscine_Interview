#include "header.h"
#include <stdlib.h>
#include <stdio.h>

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
