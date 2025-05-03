#include "c_minded.h"

int	validate_first_line_chars(char *first_line)
{
	int		len;
	char	empty;
	char	obstacle;
	char	full;

	len = ft_strlen(first_line);
	if (len < 4)
		return (0);
	empty = first_line[len - 3];
	obstacle = first_line[len - 2];
	full = first_line[len - 1];
	if (empty == obstacle || empty == full || obstacle == full)
		return (0);
	if (empty <= 32 || obstacle <= 32 || full <= 32)
		return (0);
	if (empty == 127 || obstacle == 127 || full == 127)
		return (0);
	return (1);
}

int	validate_map_content(char **map, int line_count, char empty, char obstacle)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	if (!map || line_count <= 0 || !map[0])
		return (0);
	i = 0;
	while (i < line_count)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != empty && map[i][j] != obstacle)
				return (0);
			if (map[i][j] == empty)
				counter++;
			j++;
		}
		i++;
	}
	return (counter != 0);
}

char	**ft_get_map(char *path, int count_lines, char *first_line)
{
	char	**map;

	map = ft_get_inputs(path, count_lines);
	if (!map)
		return (free(first_line), NULL);
	if (!validate_map_content(map, count_lines,
			first_line[ft_strlen(first_line) - 3],
			first_line[ft_strlen(first_line) - 2]))
	{
		ft_free(map, count_lines);
		return (free(first_line), NULL);
	}
	return (map);
}

char	**validate_inputs(char *path)
{
	int		fd;
	char	*first_line;
	int		expected_lines;
	int		count_lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	first_line = get_first_line(path);
	if (!first_line || !validate_first_line_chars(first_line))
		return (close(fd), free(first_line), NULL);
	expected_lines = get_number_in_first_line(first_line);
	if (expected_lines <= 0)
		return (close(fd), free(first_line), NULL);
	count_lines = get_nb_of_rows(fd);
	close(fd);
	if (count_lines != expected_lines)
		return (free(first_line), NULL);
	return (ft_get_map(path, count_lines, first_line));
}
