*This project has been created as part of the 42 curriculum by vslyunko*

<p align="center">
  <img src="push-swap-banner.jpg" alt="Push Swap banner" width="100%">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-245C45?style=flat&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Linked_Lists-245C45?style=flat" alt="Linked Lists">
  <img src="https://img.shields.io/badge/Greedy_Algorithm-245C45?style=flat" alt="Greedy Algorithm">
  <img src="https://img.shields.io/badge/Algorithmic_Optimization-245C45?style=flat" alt="Algorithmic Optimization">
  <img src="https://img.shields.io/badge/Memory_Management-245C45?style=flat" alt="Memory Management">
</p>

<p align="center">
  Sort a stack using the fewest possible operations
</p>

## DESCRIPTION

**Push Swap** is a sorting algorithm project built around two stacks and a limited set of operations.

The program receives a sequence of integers in **stack A** and must sort them using **stack B** as auxiliary storage.

```text
Initial                 Sorted

A       B               A       B
│ 8 │                   │ 1 │
│ 3 │                   │ 3 │
│ 5 │       →           │ 5 │
│ 1 │                   │ 8 │
└───┘   └───┘           └───┘   └───┘
```

Instead of printing the sorted numbers, `push_swap` outputs the sequence of stack operations required to reach the sorted state.

```bash
$ ./push_swap 3 2 1
ra
sa
```

The challenge is not only to sort the numbers correctly, but to do it with the **lowest possible number of operations**.

---

## INSTRUCTIONS

### Compilation

```bash
make
```

Other available rules:

```bash
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Recompile everything
```

### Running Push Swap

```bash
./push_swap 3 2 1 6 5
```

Arguments can be provided individually, inside strings, or as a combination:

```bash
./push_swap 42
./push_swap "3 2 1"
./push_swap 5 "8 4 2" 7
```

### Checking the result

The generated operations can be sent directly to the checker:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

The checker returns:

- `OK` — the stack was sorted correctly.
- `KO` — the resulting stack is not sorted.

For larger random tests:

```bash
ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
./push_swap $ARG | ./checker $ARG
```
To check for memory leaks with Valgrind:
```bash
valgrind ./push_swap $ARG
```

---

## HOW IT WORKS

My implementation uses a **cost-based greedy insertion strategy**.

**Index → Move to B → Sort 3 → Find cheapest move → Insert into A → Final rotation**

### 1. Prepare the stacks

Each number receives an index corresponding to its position in the sorted sequence.

Most elements are moved from **A → B**, leaving three elements in A that can be sorted directly.

### 2. Find the cheapest element to move

For every element in B, the algorithm determines:

- where it belongs in A;
- how many rotations A needs;
- how many rotations B needs.

```text
Element in B
     │
     ├── rotations needed in A
     │
     └── rotations needed in B
                 │
                 ↓
              total cost
```

The element with the **lowest movement cost** is selected.

### 3. Combine movements

When both stacks need to rotate in the same direction, operations are combined:

```text
ra + rb   → rr
rra + rrb → rrr
```

This reduces the total number of instructions.

The selected element is pushed back to A and the process repeats until B is empty.

Finally, A is rotated until the smallest element is at the top.

---

## OPERATIONS

| Operation | Action |
| :---: | --- |
| `sa` / `sb` | Swap the first two elements of stack A / B |
| `ss` | Swap both stacks |
| `pa` | Push the first element from B to A |
| `pb` | Push the first element from A to B |
| `ra` / `rb` | Rotate stack A / B upwards |
| `rr` | Rotate both stacks upwards |
| `rra` / `rrb` | Reverse rotate stack A / B |
| `rrr` | Reverse rotate both stacks |

---

## RESOURCES

### Theory

- [Algorithm Analysis – Wikipedia](https://es.wikipedia.org/wiki/An%C3%A1lisis_de_algoritmos)
- [Stack (Abstract Data Type) – Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

### Push Swap strategies

- [Push_swap Explanation – YouTube](https://www.youtube.com/watch?v=OaG81sDEpVk)
- [Push_swap Strategy – YouTube](https://www.youtube.com/watch?v=wRvipSG4Mmk)
- [Sorting Algorithm for 3 Numbers – Codequoi (Archived)](https://web.archive.org/web/20220802162832/https://www.codequoi.com/en/push_swap-efficient-positional-sorting-algorithm/#sorting_algorithm_for_3_numbers)
- [Push_swap Turk Algorithm – Medium](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

### AI usage

AI tools were used as conceptual support during development to discuss sorting strategies, reason about algorithmic decisions and clarify unfamiliar concepts.

All implementation decisions and suggestions were reviewed and understood before being incorporated into the project.
