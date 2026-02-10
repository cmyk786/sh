int ex(t_ast *node, t_env **env)
{
    if (!node)
        return (1);
    if (node->type == SIMPLE_CMD)
        return (ex_cmd(node, env));
    if (node->type == PIPELINE)
        return (ex_pipe(node, env));
    return (1);
}