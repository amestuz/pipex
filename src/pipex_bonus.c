/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:50:13 by uurbizu-          #+#    #+#             */
/*   Updated: 2024/03/29 19:40:39 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process_bonus(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		error(EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
	close(fd[0]);
	close(fd[1]);
}

void	write_line(char *limiter, int fd1)
{
	char	*line;

	while (get_next_line_pipex(&line))
	{
		if (ft_strncmp(line, limiter, (ft_strlen(line) - 1)) == 0)
		{
			close(fd1);
			exit(EXIT_SUCCESS);
		}
		write(fd1, line, ft_strlen(line));
		free(line);
	}
	close(fd1);
}

void	here_doc(char *limiter)
{
	pid_t	reader;
	int		fd[2];
	int		fd1;

	if (pipe(fd) == -1)
		error(EXIT_FAILURE);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		fd1 = fd[1];
		write_line(limiter, fd1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(reader, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	ftype;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			if (argc < 6)
				usage();
			i = 3;
			ftype = 0;
			here_doc(argv[2]);
		}
		else
		{
			i = 2;
			ftype = 1;
			open_file(argv[1], 2);
		}
		while (i < argc - 2)
			child_process_bonus(argv[i++], envp);
		open_file(argv[argc - 1], ftype);
		execute(argv[argc - 2], envp);
	}
	usage();
}
