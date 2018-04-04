


void findOgErstat(char *text)
{
	while (*text != '\0')
	{
		if (*text == 'a' || *text == 'A')
			*text = '@';
		else if (*text == 'h' || *text == 'H')
			*text = '#';
		++text;
	}
}