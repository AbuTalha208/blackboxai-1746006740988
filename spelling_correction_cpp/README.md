# Spelling Correction Project in C++

This project implements a simple spelling correction tool using Huffman algorithm and pattern matching algorithm in C++.

## Project Structure

- `main.cpp`: Main program demonstrating spelling correction.
- `Huffman.h` and `Huffman.cpp`: Implementation of Huffman coding algorithm for frequency analysis.
- `PatternMatching.h` and `PatternMatching.cpp`: Implementation of pattern matching algorithm using edit distance to find closest word.

## How It Works

1. The program builds a frequency table of characters from a dictionary of correct words using Huffman coding.
2. It then uses a pattern matching algorithm (edit distance) to find the closest word in the dictionary to the input word.
3. If the input word is not correct, it suggests the closest matching word.

## Build Instructions

Use g++ to compile the project:

```bash
g++ -o spelling_correction main.cpp Huffman.cpp PatternMatching.cpp
```

## Run Instructions

Run the compiled executable:

```bash
./spelling_correction
```

Enter a word to check its spelling and get suggestions if the spelling is incorrect.

## Notes

- This is a simple demonstration project for educational purposes.
- The Huffman algorithm is used here mainly for frequency analysis and demonstration.
- The pattern matching algorithm uses edit distance to find the closest word.
