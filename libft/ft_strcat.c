char *ft_strcat(char *dest, const char *src)
{
	int i;

	for (i = 0; *src != '\0'; i++)
	{
		dest[ft_strlen(dest) + i] = src[i];
	}
	dest[ft_strlen(dest) + i] = '\0';
	return (dest);
}
