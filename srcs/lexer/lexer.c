#include "../../includes/minishell.h"

// 	char *line =  "'echo' "cd"     >> amalia  >>b>>c<t<o>p<<t<<u ls <t >u -la";
// 	char *line =  "'echo' "cd"";

t_token *create_token(char *str)
{
    int     i;
    t_token *tmp;
    t_token *val;

    i = 0;
    tmp = ft_lstnew("Number", 10);
    while (str[i])
    {
        if (is_redirect_in(str[i]))
        {
            val = ft_lstnew("RED_IN", RED_IN);
            ft_lstadd_back(&tmp, val);
        }
        else if (is_redirect_out(str[i]))
        {
            val = ft_lstnew("RED_OUT", RED_OUT);
            ft_lstadd_back(&tmp, val);
        }
        else if (is_pipe(str[i]))
        {
            val = ft_lstnew("PIPE", PIPE);
            ft_lstadd_back(&tmp, val);
        }
        else if (is_space(str[i]))
        {
            val = ft_lstnew("SPACE", SEP);
            ft_lstadd_back(&tmp, val);
        }
        // else
        // {
        //     val = ft_lstnew("WORD", WORD);
        // }
        // printf("i = %d\n", i);
        // ft_lstadd_back(&tmp, val);
        // printf("i = %d\n", i);
        i++;
    }
    return (tmp);
}
