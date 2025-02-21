#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				num;
}	t_stack;

void			free_stack(t_stack **ss);
int				init_stack(t_stack **aa, t_stack **bb);
int				pill_stack(t_stack **aa, int argc, char *argv[]);
int				push_swap(t_stack **aa, t_stack **bb);

int				is_valid_args(int argc, char *argv[]);

void			sa(t_stack **aa);
void			sb(t_stack **bb);
void			ss(t_stack **aa, t_stack **bb);

void			pa(t_stack **aa, t_stack **bb);
void			pb(t_stack **aa, t_stack **bb);

void			ra(t_stack **aa);
void			rb(t_stack **bb);
void			rr(t_stack **aa, t_stack **bb);

void			rra(t_stack **aa);
void			rrb(t_stack **bb);
void			rrr(t_stack **aa, t_stack **bb);

int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);
long long int	ft_atolli(const char *nptr);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
#endif
