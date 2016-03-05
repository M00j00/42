/**
 * @todo:
 * header 42
 * ?linked list pour sauver les char lus non cpd? a voir
 * 42filechecker
 * valgrind
 * deplacer main test
 * rechecker tout encore et encore
**/

#include "get_next_line.h"

static int		get_line_len(int fd, t_storage *s)
{
	int					i;

	i = 0;
	while (s->memory[fd][i] != '\n' && s->memory[fd][i] != '\0')
		i++;
	return (i);
}

static void		read_next_line(int fd , t_storage *s)
{
	char				*tmp;

	if (!(s->memory[fd]))
		s->memory[fd] = ft_strnew(1);
	while (!(ft_strchr(s->memory[fd], '\n'))
		&& (s->nb_bytes = read(fd, s->buffer, BUFF_SIZE)) > 0)
	{
		s->buffer[s->nb_bytes] = '\0';
		tmp = s->memory[fd];
		s->memory[fd] = ft_strjoin(s->memory[fd], s->buffer);
		ft_strdel(&tmp);
	}
	ft_strdel(&s->buffer);
}

static int		manage_memory(int fd, t_storage *s)
{
	char				*tmp;

	if (ft_strchr(s->memory[fd], '\n'))
	{
		tmp = s->memory[fd];
		s->memory[fd] = ft_strdup(ft_strchr(s->memory[fd], '\n') +1);
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_storage	storage;

	if (fd < 0 || fd > MAXFD || line == NULL)
		return (-1);
	if (!(storage.buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	read_next_line(fd, &storage);
	if (storage.nb_bytes == -1)
		return (-1);
	*line = ft_strsub(storage.memory[fd], 0, get_line_len(fd, &storage));
	return (manage_memory(fd, &storage));
}

int main()
{
	char *line;	
	int fd[4];
	int i = 0;

	fd[0] = open("text", O_RDONLY);
	fd[1] = open("test", O_RDONLY);
	fd[2] = open("tect", O_RDONLY);
	fd[3] = open("tent", O_RDONLY);
	while (get_next_line(fd[i], &line) > 0)
	{
		printf("%d >> %s\n", i, line);
		i = (i + 5) % 4;
		free(line);
	}
	return (0);
}
