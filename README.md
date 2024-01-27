[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/push_swap/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/push_swap/blob/master/README.fr.md)

# Project: Push Swap

## 🏁 Goal 🏁

Sort data on a stack using a limited set of instructions, with the least number of actions possible. This involves manipulating various algorithms and choosing the most appropriate solution for optimized data sorting.

## 🚀 Usage 🚀

```shell
git clone git@github.com:nfauconn/push_swap.git
cd Project
make
```
How to run on Bash:

- To check the instructions:
```shell
> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
pb
ra
pb
ra
ra
rra
sb
pa
pa
>
```

- To check the number of instructions:
```shell
> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
8
>
```

- To check if the list has been correctly sorted:
```shell
> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
>
```

## 💡 Skills 💡

- **Algorithmic Thinking**: Understand and compare sorting algorithms

- **Complexity Analysis**: Analyzing and considering the complexity of different sorting methods

- **C Language Proficiency**: Circular double linked list, memory management, pointer arithmetic, and general syntax

- **Efficiency in Code**: Writing efficient code, looking for ways to optimize and improve the performance of algorithms

- **Makefile Usage**: Using Makefiles for compiling, managing dependencies, and ensuring that the project structure is clean and organized

- **Working with Constraints**: Work within the constraints of a project, adhering to the given specifications and rules


## 📋 Subject 📋

Solo project

### Common Instructions

1. **Language**: The project must be written in C.
2. **Norm Compliance**: Code must adhere to the Norm of the school.
3. **Error Handling**: Programs should not exit unexpectedly (e.g., segmentation fault, bus error, double free). Such incidents will render the project non-functional and result in a score of 0.
4. **Memory Management**: All heap allocated memory must be properly freed. Memory leaks are not tolerated.
5. **Makefile Requirements**:
   - Must compile source files to the required output with flags `-Wall`, `-Wextra`, and `-Werror`.
   - Must not relink.
   - Must contain the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

### The Rules

- Two stacks, `a` and `b`, are used.
- At the start:
	- Stack `a` contains a random number of negative and/or positive numbers without duplicates.
	- Stack `b` is empty.
- The goal is to sort the numbers in ascending order in stack `a` using the following operations:
	- `sa` (swap a): Swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
	- `sb` (swap b): Swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
	- `ss`: Perform `sa` and `sb` at the same time.
	- `pa` (push a): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
	- `pb` (push b): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
	- `ra` (rotate a): Shift up all elements of stack `a` by 1. The first element becomes the last one.
	- `rb` (rotate b): Shift up all elements of stack `b` by 1. The first element becomes the last one.
	- `rr`: Perform `ra` and `rb` at the same time.
	- `rra` (reverse rotate a): Shift down all elements of stack `a` by 1. The last element becomes the first one.
	- `rrb` (reverse rotate b): Shift down all elements of stack `b` by 1. The last element becomes the first one.
	- `rrr`: Perform `rra` and `rrb` at the same time.

### The program

| | |
| --- | --- |
| **Program Name** | `push_swap` |
| **Turn in Files** | Makefile, *.h, *.c |
| **Arguments** | Stack `a` as a list of integers (the first argument should be at the top of the stack). |
| **Authorized External Functions** | `read`, `write`, `malloc`, `free`, `exit` |
| **Libft** | Authorized |
| **Description** | Sort stacks |
  
- Must turn in a Makefile which compiles source files without relinking.
- Global variables are forbidden.
- The program must display the smallest list of instructions possible to sort stack `a`, with the smallest number being at the top.
- Instructions must be separated by a `\n` and nothing else.
- The goal is to sort the stack with the lowest possible number of operations.
- If no parameters are specified, the program must not display anything.
- In case of error, display "Error" followed by a `\n` on the standard error. Errors include: non-integer arguments, arguments larger than an integer, duplicates, or invalid instructions.

```shell
> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
> ./push_swap 0 one 2 3
Error
>
```
