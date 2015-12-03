void *ft_memmove(void *dest, const void *src, unsigned int n)
{
	char *tmp;
	
	if (n)
	{
		tmp = (char *) malloc(sizeof(char) * n);
		tmp = memcpy(tmp, src, n);
		dest = memcpy(dest, tmp, n);
	}
	return (dest);
}
