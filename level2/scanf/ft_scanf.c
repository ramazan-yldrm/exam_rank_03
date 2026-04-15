#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int ft_scanf(const char *fmt, ...)
{
	va_list ap;
	int c, n = 0, sign, val, found;
	char *s;

	va_start(ap, fmt);
	if ((c = fgetc(stdin)) == EOF)
		return va_end(ap), EOF;
	ungetc(c, stdin);

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'd' || *fmt == 's')
				while ((c = fgetc(stdin)) != EOF && isspace(c));
			else
				c = fgetc(stdin);

			if (c == EOF) break;

			if (*fmt == 'c')
				*va_arg(ap, char *) = c, n++;
			else if (*fmt == 'd')
			{
				sign = 1; val = 0; found = 0;
				if (c == '-' || c == '+')
					sign = (c == '-') ? -1 : 1;
				else if (isdigit(c))
					val = c - '0', found = 1;
				else
					{ ungetc(c, stdin); break; }
				while ((c = fgetc(stdin)) != EOF && isdigit(c))
					val = val * 10 + c - '0', found = 1;
				if (c != EOF) ungetc(c, stdin);
				if (!found) break;
				*va_arg(ap, int *) = sign * val;
				n++;
			}
			else if (*fmt == 's')
			{
				s = va_arg(ap, char *);
				if (isspace(c) || c == EOF) { ungetc(c, stdin); break; }
				*s++ = c;
				while ((c = fgetc(stdin)) != EOF && !isspace(c))
					*s++ = c;
				if (c != EOF) ungetc(c, stdin);
				*s = '\0';
				n++;
			}
			else break;
		}
		else if (isspace(*fmt))
		{
			while ((c = fgetc(stdin)) != EOF && isspace(c));
			if (c != EOF) ungetc(c, stdin);
		}
		else
		{
			c = fgetc(stdin);
			if (c != *fmt) { if (c != EOF) ungetc(c, stdin); break; }
		}
		fmt++;
	}
	va_end(ap);
	return n;
}
