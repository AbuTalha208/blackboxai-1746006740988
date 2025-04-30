#include "Huffman.h"
#include <iostream>

Huffman::Huffman() : root(nullptr) {}

Huffman::~Huffman() {
    deleteTree(root);
}

void Huffman::deleteTree(HuffmanNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void Huffman::buildFrequencyTable(const std::vector<std::string>& words) {
    frequencyTable.clear();
    for (const auto& word : words) {
        for (char ch : word) {
            frequencyTable[ch]++;
        }
    }
}

void Huffman::buildHuffmanTree() {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNode> pq;

    for (auto& pair : frequencyTable) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    root = pq.top();
    buildCodes(root, "");
}

void Huffman::buildCodes(HuffmanNode* node, std::string str) {
    if (node == nullptr) return;

    if (!node->left && !node->right) {
        huffmanCodes[node->ch] = str;
    }

    buildCodes(node->left, str + "0");
    buildCodes(node->right, str + "1");
}

std::string Huffman::getCode(char ch) {
    if (huffmanCodes.find(ch) != huffmanCodes.end()) {
        return huffmanCodes[ch];
    }
    return "";
}
