#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Huffman.h"
#include "PatternMatching.h"

using namespace std;

int main() {
    cout << "Spelling Correction using Huffman and Pattern Matching Algorithms" << endl;

    // Read dictionary from file
    vector<string> dictionary;
    ifstream dictFile("dictionary.txt");
    string word;
    while (getline(dictFile, word)) {
        if (!word.empty()) {
            dictionary.push_back(word);
        }
    }
    dictFile.close();

    // Input word to check
    string inputWord;
    cout << "Enter a word to check spelling: ";
    cin >> inputWord;

    // Use Huffman coding to analyze frequency (for demonstration)
    Huffman huffman;
    huffman.buildFrequencyTable(dictionary);
    huffman.buildHuffmanTree();

    // Use pattern matching to find closest word in dictionary
    PatternMatching patternMatching;
    string correctedWord = patternMatching.findClosestWord(inputWord, dictionary);

    if (correctedWord == inputWord) {
        cout << "The spelling is correct." << endl;
    } else {
        cout << "Did you mean: " << correctedWord << "?" << endl;
    }

    return 0;
}
