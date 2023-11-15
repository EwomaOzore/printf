#include "main.h"

int main(void)
{
	int len;

	len = _printf("Let's try some %s and %c and %% formatting!\n", "strings", 'C');
	_printf("Number of characters printed: %d\n", len);

	return (0);
}
