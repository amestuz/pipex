/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:09:38 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/11/04 21:28:48 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process(char **av, char **envp, int *fd)
{
	int		filein;

	filein = open(av[1], O_RDONLY, 0777);
	if (filein == -1)
	{
		error(EXIT_FAILURE);
	}
	dup2(filein, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(filein);
	execute(av[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		error(EXIT_FAILURE);
	dup2(fileout, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fileout);
	execute(argv[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (ac != 5)
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Example: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (0);
	}
	if (pipe(fd) == -1)
		error(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		error(EXIT_FAILURE);
	if (pid1 == 0)
		child_process(av, envp, fd);
	waitpid(pid1, NULL, 0);
	parent_process(av, envp, fd);
	close(fd[0]);
	close (fd[1]);
	return (0);
}

/*int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1, pid2;
	
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error(EXIT_FAILURE);
		pid1 = fork();
		if (pid1 == -1)
			error(EXIT_FAILURE);
		if (pid1 == 0)
			child_process(av, envp, fd);
		pid2 = fork();
		if (pid2 == -1)
			error(EXIT_FAILURE);
		if (pid2 == 0)
			parent_process(av, envp, fd);
		close(fd[0]);
		close (fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Example: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}*/
/*int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error(EXIT_FAILURE);
		pid1 = fork();
		if (pid1 == -1)
			error(EXIT_FAILURE);
		if (pid1 == 0)
			child_process(av, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(av, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Example: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}*/
