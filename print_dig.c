#include "main.h"
#include <stdarg.h>
#include <unistd.h>


int print_dig(va_list args)
{
char buffer[12];
int count = 0, index1 = 0, index2 = 0, n = va_arg(args, int);
unsigned int num;

if (n < 0)
{
write(1, "-", 1);
num = -n;
}
else
{
num = n;
}
while (num > 0)
{
buffer[index1++] = num % 10 + '0';
num /= 10;
}
for (index2 = index1 - 1; index2 >= 0; index2--)
{
count += write(1, &buffer[index2], 1);
}
return (count);
}
