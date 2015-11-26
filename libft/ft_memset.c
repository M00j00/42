void *ft_memset(void *ptr, int c, unsigned int n)
{
	char	*ret;

	ret = ptr;
	while (n--)
	{
		*ret++  = c;
	}
	return (ptr);
}
