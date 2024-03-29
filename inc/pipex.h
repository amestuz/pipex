/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:51:10 by uurbizu-          #+#    #+#             */
/*   Updated: 2023/11/07 18:21:12 by uurbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

/* ---------- Mandatory functions --------- */
//pipex.c
void	child_process(char **av, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
//utils_pipex.c
void	error(int er);
char	*find_path(char *cmd, char **envp);
void	execute(char *avi, char **envp);

/* --------- Bonus functions --------- */
//pipex_bonus.c
void	child_process_bonus(char *argv, char **envp);
void	here_doc(char *limiter);
//utils_pipex_bonus.c
void	usage(void);
int		open_file(char *argv, int i);
int		get_next_line_pipex(char **line);

#endif
