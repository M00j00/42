void bzero(void *s, unsigned int n)
{
	char *ptr;

	ptr = s;
	while (n--)
	{
		*ptr++ = '\0';
	}
}
