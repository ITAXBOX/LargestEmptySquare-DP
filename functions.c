#include "c_minded.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_free(char **result, int count_lines)
{
	int	i;

	i = 0;
	if (!result)
		return ;
	while (i < count_lines)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	count_first_line(char *path)
{
	int		fd;
	char	c;
	int		count;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1) > 0 && c != '\n')
		count++;
	close(fd);
	return (count);
}

char	*get_first_line(char *path)
{
	int		size;
	char	*first_line;
	int		fd;
	char	c;
	int		i;

	size = count_first_line(path);
	first_line = (char *)malloc(size + 1);
	if (!first_line)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (free(first_line), NULL);
	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
		first_line[i++] = c;
	first_line[i] = '\0';
	close(fd);
	return (first_line);
}

int	get_number_in_first_line(char *str)
{
	int	len;
	int	i;
	int	result;

	len = ft_strlen(str);
	i = 0;
	result = 0;
	if (len < 4)
		return (0);
	while (str[i] >= '0' && str[i] <= '9' && i < (len - 3))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i != len - 3)
		return (0);
	return (result);
}
