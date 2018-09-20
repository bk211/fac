#include <stdio.h>
int	main(int argc, char const *argv[])
{
	int max,min,i;
	printf("maximum?");scanf("%d",&max);
	printf("minimum?");scanf("%d",&min);
	for (i=min; (i<=max); ++i)
	{if(i%3==0&&i/3!=0)printf("%d,",i );
	}
	return 0;
}