char *ft_strnstr(const char *haystack, char *needle, unsigned int n)
{
	char *ret;

	ret = (char*)haystack;
	while (*ret != '\0' && n--)
	{
		if (*ret == *needle)
		{
			if (!ft_memcmp(ret, needle, ft_strlen(needle)))
			return ret;
		}
		ret++;
	}
	return 0;
}
