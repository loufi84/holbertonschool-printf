# Holberton's School _printf

<img align="center" alt="printfC" width="1000" src="https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExNm8wbTB4MzhtYm1zamZ1bjczYXR3MHk1bmJ6MGR1amZjb2oyOHNvYiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/GwtfUx2P2HnvByDZdg/giphy.gif">

***

## 📝 Description
This project is a simple set of functions mimicking the standard printf function in C. It focus on re producing basic printf functions.  
It is also a solid foundation for further implementations and every C developper should try at least once to understand basics of the C programing language.

***

## 📂 Index
1. [Informations](#informations)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Code Examples](#code-examples)
5. [Man Page](#man-page)
6. [Possible Improvements](#possible-improvements)
7. [Flowchart](#flowchart)
8. [Authors](#authors)

***

## 🛠️ Informations
- **Compilation**: This program was compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89` on Ubuntu 20.04 LTS.
- **Style**: Fully compatible with Betty coding standards.
- **Current Features**:
  - Supports the following specifiers: `%%`, `%s`, `%c`, `%d`, and `%i`.
  - Does not handle flags or advanced specifiers.
- **Language**: Entirely written in C89 ISO, without dynamic memory allocation.
- **Memory Testing**: No need to use Valgrind since no dynamic memory allocation is used.

## 🚀 Installation
### Prerequisites
- GCC installed on your system.
- Ubuntu 20.04 LTS (or equivalent).  
*This program was designed for Linux systems. It was tested functionnal on a Mac M2 (Apple Silicon) and can cause segmentation fault with this architecture*

### Steps
1. Clone the repository to your local machine : `git clone https://github.com/loufi84/holbertonschool-printf.git`
2. Add your own `main.c` file and compile with : `gcc -Wall -Werror -Wextra -pedantic -st=gnu89 *.c`
3. To test the program, you can use Valgrind ; `valgrind ./a.out`

***

## 📖 Usage
- To use the `_printf` function, include yhe header file in your code : `#include "main.h`
- Then call the `_printf`function as follows : `_printf(format, arguments...)`

***

## 💻 Code examples
```c
_printf("Hello %s\n", "World");  
_printf("%d\n", 456);  
int age = 17;  
_printf("You are %d years old", age);
```

***

## 🔍 Man page
This project includes a man page in the repository files:
1. Place it in `/usr/local/man/man3`.
2. Run `sudo mandb` to index it.
3. View it using: `man 3 _printf`

***

## 💡 Possible improvements 
While this version meets the mandatory requirements, there is significant room for improvement:
- Add support for `%u` (unsigned integers) and `%x` or `%X` (hexadecimal).
- Implement conversion of integers to binary using `%b`.

### Example implementation for `%x`:
```
Declare print_hex function with num args
var char buffer[9]
var int index = 7
var int digit
buffer[8] = 0
if num = 0:
  print(0)
  return
while num > 0:
  digit = num % 16
    if digit < 10:
      buffer[index--] = digit + 0
    else:
      buffer[index--] = (uppercase ? A : a) + (digit - 10)
  num /= 16
print(buffer[index + 1]
```

### Example implementation for `%b`:
```
Declare print_bin function with num args
var char buffer[33]
var int index = 31
buffer[32] = '\0'

if num = 0:
  print(0)
  return

while num > 0:
  buffer[index--] = (num % 2) + '0'
  num /= 2

print(buffer[index + 1])
```

***

## 🗺️ Flowchart
Here is an overview of `_printf`'s internal workflow:  


![Printf Diagram](https://github.com/loufi84/holbertonschool-printf/blob/main/_printf_flowchart_final.drawio.png)

***

## 🧑‍💻 Authors
Quentin LATASTE - https://github.com/loufi84 \
Patricia BAGASHVILI - https://github.com/alizium 
