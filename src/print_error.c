#include "../header/so_long.h"

/*
If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.
*/

int	print_error(char *message)
{
	printf("Error\n %s", message);
	return(0);
}
