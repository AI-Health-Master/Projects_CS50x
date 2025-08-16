# Plurality election Voting system 
A C program that simulates a plurality election. The program takes candidate names as command-line arguments, then prompts the user for the number of voters and their votes. It updates vote counts for each candidate and determines the winner(s), which is the candidate with the highest number of votes. If there’s a tie, all winners are printed.



## Key Concepts:
-	String comparison (strcmp) and command-line argument handling
-	Data organization with Structs and arrays in C
-	Implementing vote tallying logic
-	Handling ties and output formatting
-	Iteration and conditional logic in C



### Sample Output:
*One try*
$ ./plurality Jacques Bill John
Number of voters: 5
Vote: Jacques
Vote: John
Vote: Bill 
Vote: Bill 
Vote: Jacques

Jacques
Bill 

*One try*
$ ./plurality Jacques Bill 
Number of voters: 4
Vote: Jacques 
Vote: Helene
Invalid vote.
Vote: Bill 
Vote: Jacques 

Jacques 


