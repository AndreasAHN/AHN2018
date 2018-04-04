#include "e17opg2.h"

#include "stringToUnsignedInteger.h"

	unsigned int stringToUnsignedInteger(const char * text)
	{
		int i = 0, tal = 0;

		while (*text != '\0')
		{
			if ('0' < *text || *text < '9')
				return 0;

			if (9 < i)
				return 0;

			if (i > 1)
				tal += *text * 10 * i;
			else
				tal = *text;

			++text;
			i++;
		}
		return tal;
	}


