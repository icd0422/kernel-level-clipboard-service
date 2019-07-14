#include<stdio.h>
#include"kboard.h"

int main()
{
	int r = kboard_paste() ;

	if(r==-1)
	{
		printf("Fail : KBoard is empty\n") ;
	}

	else
	{
		printf("Paste success : %d\n", r) ;
	}
}
