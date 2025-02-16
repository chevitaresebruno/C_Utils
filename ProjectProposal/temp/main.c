#include ".\scripts\inc\shared.h" 
 
#include <stdio.h>

 
int main() 
{ 
	SimpleLinkedQueue queue = sllBuild();

	int a = 5;
	int* b;

	slqAdd(queue, &a);

	printf("%d", *(int*)sllGetAt(queue, 0));
	
	b = slqPop(queue);
	printf("\n%d", *b);
	printf("\n%u", sllSize(queue));

	return 0; 
} 

