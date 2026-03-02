*This project has been created as part of the 42 curriculum by vslyunko*

# DESCRIPTION

In this project, we write a C program to sort data in a stack using a limited set of instruction. The program calculates and displays a sequence of instructions needed to sort the given integers. 

We have at our disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.

The goal is to sort the stack with the lowest possible number of operations.

### To achieve the goal, I chose a customized cost-based greedy insertion sorting algorithm.
The overall structure of the algorithm is as follows:
- Assign an index to each element (its position in the sorted order).
- Push all elements except three to stack B.
- Sort the three remaining elements in stack A.
- For each node in stack B:
	- Calculate its target position in stack A.
	- Calculate cost_a (rotations needed in A).
	- Calculate cost_b (rotations needed in B).
- Select the node with the lowest total cost.
- Execute combined rotations when possible (e.g., rr or rrr) to minimize the number of moves.
- Push the selected node back to stack A (pa).
- Repeat the process until stack B is empty.
- Perform a final rotation of stack A so that the smallest element is at the top.

---
# INSTRUCTIONS

### Compilation

1. Compile the program
```
make
make clean      # removes object files (.o)
make fclean     # removes object files and executables
make re         # recompiles everything from scratch
```
2. Running the program.
```
./push_swap 3 2 1 6 5
```
push_swap support this 3 cases:
- A single number, e.g., 42
- Multiple numbers separated by spaces, e.g., "3 2 1"
- Or a mixture of both single and multi-number arguments, e.g., 5 "8 4 2" 7

Generate instructions and pass them to checker
```
./push_swap 3 2 1 | ./checker 3 2 1
```
Add automatic generator of numbers.
```
ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); valgrind ./push_swap $ARG
```
OK — the stack is sorted correctly.
KO — the stack is not sorted.

Supported Operations:
```
sa	Swap the first two elements of stack A
sb	Swap the first two elements of stack B
ss	Swap A and B simultaneously
pa	Push the first element from B to A
pb	Push the first element from A to B
ra	Rotate stack A upwards
rb	Rotate stack B upwards
rr	Rotate A and B simultaneously upwards
rra	Reverse rotate stack A
rrb	Reverse rotate stack B
rrr	Reverse rotate both A and B
```

# RESOURCES:

- Peer to peer.

### Theory
The following resources (recommended in the subject) were used to understand the fundamental concepts:

- [Algorithm Analysis – Wikipedia](https://es.wikipedia.org/wiki/An%C3%A1lisis_de_algoritmos)
- [Stack (Abstract Data Type) – Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

### Research & Approaches
To analyze the problem and explore different implementation strategies:

- [Push_swap Explanation – YouTube](https://www.youtube.com/watch?v=OaG81sDEpVk)
- [Push_swap Strategy – YouTube](https://www.youtube.com/watch?v=wRvipSG4Mmk)

### Main Algorithm
The core sorting logic is mainly based on:

- [Sorting Algorithm for 3 Numbers – Codequoi (Archived)](https://web.archive.org/web/20220802162832/https://www.codequoi.com/en/push_swap-efficient-positional-sorting-algorithm/#sorting_algorithm_for_3_numbers)
- [Push_swap Turk Algorithm – Medium](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

AI tools were used as a conceptual support tool during development.