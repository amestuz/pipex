# pipex
42 Scholl project repository

Code a C program that replicates the behaviour of pipes in shell
Aimed to better understand shell redirection and pipes.

Pipex takes an input file, performs a command on it, pipes the result to another command which then writes its result to an output file.
 The result is virtually identical to this kind of shell command:
$ < input_file command1 | command2 > output file

The bonus handles multiple pipes and heredoc redirection.