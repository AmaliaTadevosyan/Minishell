#include "../../includes/minishell.h"

// 	char *line =  "'echo' "cd"     >> amalia  >>b>>c<t<o>p<<t<<u ls <t >u -la";
// 	char *line =  "'echo' "cd"";
void    create_token(t_token *token, char *str)
{
    int     i;
    t_token *tmp; 

    tmp = token;
    i = 0;
    while (str[i])
    {
        if (is_redirect_in(str[i]))
        {
            token->type = "Red_IN";
            token->value = RED_IN;
            ft_lstadd_back(&tmp, token);
        }
        else if (is_redirect_out(str[i]))
        {
            token->type = "RED_OUT";
            token->value = RED_OUT;
            ft_lstadd_back(&tmp, token);
            // token = token->next;
        }
        else if (is_pipe(str[i]))
        {
            token->type = "PIPE";
            token->value = PIPE;
            ft_lstadd_back(&tmp, token);
            // token = token->next;
        }
        else if (is_space(str[i]))
        {
            token->type = "SPACE";
            token->value = SEP;
            ft_lstadd_back(&tmp, token);
            // token = token->next;
        }
        token = token->next;
        i++;
    }
}
