void *ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	char *cdest;
	const char *csrc;

	cdest = dest;
	csrc = src;
	while (n--)
	{
		if((*cdest++ = *csrc++) == c)
			return (dest);
	}
	return (0);
}
