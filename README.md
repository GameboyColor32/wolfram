# Wolfram Cellular Automata

This is a project that implements the Wolfram Cellular Automata in C. The goal of the project is to explore the subject of Cellular Automata and practice recursion.

## How it Works

The Wolfram Cellular Automata has 256 different rules that can be applied to a cell. Each rule will produce a different outcome, and the outcome depends on the state of the cell and its three neighboring cells from the previous generation. To implement this, the program decodes a byte to determine the rule to be applied to the cell.

To optimize the storage used by the program, a bitfield was used for the one-dimensional array that represents the current generation. Since each cell has only two possible states, storage is optimized using bitfields.

## Implementation Details

The program is written in C, which was chosen because of its high performance and the author's familiarity with the language. However, the project may also be remade in Haskell to explore a different paradigm and work in recursion only.

## Resources

For more information about the Wolfram Cellular Automata, please visit the [Wolfram MathWorld](https://mathworld.wolfram.com/ElementaryCellularAutomaton.html) website.

## Conclusion

This project has been an exciting and challenging way to learn more about Cellular Automata and practice recursion. Feel free to check out the source code in this repository and contribute to the project by opening a pull request or creating an issue.
