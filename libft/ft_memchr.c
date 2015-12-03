void *ft_memchr(const void *src, int c, unsigned int n)
{
	char *csrc;

	csrc = (char*)src;
	while (n--)
	{
		if (*csrc == c)
			return (csrc);
		csrc++;
	}
	return NULL;
}
