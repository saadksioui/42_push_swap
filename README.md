*This project has been created as part of the 42 curriculum by sksioui.*

## Description
**Push_swap** is an algorithmic challenge that requires sorting a list of unique integers using only two stacks (named 'a' and 'b') and a limited set of predefined operations.

The challenge is to sort a random list of integers using only the following operations:
* **sa, sb, ss**: Swap the first two elements of a stack.
* **pa, pb**: Push the top element of one stack to another.
* **ra, rb, rr**: Rotate the stack up (first element becomes last).
* **rra, rrb, rrr**: Reverse rotate the stack down (last element becomes first).

This project focuses on complexity analysis, sorting algorithms, and stack manipulation in C.

## Instructions

### 1. Compilation
The project uses a `Makefile` for compilation.

* **Compile the mandatory part (push_swap):**
    ```bash
    make
    ```

* **Compile the bonus part (checker):**
    ```bash
    make bonus
    ```

* **Clean object files and executables:**
    ```bash
    make fclean
    ```

### 2. Execution
To run the sorting program:
```bash
./push_swap 4 67 3 87 23
```

To run the checker (Bonus):
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
* **Output OK**: The stack is correctly sorted.

* **Output KO**: The stack is not sorted.

* **Output Error**: Invalid input.

## Algorithm Used

For large datasets (100 and 500 numbers), this project implements the Chunk Sort (Butterfly) Algorithm:
* **Indexing**: The input numbers are first ranked (0 to N) to simplify comparisons.

* **Phase 1 (A to B)**: Numbers are pushed to Stack B in "chunks" or ranges. Smaller numbers in the current range are rotated to the bottom of B (rb), creating a "butterfly" or "hourglass" shape (Large numbers at the top, Small numbers at the bottom).

* **Phase 2 (B to A)**: Elements are pushed back to A using a greedy approach. We look for the maximum index in B, bring it to the top using the most efficient path (rb or rrb), and push it to A (pa).

## Resources

### Documentation & References

* **Push_swap Tutorial**: [![Alt text for the image](https://img.youtube.com/vi/wRvipSG4Mmk/0.jpg)](https://www.youtube.com/watch?v=wRvipSG4Mmk)

* **Visualizer**: I used push_swap_visualizer to debug and optimize the algorithm.

* **Sorting Algorithms**: Wikipedia references on Quick Sort and Stack operations.

## AI Usage

AI tools (ChatGPT / Gemini) were used in this project as a learning assistant and debugger. Specifically:

* **Concept Explanation**: Used AI to understand the logic behind the "Butterfly/Chunk" algorithm and how to optimize instruction counts.

* **Debugging**: Used to troubleshoot segmentation faults and logic errors in the "sort_five" function and linked list implementation.

* **Makefile**: Assisted in creating a generic Makefile that correctly links the mandatory and bonus parts without relinking.

* **Visualization**: Generated ASCII diagrams to visualize the stack movement during the algorithm's execution.