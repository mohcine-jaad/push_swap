*This project has been created as part of the 42 curriculum by mjaad*

# Description
**Push swap** is an algorithm project that consists of sorting a stack of integers using a limited set of operations and an auxiliary stack.

The goal is not only to sort the numbers correctly, but to do so using the **minimum number of instructions possible**.

As a general overview, the program receives a list of integers as arguments and must output a series of instructions to sort them. You have access to the following operations:
| Operation | Description | Example |
|-----------|-------------|---------|
| `sa`        | swap the first two elements at the top of stack a | a: `(2) (1) (3) (4)` -> `(1) (2) (3) (4)` |
| `sb`        | swap the first two elements at the top of stack b | b: `(5) (8) (6)` -> `(8) (5) (6)` |
| `ss`        | sa and sb at the same time | a: `(2) (1) (3) (4)` -> `(1) (2) (3) (4)` <br> b: `(5) (8) (6)` -> `(8) (5) (6)`
| `pa`        | push the first element from stack b to stack a | a: `(2) (3) (4)` <br> b: `(5) (8) (6)` -> a: `(5) (2) (3) (4)` <br> b: `(8) (6)` |
| `pb`        | push the first element from stack a to stack b | a: `(2) (3) (4)` <br> b: `(5) (8) (6)` -> a: `(3) (4)` <br> b: `(2) (5) (8) (6)` |
| `ra`        | rotate stack a (shift all elements up by one) | a: `(2) (3) (4) (5)` -> `(3) (4) (5) (2)` |
| `rb`        | rotate stack b (shift all elements up by one) | b: `(5) (8) (6)` -> `(8) (6) (5)` |
| `rr`        | ra and rb at the same time | a: `(2) (3) (4) (5)` -> `(3) (4) (5) (2)` <br> b: `(5) (8) (6)` -> `(8) (6) (5)` |
| `rra`       | reverse rotate stack a (shift all elements down by one) | a: `(2) (3) (4) (5)` -> `(5) (2) (3) (4)` |
| `rrb`       | reverse rotate stack b (shift all elements down by one) | b: `(5) (8) (6)` -> `(6) (5) (8)` |
| `rrr`       | rra and rrb at the same time | | a: `(2) (3) (4) (5)` -> `(5) (2) (3) (4)` <br> b: `(5) (8) (6)` -> `(6) (5) (8)` |

# Instructions

### Compilation
Compile the project using the provided Makefile:
```bash
make
```
### Execution
Run the program by passing a list of integers as arguments:
```bash
./push_swap <list_of_integers>
```
**Example**
```bash
./push_swap 4 67 3 87 23
```

# Resources
### References
- [Push Swap - 42 Documentation](https://cdn.intra.42.fr/pdf/pdf/189063/en.subject.pdf)
- articles
    1.  [Article in medium](https://wiki.42.fr/Push_Swap)
    2.  [Another article](https://medium.com/@mohamedelgendy_17278/push-swap-42cursus-solution-explained-3a6d3f3f2f87)
    3.  [Another one](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- Big-O Notation and algorithmic complexity

### Use of AI
AI tools were used **only as an auxiliary learning resource**, not to generate final code.
- Clarify algorithmic concepts (stack operations, cost calculation, optimization ideas)
- Understand sorting algorithms and data structures
- Improve documentation clarity (README structure and wording)
- Debug specific issues by asking for explanations of error messages or unexpected behavior

## Algorithm & Technical Choices
The project is using linked lists to represent the stacks. The sorting algorithm combines different strategies based on the size of the input:
- For small lists (2-5 elements), specific sorting routines are implemented to minimize the number of operations.
- For larger lists, turk algorithm is used, which involves dividing the list into chunks and sorting them iteratively.

***phase1: Push to B (except 3 elements)***
1. Keep 3 elements in stack A.
2. Push other elements to stack B.

***phase2: Sort 3 elements in A***

1. Sort the 3 elements in stack A using minimal operations.

***phase3: Push back to A from B***
for each element in stack B:
1. **Calculate target position** in stack A (where it should be inserted).
2. **Calculate cost** to move element to top of stack B and to its target position in stack A.
3. **Choose the element with the lowest cost** and perform the necessary operations to move it to stack A.
4. Repeat until stack B is empty.
5. Finally, rotate stack A to position the smallest element at the top.

**Cost Calculation:**
```
Cost = |moves to top of B| + |moves to target position in A|

Example: 
Element at position 3 in B → top of B:  3 rotations (or n-3 reverse)
Target position 2 in A → top of A: 2 rotations (or n-2 reverse)
Total cost: min(3+2, 3+(n-2), (n-3)+2, (n-3)+(n-2))
```
**optimization:**
- use combined rotations (rr or rrr) when both stacks need to be rotated in the same direction to reduce total moves.

### Data Structures
- Dynamic arrays for storing input values.
- Linked lists for stack representation.

### Error Handling
- The program checks for invalid inputs (non-integer values, duplicates) and handles errors gracefully by printing an error message and exiting.