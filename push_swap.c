#include <stdio.h>


#include "push_swap.h"


/***********************************************************/

void	ft_error(char arg)
{
	printf ("error in the character '%c' was not digit", arg);
	exit (0);
}

int	ft_isalpha(char arg)
{
	if (arg != ' ' && (arg < 0 || arg > 9))
		ft_error(arg);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	base;

	sign = 1;
	i = 0;
	base = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			sign = sign * (-1); 
		}
		i++;
	}
	if (!str[i])
		ft_error(str[i]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		base = (base * 10) + (str[i] - 48);
		i++;
	}
	ft_isalpha(str[i]);
	return (base * sign);
}

/***********************************************************/

void ft_fill_with_one(t_stk *stk,int ac)
{
	int	i;

	stk->lis = malloc (sizeof(int) * (ac - 1));
	i = 0;
	while (i < stk->len_a)
	{
		stk->lis[i] = 1;
		i++;
	}
}
void	ft_fillsa(char *av[], int ac, t_stk *stc)
{
	int	j;
	int	i;

	stc->a = malloc((ac - 1) * sizeof(int));
	if (!stc->a)
		exit (0);
	stc->len_a = 0;
	j = 1;
	i = 0;
	while(av[j])
	{
		stc->a[i] = ft_atoi(av[j]);
		j++;
		i++;
		stc->len_a++;	
	}
	stc->len_b = 0;
	ft_fill_with_one(stc, ac);
}

/***********************************************************/

void	ft_sa(t_stk *stk)
{
	int tmp;
	int tmp1;

	tmp = stk->a[0];
	stk->a[0] = stk->a[1];
	stk->a[1] = tmp;
	printf ("sa\n");
}

/***********************************************************/

void	ft_sb(t_stk *stk)
{
	int tmp;
	int tmp1;

	tmp = stk->b[0];
	stk->b[0] = stk->b[1];
	stk->b[1] = tmp;
	printf ("sb\n");
}

/***********************************************************/

void	ft_ss(t_stk *stk)
{
	ft_sa(stk);
	ft_sb(stk);
	printf ("ss\n");
}

/***********************************************************/

void	ft_rra(t_stk *stk)
{
	int	tmp;
	int	i;

	i = stk->len_a;
	tmp = stk->a[stk->len_a - 1];
	while (i)
	{
		stk->a[i] = stk->a[i - 1];
		i--;
	}
	stk->a[0] = tmp;
	printf ("rra\n");
}

/***********************************************************/

void	ft_rrb(t_stk *stk)
{
	int	tmp;
	int	i;

	i = stk->len_b;
	tmp = stk->b[stk->len_b - 1];
	while (i)
	{
		stk->b[i] = stk->b[i - 1];
		i--;
	}
	stk->b[0] = tmp;
	printf ("rrb\n");
}

/***********************************************************/

void	ft_rrr(t_stk *stk)
{
	ft_rra(stk);
	ft_rrb(stk);
	printf ("rrr\n");
}

/***********************************************************/

void	ft_ra(t_stk *stk)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stk->a[0];
	while (i < stk->len_a)
	{
		stk->a[i] = stk->a[i + 1];
		i++;
	}
	stk->a[stk->len_a - 1] = tmp;
	printf ("ra\n");
}

/***********************************************************/

void	ft_rb(t_stk *stk)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stk->b[0];
	while (i < stk->len_b)
	{
		stk->b[i] = stk->b[i + 1];
		i++;
	}
	stk->b[stk->len_b - 1] = tmp;
	printf ("rb\n");
}

/***********************************************************/

void	ft_pa(t_stk *stk)
{
	int j;

	stk->len_b--;
	stk->len_a++;
	j = stk->len_a;
	while (j >= 0)
	{
		stk->a[j + 1] = stk->a[j];
		j--;
	}
	stk->a[0] = stk->b[0];
	j = 0;
	while (j < stk->len_b)
	{
		stk->b[j] = stk->b[j + 1];
		j++;
	}
	printf ("pa\n");
}

/***********************************************************/

void	ft_pb(t_stk *stk)
{
	int j;

	stk->len_b++;
	stk->len_a--;
	j = stk->len_b;
	while (j >= 0)
	{
		stk->b[j + 1] = stk->b[j];
		j--;
	}
	stk->b[0] = stk->a[0];
	j = 0;
	while (j < stk->len_a)
	{
		stk->a[j] = stk->a[j + 1];
		j++;
	}
	printf ("pb\n");
}

/***********************************************************/

// find the min number in my stack to start from it

void ft_find_min(t_stk *stk)
{
	int	i;
	int min;

	i = 0;
	min = stk->a[stk->min_index];
	while (i < stk->len_a)
	{
		if (stk->a[i] < min)
		{
			stk->min_index = i;
			min = stk->a[i];
		}
		i++;
	}
}

/***********************************************************/

void	ft_utils(t_stk	*stk)
{
	int	i;
	int	e;

	stk->maxlis = 0; //=> to store the max value in the lis
	stk->pos = 0; //=> to store the index of that value in the lis 
				  // equivalant in the stk->a
	i = -1;
	while (++i < stk->len_a)
		if (stk->maxlis < stk->lis[i])
		{
			stk->maxlis = stk->lis[i];
			stk->pos = i;
		}
	e = -1;
	//stk->c = 'N';
	printf ("\nmax = %d", stk->maxlis);
	stk->maxlis = stk->lis[stk->pos] + 1; // drna lih haka bach nstoki fih akbar value kayna f lis ozadt lih 1 3la 9bal lcondition li drt flta7t kaytchiki 
	//ila kan dakchi li kayjbad kolama n9st mno wa7ed khas ikon kaysawi dakchi li kan 9bal. exmpl: maxlis = 7+1 = 8 <=> 8 - 1 = 7
	while(++e <= stk->len_a)
	{
		if (stk->pos < 0)
			stk->pos = stk->len_a;
		if (stk->lis[stk->pos] == stk->maxlis - 1)
		{
			stk->maxlis = stk->lis[stk->pos];

			printf("lis = %d\n", stk->a[stk->pos]);
		}
		stk->pos--;
	}
}

void	ft_find_lis(t_stk *stk)
{
	int i; 
	int e;
	int	j;

	ft_find_min(stk);
	i = stk->min_index;
	e = -1;
	while (++e < stk->len_a)
	{
		j = i + 1;
		while (j != i && j < stk->len_a)
		{
			if (stk->a[i] > stk->a[j] && stk->lis[i] <= stk->lis[j] + 1)
				stk->lis[i] = stk->lis[j] + 1;
			j++;
			if (j == stk->len_a)
				j = 0;
		}
		i++;
		if (i == stk->len_a)
			i = 0;
	}
	ft_utils(stk);
}




int main(int ac,  char *av[])
{
	t_stk stk;

	ft_fillsa(av, ac, &stk);
	ft_find_lis(&stk);
}

/***********************************************************/

void	ft_algo(t_stk *stk, int ac)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (ac == 4)
	{
		/* if (stk->a[0] > stk->a[1] && stk->a[0] > stk->a[2])
			ft_ra(stk); */
		if (stk->a[0] > stk->a[1])
			ft_sa(stk);
		if (/* stk->a[0] < stk->a[1] &&  */stk->a[1] < stk->a[2])
		{
			//ft_sa(stk);
			ft_ra(stk);
		}
		if (stk->a[0] < stk->a[1] && stk->a[0] > stk->a[2])
			ft_rra(stk);
	}
	else if (ac > 4)
	{
	int k = stk->len_a;
		while (k)
		{
			if (stk->a[i] < stk->a[i + 1] && stk->b[j] < stk->b[j + 1] && stk->len_b)
				ft_ss(stk);

			else if (stk->a[i] < stk->a[i + 1])
				ft_sa(stk);

			else if (stk->b[j] < stk->b[j + 1])
				ft_sa(stk);

			else if (stk->b[j] < stk->b[stk->len_b] && stk->b[j] < stk->b[j + 1])
				ft_rb(stk);

			ft_pb(stk);
			//stk->len_a--;
			k--;
		}
	}
}




// int	main(int ac, char *av[])
// {
// 	//printf ("ff");
// 	t_stk	stk;
// 	//stk = (t_stk *)malloc(sizeof (t_stk *));
// 	int		*test;
// 	int		i = -1;
// 	// stk->len_b = 0;
// 	//stk.len_a = 0;
// 	stk.b = (int *)malloc(sizeof(int) * ac - 1);
	
// 	// stk = ft_sa(stk);
// 	ft_fillsa(av, ac, &stk);
// 	// ft_pb(&stk);
// 	// ft_pb(&stk);

// /* 	printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");

// 	printf ("len of stk_b = %d\n", stk.len_b);

// 	for (int k = 0 ; k < stk.len_b; k++)
// 		printf("stk.b[%d] = %d \n", k, stk.b[k]);

// 	printf("\n\n-------------------------------\n\n");

// 	printf ("len of stk_a = %d\n", stk.len_a);

// 	for (int k = 0 ; k < stk.len_a ; k++)
// 		printf("stk.a[%d] = %d \n",k, stk.a[k]);

// 	printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");

// 	ft_rra(&stk);
// 	ft_rra(&stk);
// 	ft_rra(&stk);
// 	printf ("len of stk_b = %d\n", stk.len_b);

// 	for (int k = 0 ; k < stk.len_b; k++)
// 		printf("stk.b[%d] = %d \n", k, stk.b[k]);

// 	printf("\n\n-------------------------------\n\n");

// 	printf ("len of stk_a = %d\n", stk.len_a);

// 	for (int k = 0 ; k < stk.len_a ; k++)
// 		printf("stk.a[%d] = %d \n",k, stk.a[k]); */

// 	int *tmp = ft_find_lis(&stk, ac);
// 	//ft_algo(&stk, ac);
// 	printf ("len of stk_a = %d\n", stk.len_a);

// 	for (int k = 0 ; k < 150; k++)
// 		printf("stk.a[%d] = %d \n",k, tmp[k]);


// }
