#include<stdio.h>
 
#include<stdlib.h>
int main()
 
{
	int n;
	scanf("%d ",&n);
	
 
		int a, b, i = 0, count = 0, dount = 0;
		int*c = NULL;
		c = (int*)calloc(n, sizeof(int));
		int*d = NULL;
		d = (int*)calloc(n, sizeof(int));
		scanf("%d %d", &a, &b);
		for (int k = 0; k < n; k++)
		{
			int x, y;
			scanf("%d %d",&x,&y);
			*(c + k) = x;
			*(d + k) = y;
		}
		
		while (i < n)
		{
			if (a > *(c + i) && b > *(d + i))
			{
				count++;
			}
			else if (a < *(c + i) && b < *(d + i))
			{
				dount++;
			}
			i++;
		}
		if (count == dount)
		{
			printf("%d %d", a, b);
		}
 
	
		return 0;
}
