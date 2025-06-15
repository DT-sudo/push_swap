// #include "push_swap.h"
// # include <limits.h>
// # include <stdbool.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>


// int	main(void)
// {
// 	t_nums *h1, *h2;
// 	t_nums *a, *b, *c, *aa, *bb, *cc;
// 	int z, x, y, zz, xx, yy;

// 	z = 10;
// 	x = 20;
// 	y = 30;
// 	zz = 110;
// 	xx = 220;
// 	yy = 330;
// 	a = do_node(z);
// 	b = do_node(x);
// 	c = do_node(y);
// 	aa = do_node(zz);
// 	bb = do_node(xx);
// 	cc = do_node(yy);
// 	a->next = b;
// 	b->next = c;
// 	aa->next = bb;
// 	bb->next = cc;

// 	h1 = a;
// 	h2 = aa;
// 	while (h1 != NULL)
// 	{
// 		printf("%d -> ", (h1)->number);
// 		h1 = (h1)->next;
// 	}
// 	printf("\n");
// 	while (h2 != NULL)
// 	{
// 		printf("%d -> ", (h2)->number);
// 		h2 = (h2)->next;
// 	}
// 	h1 = a;
// 	h2 = aa;
// 	pa(&h1, &h2);
// 	printf("\n");
// 	printf("\n");
// 	while (h1 != NULL)
// 	{
// 		printf("%d -> ", (h1)->number);
// 		h1 = (h1)->next;
// 	}
// 	printf("\n");
// 	while (h2 != NULL)
// 	{
// 		printf("%d -> ", (h2)->number);
// 		h2 = (h2)->next;
// 	}
// 	return (0);
// }
// int main(void)
// {
//     int i = 1;

//     while(i != 10)
//     {
//         i += 1;
//         printf("%d\n", i);
//     }
// }

// void	three_sort(t_nums **a)
// {
// 	t_nums	*biggest;
// 	t_nums	*tmp;

// 	tmp = *a;
// 	biggest = find_biggest_number(*a);
// 	set_stack_parametrs(*a); 							//!!
// 	// /////////////// testing
// 	// printf("%d is on position: %d top_price: %d , first_half: %d\n", (*a)->number,(*a)->position, (*a)->top_price, (*a)->first_half);
// 	// printf("%d is on position: %d top_price: %d , first_half: %d\n", ((*a)->next)->number, ((*a)->next)->position, ((*a)->next)->top_price, ((*a)->next)->first_half);
// 	// printf("%d is on position: %d top_price: %d , first_half: %d\n", find_last_num(*a)->number, find_last_num(*a)->position, find_last_num(*a)->top_price, find_last_num(*a)->first_half);
// 	// /////////////// testing
// 	if (biggest->position == 0)
// 		ra(a);
// 	else if (biggest->position == 1)
// 		rra(a);
// 	set_stack_parametrs(*a);							//!!
// 	if ((*a)->number > ((*a)->next)->number)
// 		sa(a);
// 	tmp = *a;
// 	while(tmp != NULL)
//     {
//         printf("%d -> ", (tmp)->number);
//         tmp = (tmp)->next;
//     }
//     printf("\n");
// }
///////////////////////////////////////////////

// #include "push_swap.h"

// int main(void)
// {
//     int *p;
//     int **pp;
//     int v;

//     v = 12;
//     p = &v;
//     pp = &p;
//     printf("adres of v with pointer: %p\nadres of v with &v: %p\nadres of v with double pointer: %p\n", p, &v, *pp);
//     printf("value of v with pointer: %d\nvalue of v with &v: %d\nvalue of v with double pointer: %d", *p, v, **pp);
//     return(0);
// }

// // creat new node
// t_nums	*new_num(int num)
// {
// 	t_nums	*p;

// 	p = malloc(sizeof(t_nums));
// 	if (!p)
// 		return (NULL);
// 	p->number = num;
// 	p->next = NULL;
//     return (p);
// }

// //
// t_nums	*find_last_num(t_nums *lst)
// {
//     while(lst->next != NULL)
//         lst = lst->next;
//     return (lst);
// }

// void	append_num(t_nums **head, t_nums *num_to_add)
// {
//     if (!num_to_add)
//         return;
//     if (!*head)
//     {
//         *head = num_to_add;
//         return;
//     }
//     find_last_num(*head)->next = num_to_add;
// }

// void f(t_nums *s)
// {
//     printf("%d\n", s->number);
// }

// void prft_n(t_nums *lst, void(*f)(t_nums *))
// {
//     while(lst != NULL)
//     {
//         f(lst);
//         lst = lst->next;
//     }
// }

// int	main(int argc, char **argv)
// {
//     t_nums **head;
//     t_nums *n, *m, *k;
//     int  a, b, c, i;

//     i = 0;
//     a = 10;
//     b = 20;
//     c = 30;
//     n = new_num(a);
//     head = &n;
//     m = new_num(b);
//     k = new_num(c);
//     append_num(head, m);
//     append_num(head, k);
//     prft_n(*head, f);
//     return (0);
// }

// // // // // // // // // // // // // // // // // // // // // // // // // //

// void ichange_ptr(int *a, int *b)
// {
//     int tmp;

//     tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// void change_ptr(int **a, int **b)
// {
//     int **tmp;

//     *tmp = *a;
//     *a = *b;
//     *b = *tmp;
// }

// int main(void)
// {
//     int *a, *b;
//     int aa = 10;
//     int bb = 20;

//     a = &aa;
//     b = &bb;
//     printf("a:%d, b:%d\na:%p, b:%p\n", *a, *b, a, b);
//     ichange_ptr(a, b);
//     printf("a:%d, b:%d\na:%p, b:%p\n", *a, *b, a, b);
//     change_ptr(&a, &b);
//     printf("a:%d, b:%d\na:%p, b:%p\n", *a, *b, a, b);
//     return (0);
// }


//////////////

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_nums
{
	int				number;
	struct s_nums	*next;
}					t_nums;

t_nums	*do_node(int number)
{
	t_nums	*node;

	node = malloc(sizeof(t_nums));
	if (!node)
		exit(0);
	node->number = number;
	node->next = NULL;
	return (node);
}

void rra(t_nums **a)
{
    t_nums *lust;
    t_nums *before_lust;
    int i;

    i = -1;
    lust = *a;
    before_lust = *a;
    while (lust->next != NULL)
    {
        lust = lust->next;
        i++;
    }
    while (i--)
        before_lust = before_lust->next;
    before_lust->next = NULL;
    lust->next = *a;
    *a = lust; 
	// write(1, "rra\n", 4);
    // set_position(*a);
}

int main(void)
{
    t_nums *h;
    t_nums *a, *b,*c;
    int z, x, y;

    z = 10;
    x = 20;
    y = 30;
    a = do_node(z);
    b = do_node(x);
    c = do_node(y);
    a->next = b;
    b->next = c;
    h = a;
    while(h != NULL)
    {
        printf("%d -> ", (h)->number);
        h = (h)->next;
    }
    printf("\n");
    h = a;
    rra(&h);
    while(h != NULL)
    {
        printf("%d -> ", (h)->number);
        h = (h)->next;
    }    
    return 0;
}

// / /////

// #include <limits.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// typedef struct s_nums
// {
// 	int				number;
// 	struct s_nums	*next;
// }					t_nums;

// t_nums	*do_node(int number)
// {
// 	t_nums	*node;

// 	node = malloc(sizeof(t_nums));
// 	if (!node)
// 		exit(0);
// 	node->number = number;
// 	node->next = NULL;
// 	return (node);
// }

// void rra(t_nums **a)
// {
//     t_nums *lust;
//     t_nums *before_lust;
//     int i;

//     i = -1;
//     lust = *a;
//     before_lust = *a;
//     while (lust->next != NULL)
//     {
//         lust = lust->next;
//         i++;
//     }
//     while (i--)
//         before_lust = before_lust->next;
//     before_lust->next = NULL;
//     lust->next = *a;
//     *a = lust; 
// }
// void	rra(t_nums **a)
// {
// 	t_nums	*lust;
// 	t_nums	*before_lust;
// 	int		i;

// 	i = -1;
// 	lust = *a;
// 	before_lust = *a;
// 	while (lust->next != NULL)
// 	{
// 		lust = lust->next;
// 		i++;
// 	}
// 	while (i--)
// 		before_lust = before_lust->next;
// 	before_lust->next = NULL;
// 	lust->next = (*a)->next;
// 	*a = lust;
// 	write(1, "rra\n", 4);
// }

// int main(void)
// {
//     t_nums *h;
//     t_nums *a, *b,*c;
//     int z, x, y;

//     z = 1;
//     x = 3;
//     y = 2;
//     a = do_node(z);
//     b = do_node(x);
//     c = do_node(y);
//     a->next = b;
//     b->next = c;
//     h = a;
//     while(h != NULL)
//     {
//         printf("%d -> ", (h)->number);
//         h = (h)->next;
//     }
//     printf("\n");
//     h = a;
//     rra(&h);
//     while(h != NULL)
//     {
//         printf("%d -> ", (h)->number);
//         h = (h)->next;
//     }    
//     return 0;
// }
