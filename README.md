# Holberton's School _printf

## 📝 Description
This project is a simple set of functions mimicking the standard printf function in C. 

## 📂 Index
- Informations
- Installation
- Uses
- Code examples
- Flowchart
- Authors

## 🛠️ Informations
This program was compiled with = ```gcc -Wall -Werror -Wextra -pedantic -std=gnu89``` on Ubuntu 20.04 LTS. \
This program is fully Betty-compatible. We do not provide a main test. \
At the moment, it only handle %%, %s, %c, %d and %i properly. \
It does not handle flags. \
It is coded entirely in basic C89 ISO. \
As this set of functions does not uses mdynamic memoty allocation, there is no need for Valgrind.

## 🚀 Installation
1. Clone the repository on your system : `git clone https://github.com/loufi84/holbertonschool-printf.git`  
2. Add you main.c and compile with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c`  

## 📖 Uses
You can import the function in your code by using ```#include "main.h"``` in the headers. 

## 💻 Code examples
```c
_printf("Hello %s\n", "World");  
_printf("%d\n", 456);  
int age = 17;  
_printf("You are %d years old", age);
```

## 🔍 Man page
This documentation include a man page in the files. It is not executable for the moment.  
You can place it in /usr/local/man/man3  
`sudo mandb` to make it executable.  
And `man 3 _printf` to execute it.

## 🗺️ Flowchart
![printf_diagram drawio](https://github.com/user-attachments/assets/2c34cc37-842e-446c-9654-4ce42c88c5ea)

## 🧑‍💻 Authors
Quentin LATASTE - https://github.com/loufi84 \
Patricia BAGASHVILI - https://github.com/alizium 