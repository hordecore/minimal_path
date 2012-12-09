#include <stdio.h>

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

void init_ar(int ar[10][10])
{
	int i,j;
	for (i=1;i<10;i++) {
		for (j=1;j<10;j++) {
			ar[i][j]=-1;
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
	int ar[10][10];
	int i,j,k;
	init_ar(ar);
	for (i=1;i<10;i++)
		ar[i][i]=0;
	printf("itworks %d\n", 10);
	print_ar(ar);
	return 0;

}
