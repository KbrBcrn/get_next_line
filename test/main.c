/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:51:37 by kbeceren          #+#    #+#             */
/*   Updated: 2022/07/28 10:23:49 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	*ret1;
	char	*ret;
	char	*ret2;
	int		fd;
	size_t	i;

	fd = 0;
	fd = open("alone.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("OPEN ERROR\n");
		return (0);
	}
	i = 0;
	while (i < 20)
	{
		ret = get_next_line(fd);
		printf("str is %s\n", ret);
		free(ret);
		++i;
	}
	ret = get_next_line(fd);
	printf("%s", ret);
	ret1 = get_next_line(fd);
	printf("str is %s", ret1);
	ret2 = get_next_line(fd);
	printf("str is %s", ret2);
	close(fd);
	return (0);
}
