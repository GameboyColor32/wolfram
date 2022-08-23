# Wolfram

I decided to program the Wolfram Cellular Automata since the subject intersts me. And I wanted to practice recursion.
I chose the C language since I'm familiar with it, and I love its performance. I might remake the project in Haskell
to explore a different paradigm and works in recursion only.

How does it work?
-----------------------------------
The Wolfram Cellular Automata has 256 differrent rules that can be applied on a cell.
Each rule will produce a different outcome. 256 bits is the size of a byte on your computer,
and a byte is precisely what is used to decode the rule. Once you decode the rule, you then know how
each cell will reproduce compared to its three neighboring cell from the previous generation.

To improve the space used by the program, I chose to use a bitfield for the one dimensional array
representing the current generation. Since each cell has only 2 possible states, storage
could be optimised with bitfields.

Ressources
-----------------------------------
-   Wolfram MathWorld: https://mathworld.wolfram.com/ElementaryCellularAutomaton.html
