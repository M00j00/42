int ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_memcmp(s1, s2, ft_strlen(s2)));
	else
		return (ft_memcmp(s1, s2, ft_strlen(s1)));
}
