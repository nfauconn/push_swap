[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/push_swap/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/push_swap/blob/master/README.fr.md)

*C Programming Language* • *Algorithmic Thinking* • *Complexity Analysis* • *Double Circular Linked Lists* • *Error Management* • *Memory Management* • *Norm Compliance* • *Compilation Automation with Makefile*

# Push Swap

Sort data on a stack using a limited set of instructions, with the least number of actions possible. This involves manipulating various algorithms and choosing the most appropriate solution for optimized data sorting.

| Key | Value |
| --- | --- |
| **Program Name** | `push_swap` |
| **Turn in Files** | Makefile, *.h, *.c |
| **Arguments** | Stack `a` as a list of integers (the first argument should be at the top of the stack). |
| **Authorized External Functions** | `read`, `write`, `malloc`, `free`, `exit` |

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

- The program displays the smallest list of instructions possible to sort stack `a`, with the smallest number being at the top.

## Usage

```shell
git clone git@github.com:nfauconn/push_swap.git
cd push_swap/Project
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
