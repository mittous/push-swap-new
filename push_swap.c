
#include <stdio.h>

#include "push_swap.h"

/***********************************************************/

void ft_error(char arg)
{
	printf("error in the character '%c' was not digit", arg);
	exit(0);
}

int ft_isalpha(char arg)
{
	if (arg != ' ' && (arg < 0 || arg > 9))
		ft_error(arg);
	return (0);
}

int ft_atoi(const char *str)
{
	int i;
	int sign;
	int base;

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

void ft_fill_with_one(t_stk *stk, int ac)
{
	int i;

	stk->lis = malloc(sizeof(int) * (ac - 1));
	i = 0;
	while (i < stk->len_a)
	{
		stk->lis[i] = 1;
		i++;
	}
}
void ft_fillsa(char *av[], int ac, t_stk *stc)
{
	int j;
	int i;

	stc->a = malloc((ac - 1) * sizeof(int));
	if (!stc->a)
		exit(0);
	stc->len_a = 0;
	j = 1;
	i = 0;
	while (av[j])
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

void ft_sa(t_stk *stk)
{
	int tmp;

	tmp = stk->a[0];
	stk->a[0] = stk->a[1];
	stk->a[1] = tmp;
	printf("sa\n");
}

/***********************************************************/

void ft_sb(t_stk *stk)
{
	int tmp;

	tmp = stk->b[0];
	stk->b[0] = stk->b[1];
	stk->b[1] = tmp;
	printf("sb\n");
}

/***********************************************************/

void ft_ss(t_stk *stk)
{
	ft_sa(stk);
	ft_sb(stk);
	printf("ss\n");
}

/***********************************************************/

void ft_rra(t_stk *stk)
{
	int tmp;
	int i;

	i = stk->len_a;
	tmp = stk->a[stk->len_a - 1];
	while (i)
	{
		stk->a[i] = stk->a[i - 1];
		i--;
	}
	stk->a[0] = tmp;
	printf("rra\n");
}

/***********************************************************/

void ft_rrb(t_stk *stk)
{
	int tmp;
	int i;

	i = stk->len_b;
	tmp = stk->b[stk->len_b - 1];
	while (i)
	{
		stk->b[i] = stk->b[i - 1];
		i--;
	}
	stk->b[0] = tmp;
	printf("rrb\n");
}

/***********************************************************/

void ft_rrr(t_stk *stk)
{
	int tmp;
	int i;

	i = stk->len_b;
	tmp = stk->b[stk->len_b - 1];
	while (i)
	{
		stk->b[i] = stk->b[i - 1];
		i--;
	}
	stk->b[0] = tmp;
	i = stk->len_a;
	tmp = stk->a[stk->len_a - 1];
	while (i)
	{
		stk->a[i] = stk->a[i - 1];
		i--;
	}
	stk->a[0] = tmp;
	printf("rrr\n");
}

/***********************************************************/

void ft_ra(t_stk *stk)
{
	int tmp;
	int i;

	i = 0;
	tmp = stk->a[0];
	while (i < stk->len_a)
	{
		stk->a[i] = stk->a[i + 1];
		i++;
	}
	stk->a[stk->len_a - 1] = tmp;
	printf("ra\n");
}

/***********************************************************/

void ft_rb(t_stk *stk)
{
	int tmp;
	int i;

	i = 0;
	tmp = stk->b[0];
	while (i < stk->len_b)
	{
		stk->b[i] = stk->b[i + 1];
		i++;
	}
	stk->b[stk->len_b - 1] = tmp;
	printf("rb\n");
}


/***********************************************************/

void ft_rr(t_stk *stk)
{
	int tmp;
	int i;

	i = 0;
	tmp = stk->b[0];
	while (i < stk->len_b)
	{
		stk->b[i] = stk->b[i + 1];
		i++;
	}
	stk->b[stk->len_b - 1] = tmp;
	i = 0;
	tmp = stk->a[0];
	while (i < stk->len_a)
	{
		stk->a[i] = stk->a[i + 1];
		i++;
	}
	stk->a[stk->len_a - 1] = tmp;
	printf("rr\n");
}

/***********************************************************/

void ft_pa(t_stk *stk)
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
	printf("pa\n");
}

/***********************************************************/

void ft_pb(t_stk *stk)
{
	int j;

	stk->len_b++;
	stk->len_a--;
	j = stk->len_b;
	while (j >= 0)
	{
		stk->b[j + 1] = stk->b[j];
		j--;
		// printf ("ha7na\n");
	}
	stk->b[0] = stk->a[0];
	j = 0;
	while (j < stk->len_a)
	{
		stk->a[j] = stk->a[j + 1];
		j++;
	}
	printf("pb\n");
}

/***********************************************************/

// find the min number in my stack to start from it

int ft_find_min(t_stk *stk, int *a, int len)
{
	int i;
	int min;

	i = 0;
	min = a[0];
	while (i < len)
	{
		if (a[i] <= min)
		{
			stk->min_index = i;
			min = a[i];
		}
		i++;
	}
	return (min);
}

/***********************************************************/

void ft_utils(t_stk *stk)
{
	int i;
	int e;

	stk->maxlis = 0; //=> to store the max value in the lis
	stk->pos = 0;	 //=> to store the index of that value in the lis
					 // equivalant in the stk->a
	i = -1;
	while (++i < stk->len_a)
		if (stk->maxlis < stk->lis[i])
		{
			stk->maxlis = stk->lis[i];
			stk->pos = i;
		}
	//printf("%d")
	e = -1;
	stk->lis_a = malloc(sizeof(int) * stk->maxlis-1);
	stk->maxp = stk->lis[stk->pos] + 1; // drna lih haka bach nstoki fih akbar value kayna f lis ozadt lih 1 3la 9bal lcondition li drt flta7t kaytchiki
	// ila kan dakchi li kayjbad kolama n9st mno wa7ed khas ikon kaysawi dakchi li kan 9bal. exmpl: maxp = 7+1 = 8 <=> 8 - 1 = 7
	i = 0;
	while (++e < stk->len_a)
	{
		if (stk->pos == -1)
			stk->pos = stk->len_a - 1;
		if (stk->lis[stk->pos] == stk->maxp - 1)
		{
			stk->maxp = stk->lis[stk->pos];
			stk->lis_a[i] = stk->a[stk->pos];
			//printf ("%d\n", stk->lis_a[i]);
			i++;
		}
		stk->pos--;
	}
	//printf ("---++++----+++%d\n", stk->lis_a[15]);
	//puts ("-==-=-=--=-=-=-=--=-=-=-=-=-=-=-");
	int t = 0;
	i = stk->len_a + 1;
	while (--i)
	{
		t = 0;
		while (t < stk->maxlis)
		{
			if (stk->a[0] == stk->lis_a[t])
			{
				// printf ("%d\n", stk->a[0]);
				// printf ("%d\n", t);
				ft_rr(stk);
				break;
			}
			if (t == stk->maxlis - 2)
				ft_pb(stk);
			t++;
		}
	}
	// t=0;

	// while (t < i)
	// {
	// 	printf ("%d\n",stk->lis_a[t]);
	// 	t++;
	// }
	// puts ("-==-=-=--=-=-=-=--=-=-=-=-=-=-=-");
}

void ft_find_lis(t_stk *stk)
{
	int i;
	int e;
	int j;

	ft_find_min(stk, stk->a, stk->len_a);
	i = stk->min_index;
	e = -1;
	while (++e < stk->len_a)
	{
		j = i + 1;
		if (j == stk->len_a) // we add that condition whene i reach the end os stk
			j = 0; // then j must returned to 0 and contunue her job
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
	// i = 0;
	// while (i < stk->len_a)
	// {
	// 	printf ("%d,", stk->lis[i]);
	// 	i++;
	// }
	// puts ("\n");
	ft_utils(stk);
}

/***********************************************************/
// this function is to konw the right position
// for nb in sb to sa

int ft_right_pos(t_stk *stk, int sb_nb)
{
	int i;
	int old;

	old = stk->a[stk->len_a - 1];
	i = 0;
	while (i < stk->len_a)
	{
		if (sb_nb < stk->a[i])
		{
			if (sb_nb > old)
				return (i);
		}
		old = stk->a[i];
		i++;
	}
	ft_find_min(stk, stk->a, stk->len_a);
	return (stk->min_index);
}

/***********************************************************/
// this function let me know what moves to do with my nbrs

void ft_find_bm(t_stk *stk)
{
	int i;
	int posb;
	int posa;
	int rslt;

	i = 0;
	posb = -1;
	rslt = 0;
	while (++posb < stk->len_b)
	{
		posa = ft_right_pos(stk, stk->b[posb]);

		if (posb >= (stk->len_b / 2) && posa >= (stk->len_a / 2))
		{
			rslt = (stk->len_a - posa) - (stk->len_b - posb);
			if (rslt >= 0)
				stk->best_move[i] = rslt + (stk->len_b - posb);
			if (rslt < 0)
				stk->best_move[i] = (rslt * -1) + (stk->len_a - posa);
		}

		else if (posb <= (stk->len_b / 2) && posa <= (stk->len_a / 2))
		{
			rslt = (posa) - (posb);
			if (rslt >= 0)
				stk->best_move[i] = rslt + (posb);
			if (rslt < 0)
				stk->best_move[i] = (rslt * -1) + (posa);
		}

		else if ((posa <= stk->len_a / 2) && (posb >= stk->len_b / 2))
		{
			stk->best_move[i] = ((stk->len_b - posb) + posa);
		}

		else if ((posa >= stk->len_a / 2) && (posb <= stk->len_b / 2))
		{
			stk->best_move[i] = ((stk->len_a - posa) + posb);
		}
		i++;
	}

	ft_find_min(stk, stk->best_move, stk->len_b);
	posa = ft_right_pos(stk, stk->b[stk->min_index]);
	ft_find_min(stk, stk->best_move, stk->len_b);
	posb = stk->min_index;

	i = 0;
	if (posb >= (stk->len_b / 2) && posa >= (stk->len_a / 2))
	{
		rslt = (stk->len_a - posa) - (stk->len_b - posb);
		if (rslt >= 0)
		{
			while (i < (stk->len_b - posb))
			{
				ft_rrr(stk);
				i++;
			}
			i = 0;
			while(i < rslt)
			{
				ft_rra(stk);
				i++;
			}
		}
		if (rslt < 0)
		{
			while(i < (stk->len_a - posa))
			{
				ft_rrr(stk);
				i++;
			}
			i = 0;
			while(i < (rslt * -1))
			{
				ft_rrb(stk);
				i++;
			}
		}
		ft_pa(stk);
	}


	else if (posb <= (stk->len_b / 2) && posa <= (stk->len_a / 2))
	{
		rslt = (posa) - (posb);
		if (rslt >= 0)
		{
			while(i < posb)
			{
				ft_rr(stk);
				i++;
			}
			i = 0;
			while(i < rslt)
			{
				ft_ra(stk);
				i++;
			}
		}
		if (rslt < 0)
		{
			while(i < posa)
			{
				ft_rr(stk);
				i++;
			}
			i = 0;
			while(i < (rslt * -1))
			{
				ft_rb(stk);
				i++;
			}
		}
	ft_pa(stk);
	}


	else if ((posa <= stk->len_a / 2) && (posb >= stk->len_b / 2))
	{
		while(i < posa)
		{
			ft_ra(stk);
			i++;
		}
		i = 0;
		while(i < (stk->len_b - posb))
		{
			ft_rrb(stk);
			i++;
		}
	ft_pa(stk);
	}

	else if ((posa >= stk->len_a / 2) && (posb <= stk->len_b / 2))
	{
		while(i < posb)
		{
			ft_rb(stk);
			i++;
		}
		i = 0;
		while(i < (stk->len_a - posa))
		{
			ft_rra(stk);
			i++;
		}
	ft_pa(stk);
	}
}

/***********************************************************/

void ft_algo(t_stk *stk)
{
	int i = 0;
	i = stk->len_b;
	while (i)
	{
		ft_find_bm(stk);
		i--;
	}
}
/***********************************************************/
void	ft_algo_of_tree(t_stk *stk, int ac)
{

	if (ac == 4)
	{
		if (stk->a[0] > stk->a[1] && stk->a[0] > stk->a[2])
			ft_ra(stk);
		if (stk->a[0] > stk->a[1])
			ft_sa(stk);
		if (stk->a[0] < stk->a[1] && stk->a[1] < stk->a[2])
		{
			ft_sa(stk);
			ft_ra(stk);
		}
		if (stk->a[0] < stk->a[1] && stk->a[0] > stk->a[2])
			ft_rra(stk);
	}
}

int main(int ac, char *av[])
{
	t_stk stk;

	stk.b = (int *)malloc(sizeof(int) * ac);

	ft_fillsa(av, ac, &stk);
	if (ac == 4)
		ft_algo_of_tree(&stk, ac);
	else
	{
		ft_find_lis(&stk);
		stk.best_move = malloc(sizeof(int) * stk.len_b);
		ft_algo(&stk);

		int min = ft_find_min(&stk, stk.a, stk.len_a);
		while (stk.a[0] != min)
		{
			if (stk.min_index <= stk.len_a / 2)
				ft_ra(&stk);
			else
				ft_rra(&stk);
		}
	}
	// puts ("+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+");
	// int min = 0;
	// while (min < stk.len_a)
	// {
	// 	printf ("%d\n", stk.a[min]);
	// 	min++;
	// }
	
}


/***********************************************************/
// void	ft_algo(t_stk *stk, int ac)
// {
// 	int	i;
// 	int	j;
	
// 	i = 0;
// 	j = 0;
// 	if (ac == 4)
// 	{
// 		/* if (stk->a[0] > stk->a[1] && stk->a[0] > stk->a[2])
// 			ft_ra(stk); */
// 		if (stk->a[0] > stk->a[1])
// 			ft_sa(stk);
// 		if (/* stk->a[0] < stk->a[1] &&  */stk->a[1] < stk->a[2])
// 		{
// 			//ft_sa(stk);
// 			ft_ra(stk);
// 		}
// 		if (stk->a[0] < stk->a[1] && stk->a[0] > stk->a[2])
// 			ft_rra(stk);
// 	}
// 	else if (ac > 4)
// 	{
// 	int k = stk->len_a;
// 		while (k)
// 		{
// 			if (stk->a[i] < stk->a[i + 1] && stk->b[j] < stk->b[j + 1] && stk->len_b)
// 				ft_ss(stk);

// 			else if (stk->a[i] < stk->a[i + 1])
// 				ft_sa(stk);

// 			else if (stk->b[j] < stk->b[j + 1])
// 				ft_sa(stk);

// 			else if (stk->b[j] < stk->b[stk->len_b] && stk->b[j] < stk->b[j + 1])
// 				ft_rb(stk);

// 			ft_pb(stk);
// 			//stk->len_a--;
// 			k--;
// 		}
// 	}
// }




// int	main(int ac, char *av[])
// {
// 	//printf ("ff");
// 	t_stk	stk;
// 	//stk = (t_stk *)malloc(sizeof (t_stk *));
// 	int		*test;
// 	int		i = -1;
// 	// stk->len_b = 0;
// 	//stk.len_a = 0;
	
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
