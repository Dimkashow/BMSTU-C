#include <stdio.h>

void check(int arr[], int n)
{
	int kol = 0;
	for (int i = 0; i < n; i++)
	{
		int res = 1;
	    for (int j = 0; j < i; j++)
		{
		    if (arr[i] == arr[j])
			    res = 0;
		}
		if (res)
		    kol++;
	}
	printf("%d", kol);
}

int main()
{
    int n;
	scanf("%d", &n);
	int array[n];
	for (int i = 0; i < n; i++)
	    scanf("%d", &array[i]);
	check(array, n);
}