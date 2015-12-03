char *ft_strrchr(const char *src, int c)
{
	int i;
	char *v;
	for (i = ft_strlen(src); i > 0; i--)
	{
		v = (char*)&src[i];
		if (*v == c)
			return (v);
	}
	return 0;
}
