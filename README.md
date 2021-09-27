COMMENT: THIS GAME WAS MADE FOR AN EXAM OF PROGRAMMING 1 FOR THE UNIVERSITY PROGRAMMING CAREER. IN GROUPS OF 3
STUDENTS AND WITH A DEADLINE OF 2 WEEKS. AT THAT TIME WE DIDN'T HAVE KNOWLEDGE IN OBJECTS ORIENTATED PROGRAMING
AND STRUCTS, THAT  WOULD HAVE SIMPLIFIED CODE.

EXAM STATEMENTS LINK: https://drive.google.com/file/d/1A93nGB2VdOVF7yqzc0hKuqTddVaJZOiX/view?usp=sharing

MATHrix game

Mathrix is an individual game where you can test your math skills. Consists in
a 6x6 matrix that is filled in with randomly located numbers from 0 through 9.


The general objective of the game is to score as many points as possible over the course of
rounds until you run out of batteries. The game begins with a total of three bateries.
Over the gameplay, the player must enter the coordinate of the first number position(row and column)
from where you want to build an equation.


After this step, you must choose the necessary mathematical operator for the equation:

(+) SUM
(-) SUBSTRACTION
(*) MULTIPLICATION
(/) DIVISION
(%) REMAINDER

Lastly, you need to choose the direction in which the equation is solved. Values can be:

(8) UP
(2) DOWN
(4) LEFT
(6) RIGHT

The game should try to solve the equation taking into account the values entered by the
user, starting from the selected cell and using the adjacent cells that are are in the chosen direction.
Every equation is formulated as follows: A ± B = C.

(1) - Therefore, if the user enters:
- Row: 5
- Column: 3
(2) - Then the operation: + (Sum)
(3) -And finally, enter: 4 (left)

The game will check if the equation is correct. If the equation is correct, the user will obtain the equivalent score for that round
to the sum of the three numbers that took part in the equation (A + B+ C).
Next, the game must lock the cells used and advance to the next round.
In the case that the equation is not correct or out of bounds the player loses a battery.
