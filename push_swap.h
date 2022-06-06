# ifndef  PUSH_SWAP_H
# define  PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stk{
	int	*a;
	int *lis;
	int *tmp;
	int *b;
	int min_index;
	int len_a;
	int len_b;
	int maxlis;
	int maxp;
	int pos;
	int *s; // db fach kancomenti had line li zadt kaykhdam mz1 ila rj3to kaysegfaulti 
}   t_stk;

#endif
