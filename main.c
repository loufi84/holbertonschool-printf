#include <stdio.h>
#include <limits.h>
#include "main.h"

void run_tests(void)
{
	char non_printable = 1;

	printf("\n==== EDGE CASE TESTING ====\n\n");

	printf("=== Integer Edge Cases ===\n");
	_printf("Single digit: %d\n", 7);
	_printf("Zero: %d\n", 0);
	_printf("INT_MAX: %d\n", INT_MAX);
	_printf("INT_MIN: %d\n", INT_MIN);
	_printf("INT_MAX as %%i: %i\n", INT_MAX);
	_printf("INT_MIN as %%i: %i\n", INT_MIN);
	_printf("Multiple zeros: %d%d%d\n", 0, 0, 0);
	_printf("Alternating signs: %d %i %d %i\n", 1, -1, 2, -2);
	_printf("Large numbers: %d %i %d\n", 1234567, 9876543, 5555555);
	_printf("\n");

	printf("=== Character Edge Cases ===\n");
	_printf("Printable char: %c\n", 'A');
	_printf("Digit as char: %c\n", '7');
	_printf("Special char: %c\n", '$');
	_printf("Space char: %c\n", ' ');
	_printf("Newline char: %c", '\n');
	_printf("Tab char: %c\n", '\t');
	_printf("Non-printable (ASCII 1): %c\n", non_printable);
	_printf("Null char: %c\n", '\0');
	_printf("Multiple chars: %c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	_printf("\n");

	printf("=== String Edge Cases ===\n");
	_printf("Normal string: %s\n", "Hello");
	_printf("Empty string: %s\n", "");
	_printf("NULL string: %s\n", NULL);
	_printf("String with spaces: %s\n", "   ");
	_printf("String with special chars: %s\n", "!@#$%^&*()");
	_printf("String with numbers: %s\n", "12345");
	_printf("String with escapes: %s\n", "Hello\nWorld\t!");
	_printf("Long string: %s\n", "This is a very long string that should test the buffer handling of your printf implementation");
	_printf("Adjacent strings: %s%s%s\n", "One", "Two", "Three");
	_printf("\n");

	printf("=== Percent Sign Edge Cases ===\n");
	_printf("Single %%: %%\n");
	_printf("Multiple %%%%: %%%%\n");
	_printf("Mixed with text: 100%%\n");
	_printf("At start: %%Hello\n");
	_printf("At end: Hello%%\n");
	_printf("Alone: %%%%\n");
	_printf("With spaces: %% %% %%\n");
	_printf("\n");

	printf("=== Mixed Format Edge Cases ===\n");
	_printf("%d %i %c %s %%\n", 123, -456, 'X', "Mixed");
	_printf("%s%d%c%%\n", "Test", 42, '!');
	_printf("%c%s%d%%%i\n", 'A', "BC", 123, -456);
	_printf("%%%d%%%i%%%c%%%s%%\n", 1, 2, 'C', "D");
	_printf("Leading text %d middle %c end\n", 123, 'X');
	_printf("%d%d%d%d\n", 1, 2, 3, 4);
	_printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	_printf("\n");

	printf("=== Format String Edge Cases ===\n");
	_printf("Empty format string: \n");
	_printf("%%");
	_printf("\nNo args: Hello World\n");
	_printf("Percent at end: Hello %\n");
	_printf("Unterminated format: %");
	_printf("\n");
}

int main(void)
{
	int num = 42;
	int neg_num = -42;
	int zero = 0;
	int max_int = INT_MAX;
	int min_int = INT_MIN;
	char ch = 'A';
	char *str = "Hello, World!";
	char *empty_str = "";
	char *null_str = NULL;

	printf("==== Starting Comprehensive printf Tests ====\n");
	printf("==== Standard Test Cases ====\n");

	_printf("Positive number: %d\n", num);
	_printf("Negative number: %i\n", neg_num);
	_printf("Zero: %d\n", zero);
	_printf("INT_MAX: %i\n", max_int);
	_printf("INT_MIN: %d\n\n", min_int);

	_printf("Uppercase letter: %c\n", ch);
	_printf("Lowercase letter: %c\n", 'z');
	_printf("Digit as char: %c\n", '7');
	_printf("Special char: %c\n\n", '$');

	_printf("Regular string: %s\n", str);
	_printf("Empty string: %s\n", empty_str);
	_printf("NULL string: %s\n\n", null_str);

	_printf("Percent sign: %%\n");
	_printf("Multiple percent signs: %%%%\n");
	_printf("Mixed with text: Hello%%World\n\n");

	_printf("Number: %d, Char: %c, String: %s\n", num, ch, str);
	_printf("%s %d%% complete\n", "Progress:", 75);
	_printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	_printf("%d %i %c %s %%\n", 100, 200, 'X', "Test");

	run_tests();

	printf("==== All Tests Completed ====\n");

	return (0);
}