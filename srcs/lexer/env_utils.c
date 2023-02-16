#include "../../includes/minishell.h"

int init_env(t_data *data, char **envp)
{
    int i;
    t_env *first_node;
    char **split_env;

    data->env = malloc(sizeof(t_env));
    first_node = data->env;
    i = 0;
    while (envp[i])
    {
        split_env = ft_split(envp[i], '=');
        data->env->key = split_env[0];
        data->env->value = split_env[1];
        if (!envp[i + 1])
            break;
        data->env->next = malloc(sizeof(t_env));
        data->env = data->env->next;
        i++;
    }
    data->env = first_node;
    return (0);
}

char *get_env_value(char *key, t_data *data)
{
    while (data->env)
    {
        if (ft_strcmp(key, data->env->key) == 0)
        {
            return (data->env->value);
        }   
        data->env = data->env->next;
    }
    return ("No such key!");
}