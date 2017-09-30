/*
 * div3 --> fizz
 * div5 --> buzz
 * div3&&div5 -->fizzbuzz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fizzbuzz(int i);
void fizzbuzz2(int i);
int main(int argc, char **argv)
{

	//~ int a=54325;
	//~ char buf[20];
	//~ snprintf(buf,sizeof(buf),"%d",a);
	//~ printf("%s\n",buf);
	fizzbuzz2(100);
	return 0;
}

void fizzbuzz(int i){
	
	if(i==1) printf("1\n");
	else{
		fizzbuzz(i-1);
		if(i%15==0)	printf("fizzbuzz\n");
		else if(i%5==0)	printf("buzz\n");
		else if(i%3==0)	printf("fizz\n");
		else printf("%d\n",i);		
	}

	
}

void fizzbuzz2(int i){
		if(i==1) printf("1\n");
		else{
			char str[20];
			snprintf(str,sizeof(str),
				    (i%15==0) ? "fizzbuzz"
				  : (i%5==0) ? "buzz"
				  : (i%3==0) ? "fizz"
				  : ("%d",i));
			printf("%s\n",str);
			fizzbuzz2(i-1);
		}
}
