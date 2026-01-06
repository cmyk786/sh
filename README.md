# sh

# Module Assignments  
Readline input - yiwei  
Signals - yiwei  
Tokenizer/Lexer - joloo  
Heredoc - joloo  
Parsing - joloo  
Wildcards  
Environment variables - joloo  
Environment variable expansion - joloo  
Execution - yiwei  
Built-ins - yiwei  

# Parser BNF
`<list> ::= <pipeline> <list-tail>  
<list-tail> ::= epsilon | <AND> <pipeline> <list-tail> | <OR> <pipeline> <list-tail>

<pipeline> ::= <command> <pipeline-tail>  
<pipeline-tail> ::= epsilon | <PIPE> <command> <pipeline-tail>

NOTE:
simple-command built iteratively in code
<command> ::= <simple-command> | <grouping>

<grouping>   ::= <OP> <list> <CP> <redirections>
`