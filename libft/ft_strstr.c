char *ft_strstr(const char *haystack, char *needle)
{
	char *ret;

	ret = (char*)haystack;
	while (*ret != '\0')
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
