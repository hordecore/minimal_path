#include <stdio.h>

static int ar[10][10];

void print_ar(int ar[10][10])
{
	int i,j;
	printf("Print:\n");
	for (i=1;i<10;i++) {
		for (j=1;j<10;j++) {
			if (ar[j][i]<1000 && ar[j][i]>=0)
				printf(" %d ", ar[j][i]);
			else	
				printf(" x ");
		}
		printf("\n");
	}
	return;
}

int get_path_from(int from, int len)
{
	int i,j,k;
	int tmp[10][10];
	printf("Get path from: %d, len: %d\n",from,len);
	for (j=0;j<=len;j++) {
		printf("Len: %d\n", j);
		k=j;
		for (i=1;i<10;i++)
			if (ar[from][i]>-1) {
				printf(" %d ", ar[from][i] );
				get_path_from(i, j-1);
			}
			else
				printf(" x ");
	printf("\n");
}
}

void init_ar(int ar[10][10])
{
	int i,j;
	for (i=1;i<10;i++) {
		for (j=1;j<10;j++) {
			if (i!=j) 
				ar[i][j]=-1;
			else 
				ar[i][j]=0;
		}
	}
	ar[1][2]=8;
	ar[2][3]=4;
	ar[3][5]=8;
	ar[4][3]=5;
	ar[5][4]=4;
	ar[5][6]=6;
	ar[6][1]=7;
	ar[7][6]=2;
	return;
}



int main(void)
{
	int i,j,k;
	init_ar(ar);
	print_ar(ar);
	get_path_from(1,1);
	return 0;

}
