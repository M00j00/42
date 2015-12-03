int ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned char *c1;
	unsigned char *c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	for ( ; n-- ; c1++, c2++)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
	}
	return 0;
}
