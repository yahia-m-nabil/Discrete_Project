# Discrete Project *(Proving the validity of a Statement & its Satisfiability)*
this project is about decoding a string of symbols that represent the boolean algebra of a statement into truth tables and seeing the operators and doing the 
appropriate operations using multiple functions

## the decoding mechanism (Two Stack algorithm)
the main idea of the program is by using 2 stacks we can represent the string in a char stack while another stack holds the truth table for the appropriate 
representation 
*For example*   `(~a|b)`
``` diagram 
                   char stack     vector<bool> stack
                    |      |            |     |
`(`        ->       |      |            |     |
                    | ____ |            | ___ |
                   char stack     vector<bool> stack
                    |     |            |            |
`(a`       ->       |  a  |            |            |
                    | (   |            | a_vector   |
                   char stack     vector<bool> stack
                    |   |  |            |          |
`( a|`     ->       |  a   |            |          |
                    | (    |            | a_vector |
                     char stack     vector<bool> stack
                    |  ~   |            |          |
                    |  |   |            |          |
`( a|~`    ->       |   a  |            |          |
                    |  (   |            | a_vector |
                   char stack     vector<bool> stack
                    |  b   |            |          |
                    |  ~   |            |          |
                    |  |   |            |          |
`(a|~b `   ->       |   a  |            | b_vector |
                    |  (   |            | a_vector |
###after reaching a ) the application unwinds the char stack and calculates the vector stack and pops previous data and pushes new result 
                   char stack     vector<bool> stack
                    |      |            |           |
                    |      |            |           |
                    |  |   |            |           |
`(a| `     ->       |   a  |            | !b_vector |
                    |  (   |            | a_vector  |
                    char stack     vector<bool> stack
                    |      |            |              |
                    |      |            |              |
                    |      |            |              |
`(`        ->       |      |            |              |
                    |  (   |            |  A|!B vector |
```
*end of extractlargestring function*


                    
