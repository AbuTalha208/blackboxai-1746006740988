#ifndef PATTERNMATCHING_H
#define PATTERNMATCHING_H

#include <string>
#include <vector>

class PatternMatching {
public:
    PatternMatching();

    // Find the closest word in the dictionary to the input word using edit distance
    std::string findClosestWord(const std::string& input, const std::vector<std::string>& dictionary);

private:
    int editDistance(const std::string& s1, const std::string& s2);
};

#endif
