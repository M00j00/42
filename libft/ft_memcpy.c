void *ft_memcpy(void *dest, const void *src, unsigned int n)
{
	 char *cdest;
	 const char *csrc;

	cdest = dest;
	csrc = src;
	while (n--)
	{
		*cdest++ = *csrc++;
	}
	return dest;
}
