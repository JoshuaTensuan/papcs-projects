Solo project to test knowledge of boolean expression trees (also worked on this with earlier calculator project)

Symbols and Precedence:
1. ! (not) - highest precedence
2. & (and), | (or), ^ (exclusive or)
3. > (implies) - lowest precedebce
T - true
F - false

To Run:
-build main.cpp
-input a boolean expression through the command line (case and whitespace insensitive)
-read output
-to exit loop, type "exit" (case and whitespace sensitive)

Code Layout:
-tree structure included in tnode.cpp
-methods to parse and evaluate included in parser.cpp
