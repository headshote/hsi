#include <stdio.h>

int main(void)
{
	int v1 = 10;
	int v2 = ~v1 +1;
	printf("%d %d \n", v1, v2);
	int v3 = 0xffffffff;
	printf("%d \n", v3);
	printf("%d %d \n", !54, !0);
}
