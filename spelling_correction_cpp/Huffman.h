#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

struct CompareNode {
    bool operator()(HuffmanNode* const &n1, HuffmanNode* const &n2) {
        return n1->freq > n2->freq;
    }
};

class Huffman {
private:
    HuffmanNode* root;
    std::unordered_map<char, int> frequencyTable;
    std::unordered_map<char, std::string> huffmanCodes;

    void buildCodes(HuffmanNode* node, std::string str);
    void deleteTree(HuffmanNode* node);

public:
    Huffman();
    ~Huffman();

    void buildFrequencyTable(const std::vector<std::string>& words);
    void buildHuffmanTree();
    std::string getCode(char ch);
};

#endif
