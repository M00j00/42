char *ft_strcat(char *dest, const char *src, unsigned int n)
{
	int i;

	for (i = 0; i < n && *src != '\0'; i++)
	{
		dest[ft_strlen(dest) + i] = src[i];
	}
	dest[ft_strlen(dest) + i] = '\0';
	return (dest);
}
