# Simple Puzzle solver mezzonic cache
Puzzle is called mezzonic cache found in World of Warcraft 9.2 in zereth mortis.
See Picture puzzle.webp
This Program solves the puzzle by brute force testing each possible combination. 

###### Compile natively in Linux or Windows:
$ gcc -O3 code.c

###### Compile in Linux for Windows:
$ i686-w64-mingw32-gcc -O3 code.c

###### Run in Windows:
-> open a.exe

###### Run in Linux:
$ ./a.out
 
#### Example Run:
[admin_t@archpc wow puzzle]$ ./a.out 
Number of possibilities for cross placement is 2^(5*5) = 33554432

Enter the values of the puzzle, e.g. line "1: 0 0 1 0 1", confirm each line with enter.
   v v v v v
1: 0 0 0 0 0
2: 0 1 0 0 0
3: 0 0 0 0 0
4: 0 0 0 0 0
5: 0 0 0 0 0

searching solution positions for:
|0|0|0|0|0|
|0|1|0|0|0|
|0|0|0|0|0|
|0|0|0|0|0|
|0|0|0|0|0|

Testing Combination 2293760 out of 33554432

Success!

Result Combination Number: 2335594
Result Positions for cross placements:
|0|1|0|1|0|
|1|1|0|1|1|
|0|0|0|1|0|
|1|1|1|0|0|
|0|1|0|0|0|


Press enter to exit
