#include "text_justification.h"

using std::string;
using std::vector;

void putSpaces(string &str, unsigned int count) {
    for (int i = 0; i < count; i++) {
        str.push_back(' ');
    }
}

string createLastLine(const vector<string> &words, int wordsInLine, int width) {
    int start = words.size() - wordsInLine;
    string line;
    int letters = 0;
    for (int i = 0; i < wordsInLine; i++) {
        letters += words[start + i].size();
        line.append(words[start + i]);
        if (i < wordsInLine - 1) {
            line.push_back(' ');
            letters++;
        }
    }
    if (letters < width) {
        putSpaces(line, width - letters);
    }
    return line;
}

string createLine(const vector<string> &words, int scanned, int wordsInLine, int letters, int width) {
    int start = scanned - wordsInLine;
    int totalSpaces = width - letters;
    int average = wordsInLine == 1 ? 0 : (totalSpaces / (wordsInLine - 1));
    int leftSpaces = wordsInLine == 1 ? 0 : (totalSpaces % (wordsInLine - 1));
    string line;
    for (int i = start; i < start + wordsInLine - 1; i++) {
        line.append(words[i]);
        int space = average;
        if (leftSpaces > 0) {
            space++;
            leftSpaces--;
        }
        putSpaces(line, space);
    }
    line.append(words[start + wordsInLine - 1]);
    if (wordsInLine == 1) {
        putSpaces(line, width - letters);
    }
    return line;
}


vector<string> text_justification::Solution::fullJustify(vector<string> &words, int maxWidth) {
    auto lines = vector<string>();
    int letters = 0;
    int ws = 0;
    int wordsInLine = 0;
    int wordsScanned = 0;
    for (auto &word: words) {
        int wordSize = word.size();
        if (wordSize <= maxWidth - letters - ws) {
            letters += wordSize;
            ws++;
            wordsInLine++;
        } else {
            lines.push_back(createLine(words, wordsScanned, wordsInLine, letters, maxWidth));
            letters = word.size();
            ws = 1;
            wordsInLine = 1;
        }
        wordsScanned++;
    }
    lines.push_back(createLastLine(words, wordsInLine, maxWidth));
    return lines;
}
