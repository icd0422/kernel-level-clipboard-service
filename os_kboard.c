#include<linux/printk.h>
#include<linux/kernel.h>

static int ling[5];

long sys_kb_enqueue(int clip)
{
	int t = 0 ;
	int i ;

	if(clip<0)//음수를 넣을려고 하면
	{
		printk(KERN_DEBUG "JHJANG: sys_my_enqueue() CALLED!! clip = %d\n", clip);
		printk(KERN_DEBUG "sys_my_enqueue invalid integer clip = %d\n", clip);
		return -1 ;
	}

	for(i=0 ; i<5 ; i++)
	{
		if(ling[i]==0)
		{
			t=1 ;
			break ;
		}
	}

	if(t==0)//ling버퍼가 꽉 차있으면
	{
		printk(KERN_DEBUG "JHJANG: sys_my_enqueue() CALLED!! clip = %d\n", clip);
		printk(KERN_DEBUG "JHJANG: sys_my_enqueue() ring is full!!\n", clip);
		return -1 ;
	}

	ling[i] = clip ;
	printk(KERN_DEBUG "JHJANG: sys_my_enqueue() CALLED!! clip = %d\n", clip);//그 외의 경우 정상으로 들어감
	return 0 ;
}

long sys_kb_dequeue(void)
{
	int t = 0 ;
	int i,j ;
	int temp ;

	for(i=0 ; i<5 ; i++)
	{
		if(ling[i]!=0)
		{
			t=1 ;
			break ;
		}
	}

	if(t==0)//ling버퍼가 비어있으면
	{
		printk(KERN_DEBUG "JHJANG: sys_my_dequeue() CALLED!!\n") ;
		printk(KERN_DEBUG "JHJANG: sys_my_dequeue() ring is empty!!\n") ;
		return -1 ;
	}

	temp = ling[i] ;
	ling[i] = 0 ;

	for(j=i; j<5 ; j++)
	{
		ling[j-1] = ling[j] ;
		ling[j] = 0 ;
	}
	printk(KERN_DEBUG "JHJANG: sys_my_dequeue() CALLED!!\n") ;
	return temp ;
}
