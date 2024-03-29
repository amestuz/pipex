/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:53:19 by uurbizu-          #+#    #+#             */
/*   Updated: 2024/03/29 19:36:43 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	usage(void)
{
	ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex \"here_doc\" <LIMITER> <cmd>\
	<cmd1> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
	{
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	else if (i == 1)
	{
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	else if (i == 2)
	{
		file = open(argv, O_RDONLY, 0644);
		dup2(file, STDIN_FILENO);
		close(file);
	}
	if (file == -1)
		error(EXIT_FAILURE);
	return (file);
}

int	get_next_line_pipex(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = ft_strdup(buffer);
	free(buffer);
	return (r);
}
