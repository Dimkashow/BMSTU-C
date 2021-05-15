#include <stdio.h>

int checkSimple(int n)
{
    int i;
    for (i=2; i<=(n/2); i++)
        if ((n % i) == 0) return 0;
    return 1;
}

int checkFibon(int n)
{
    int a = 0;
	int b = 1;
	int temp = 0;
	while (b <= n)
	{
	    if (b == n)
		    return 1;
		a = b + a;
		temp = b;
		b = a;
		a = temp;
	}
	return 0;
	
}

int main()
{
    int N;
	scanf("%d", &N);
	for(int i = 2; i < N; i++)
	{
                if ((checkSimple(i) == 1) && (checkFibon(i) == 1))
		    printf("%d ", i);
	}
}
