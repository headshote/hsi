#include <stdio.h>

int fact( int n );

int main(void)
{
	int res, res2;
	res = fact( 5 );
	res2 = fcn_4(9);
	//printf("%d\n", res);
	printf("%d\n", res2 );
	return 0;
}

int fact( int n )
{
	if (n <= 1 )
		return 1;
	else
		return n * fact(n-1);
}

int fcn_4(int n)
{
	if (n <= 1)
		return 1;
	else
		return fcn_4( n-1 ) + fcn_4( n-2 );
}
