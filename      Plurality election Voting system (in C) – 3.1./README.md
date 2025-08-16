# Plurality election Voting system 
A C program that simulates a plurality election. Candidate names are provided as command-line arguments; the program then prompts for the number of voters and each vote, tallies the results, and prints the winner(s). The winner is the candidate with the highest vote count; in case of a tie, all winners are printed.


## Key Concepts:
-	String comparison (strcmp) and command-line argument handling
-	Data organization with structs and arrays in C
-	Implementing vote tallying logic
-	Ties handling  and output formatting
-	Iteration and conditional logic in C



### Sample Output:
*One try*
```bash
$ ./plurality Jacques Bill John
Number of voters: 5
Vote: Jacques
Vote: John
Vote: Bill
Vote: Bill
Vote: Jacques

Jacques
Bill 
```

*One try*
```bash
$ ./plurality Jacques Bill
Number of voters: 4
Vote: Jacques
Vote: Helene
Invalid vote.
Vote: Bill 
Vote: Jacques 

Jacques 
```

