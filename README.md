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
<pipeline>      ::= <command> <pipeline-tail>

<pipeline-tail>  ::= ε
                  | <PIPE> <command> <pipeline-tail>

NOTE:
simple-command elements are stored in a linked list

<command>        ::= <simple-command>

<simple-command> ::= <redirection> <simple-command-tail>
                   | <argument>    <simple-command-tail>

<simple-command-tail> ::= ε
                        | <redirections> <simple-command-tail>
                        | <arguments>    <simple-command-tail>
```
