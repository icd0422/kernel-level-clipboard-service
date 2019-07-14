#include<stdio.h>
#include<stdlib.h>
#include"kboard.h"

int main(int argc, char **argv)
{
	int clip = atoi(argv[1]) ;

	int r = kboard_copy(clip) ;

	if(r==-1)
	{
		printf("Fail : KBoard is full or invalid clip\n") ;
	}

	else
	{
		printf("Copy success : %d\n", clip) ;
	}
}
