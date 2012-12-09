#include <stdio.h>

static int ar[10][10];
static int tmp[10][10];

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

int get_path_from(int orig, int from, int len)
{
	int i,j,k;
	if (len<0)
		return -1;
	//printf("Get path from: %d, len: %d\n",from,len);
	for (j=0;j<=len;j++) {
		//printf("Len: %d\n", j);
		k=j;
		for (i=1;i<10;i++)
			if (ar[from][i]>0) {
				printf("%d -> %d = %d\n", orig, i, tmp[orig][from] + ar[from][i]);
				tmp[orig][i] = tmp[orig][from]+ar[from][i];
				get_path_from(from, i, j-1);
			}
		printf("\n");
	}
	return 0;
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
	ar[3][1]=2;
	ar[4][3]=5;
	ar[4][6]=5;
	ar[5][4]=4;
	ar[5][6]=6;
	ar[6][1]=7;
	ar[6][3]=3;
	ar[6][8]=1;
	ar[7][5]=1;
	ar[7][6]=2;
	ar[7][8]=7;
	ar[8][7]=1;
	ar[8][1]=5;
	ar[8][9]=2;
	ar[9][1]=1;
	ar[9][8]=3;

	for (i=1;i<10;i++)
		for (j=1;j<10;j++)
			tmp[i][j]=ar[i][j];
	return;
}



int main(void)
{
	int i,j,k;
	init_ar(ar);
	print_ar(ar);
	for (i=1;i<10;i++)
		get_path_from(i,i,1);
	print_ar(tmp);
	return 0;

}
