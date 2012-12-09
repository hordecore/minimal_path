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
			if (i==j) 
				add_path(&arr[j][i], 0, 0);
			else
				add_path(&arr[j][i], 0, -1);
	add_path(&arr[1][2], 0, 8);
	add_path(&arr[2][3], 0, 4);
	add_path(&arr[3][5], 0, 8);
	add_path(&arr[3][1], 0, 2);
	add_path(&arr[4][3], 0, 5);
	add_path(&arr[4][6], 0, 5);
	add_path(&arr[5][4], 0, 4);
	add_path(&arr[5][6], 0, 6);
	add_path(&arr[6][1], 0, 7);
	add_path(&arr[6][3], 0, 3);
	add_path(&arr[6][8], 0, 1);
	add_path(&arr[7][5], 0, 1);
	add_path(&arr[7][6], 0, 2);
	add_path(&arr[7][8], 0, 7);
	add_path(&arr[8][7], 0, 1);
	add_path(&arr[8][1], 0, 5);
	add_path(&arr[8][9], 0, 2);
	add_path(&arr[9][1], 0, 1);
	add_path(&arr[9][8], 0, 3);

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

void print_avaible(struct path arr[10][10], int from) {
	int i,j;
	for (i=1;i<10;i++)
		if (arr[from][i].cost > 0 && arr[from][i].by == 0)
			printf("%d->%d: %d\n", from, i, arr[from][i].cost);
	return;
}

void main(void)
{
	init_path(array);
	init_path(tmp);
	print_path_array(array);
	return;
}
