char *ft_strchr(const char *src, int c)
{
	return ((char*)ft_memchr(src, c, ft_strlen(src)));
}
