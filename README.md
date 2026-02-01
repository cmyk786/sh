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
```
<pipeline> ::= <command> <pipeline-tail>  
<pipeline-tail> ::= epsilon | <PIPE> <command> <pipeline-tail>

NOTE:
simple-command elements is a linked list
<command> ::= <simple-command>
```
