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

<command>        ::= <simple-command>

NOTE:
simple-command elements are stored in linked lists

<simple-command> ::= <redirection> <simple-command-tail>
                   | <word>    <simple-command-tail>

<simple-command-tail> ::= ε
                        | <redirection> <simple-command-tail>
                        | <word>    <simple-command-tail>

<redirection> 		  ::= <redirection-operator> <word>
```
