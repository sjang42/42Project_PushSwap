# Push_Swap - sjang@student.42.us.org

A C program that sort data using two stack with limited operation.

## TOC
* [What is Push_Swap?](##what-is-Push_Swap)
* [How do I use it?](##how-do-i-use-it)
* [How do I test it?](##how-do-i-test-it)

## What is Push_Swap?

[Push_Swap][1] is an individual project at [42][2] that sort data under a limited condition.

Disclaimer: *There are so many easier [methods][4] of sorting data this by using array, linked list or other data structures. But the goal here is to be able to do it by using just two stacks with limited operation.*

###Rule

The rule is using only 2 stack with 11 operation described below.

**sa** :	swap a - swap the first 2 elements at the top of stack a. Do nothing if there
			is only one or no elements).
**sb** :	swap b - swap the first 2 elements at the top of stack b. Do nothing if there
			is only one or no elements).
**ss** :	sa and sb at the same time.
**pa** :	push a - take the first element at the top of b and put it at the top of a. Do
			nothing if b is empty.
**pb** :	push b - take the first element at the top of a and put it at the top of b. Do
			nothing if a is empty.
**ra** :	rotate a - shift up all elements of stack a by 1. The first element becomes
			the last one.
**rb** :	rotate b - shift up all elements of stack b by 1. The first element becomes
			the last one.
**rr** :	ra and rb at the same time.
**rra** :	reverse rotate a - shift down all elements of stack a by 1. The flast element
			becomes the first one.
**rrb** :	reverse rotate b - shift down all elements of stack b by 1. The flast element
		becomes the first one.
**rrr** :	rra and rrb at the same time.

###Example 
  
    a : 7, 1, -8, 6, 5
    b :
`ra`

    a : 1, -8, 6, 5, 7
    b :
`pb`

    a : -8, 6, 5, 7
    b : 1
`pb`

    a : 6, 5, 7
    b : -8, 1
`ss`

    a : 5, 6, 7
    b : 1, -8
`pa`

    a : 1, 5, 6, 7
    b : -8
`pa`

    a : -8, 1, 5, 6, 7
    b :

### How do I use it?

We can make the program `push_swap` and `checker` at the same time.

**NOTE:** `push_swap` gets number data as argument and shows instructions to be used for sorting. `checker` gets number data as argument and also gets instructions through stdin and check it is sorted or not at the end.

Alright, so first of all, download/clone this repo:

	git clone https://github.com/sjang42/42Project_PushSwap.git

Get into it and build the excutable:
	
	cd 42Project_PushSwap
	make

**NOTE:** Since 42 makes us the limitation for using of Standard Library function except ◦ write
◦ read ◦ malloc ◦ free ◦ exit, I made my own library [libft][3] using allowed functions.

Alright, the last command created a `push_swap` and `checker` executable in your directory. Now test `push_swap` with:

	./push_swap 7, 1, -8, 6, 5

It should show you how we can sort the data using instructions above. Then, let's test `checker` with:

	./push_swap 7, 1, -8, 6, 5 | ./checker -s 7, 1, -8, 6, 5

It will show you OK if it is sorted in the end or KO if not. *-s* option shows you the sorting process visually.

## How do I test it?

I added a `test` command in my Makefile. So just call:

	make test

This command makes `mktest` excutable file in your directory. Lets make test file with:

	./mktest filename size_of_data

If you choose `test100.txt` and size 100, call this with -f option:

	./push_swap -f test100.txt | ./checker -fs test100.txt

**NOTE:** If you add m option into checker, you will see how many instructions used.

Enjoy!

[1]: https://github.com/sjang42/42Project_GetNextLine/blob/master/get_next_line.en.pdf
[2]: http://42.us.org "42 USA"
[3]: https://github.com/sjang42/42Project_Libft
[4]: https://en.wikipedia.org/wiki/Sorting_algorithm
