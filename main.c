#include <stdio.h>

struct path {
	int by;
	int cost;
};

static struct path array[10][10];
static struct path tmp[10][10];

void add_path(struct path *elem, int by, int cost)
{
	elem->cost = cost;
	elem->by = by;
	return;
}

void init_path(struct path arr[10][10])
{
	int i,j;
	for (i=1;i<10;i++)
		for (j=1;j<10;j++)
			if (i==j) {
				add_path(&array[j][i], 0, 0);
				printf("add %d %d: 0 0\n", i, j);
			} else {
				add_path(&array[j][i], 0, -1);
				printf("add %d %d: 0 -1\n", i, j);
			}
	return;
}

void print_path_array(struct path arr[10][10])
{
	int i,j;
	for (i=1;i<10;i++) {
		for (j=1;j<10;j++)
			if (arr[j][i].cost > -1)
				printf(" %d ", arr[j][i].cost);
			else
				printf(" x ");
		printf("\n");
	}

	return;
}

void main(void)
{
	init_path(array);
	init_path(tmp);
	print_path_array(array);
	return;
}
