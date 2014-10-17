/*
 * get the number of swapping adjacent characters
 */
#include<stdio.h>
int n = 5;
char str[] = "ZBDCA";

int count[26] = {};
int ans = 0;

int i,j;
void main() {
	for (i = 0; i < n; ++i)
	{
		int index = str[i] - 'A';
		count[ index ] ++;
		// ans += sum( count[index + 1] ... count[26 - 1] );
		for (j = index + 1 ; j < 26; ++j){
			ans += count[j];
		}
	}
	printf( "%d\n",ans);
	for( j =0 ; j < 26; j++){
		printf( "%d ",count[j]);
	}
	printf( "\n" );
}
