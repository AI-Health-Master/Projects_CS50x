# Ranked-choice Runoff Voting system


### Description  
A C program that implements a ranked-choice runoff election (also known as instant-runoff voting). Candidate names are supplied as command-line arguments. The program records each voter’s ranked candidate preferences and repeatedly tabulates results:
- If no candidate wins an absolute majority (>50%) of the votes, the candidate(s) with the fewest votes are eliminated.
- Votes for eliminated candidates are redistributed to the next preferred non-eliminated candidate on each ballot.
- This process continues in successive rounds until a candidate achieves a majority or until all remaining candidates are tied.


**Key Concepts**
- Command-line argument parsing — processing candidate names provided at runtime
- 2D arrays for data storage — recording each voter’s ranked preferences efficiently
- Control flow and iteration — implementing loops and conditionals to drive election rounds
- Abstraction with functions — modularizing vote tabulation, elimination, and winner detection functions
- Algorithm design — applying elimination and redistribution logic until termination conditions are met


**Sample Output**
```bash
$ ./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie

```
