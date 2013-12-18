#include <stdio.h>
#include "basic_list.h"

int main()
{
	StorageList l;
	char *a={"foobar"};
	char b[10]={"hi there!"};
	int c=666;
	void *p;
	
	init_list(&l);
	
	add_to_list(&l, a);
	add_to_list(&l, b);
	add_to_list(&l, &c);
	
	p = get_elem_by_index(&l, 0);
	printf("a=%s\n", (char*)p);
	p = get_elem_by_index(&l, 1);
	printf("a=%s\n", (char*)p);
	p = get_elem_by_index(&l, 2);
	printf("a=%d\n", *(int*)p);

	release_list(&l);
	
	return 0;
}
