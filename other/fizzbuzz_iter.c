/*
 * div3 --> fizz
 * div5 --> buzz
 * div3&&div5 -->fizzbuzz
 */

#include <stdio.h>
#include <stdlib.h>
void fizzbuzz(int i);
int main(int argc, char **argv)
{
	int i;
	for(i=0;i<100;i++){
		if(i%15==0) printf("fizzbuzz\n");
		else if(i%5==0) printf("buzz\n");
		else if(i%3==0) printf("fizz\n");
		else printf("%d\n",i);
	}
}


