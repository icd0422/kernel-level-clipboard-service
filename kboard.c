#include<stdio.h>
#include<sys/syscall.h>
#include"kboard.h"

long kboard_copy(int clip)
{
	return syscall(332,clip) ;
}

long  kboard_paste(void)
{
	return syscall(333) ;
}
