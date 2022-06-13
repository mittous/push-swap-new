#include <stdio.h>
#include <stdlib.h>
void	ft_swap(int a, int b)
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
}



int main()
{
    int a = 1;
    int b = 2;
    ft_swap(a,b);
    printf("a = %d|| b = %d", a,b);
    // int **best_one;
    // int a[2] = {1};
    // int b[2] = {2};
    // int c[2] = {3};
    // best_one = malloc(sizeof (int *) * 3);
    // best_one[0] = a; 
    // puts ("hna");
    // best_one[2] = b; 
    // best_one[3] = c; 
    // printf("best_one[0] = %d",best_one[0][0]);
    // printf("best_one[1] = %d",best_one[1][0]);
    // printf("best_one[2] = %d",best_one[2][0]);

    return 0;
}