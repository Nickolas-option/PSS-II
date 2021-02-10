#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;
typedef vector<tuple<string, int, vector<int>>> container;

pair<container, vector<basic_string<char>>>* read() {
    ifstream myReadFile("in.txt");
    string lineInput;
    vector<string> sentences;
    char currentChar;
    bool fullstop = false;
    myReadFile.get(currentChar);
    while (currentChar != '\n') {    //reading only first line
        lineInput.push_back(currentChar);
        if (currentChar == '.') {   //the end of the sentence
            sentences.push_back(lineInput);   //saving current sentence to vector
            lineInput.clear();
            fullstop = true;
        }
        myReadFile.get(currentChar);
        if (fullstop && currentChar == ' ') {
            while (currentChar == ' ') {
                myReadFile.get(currentChar);
            }
            fullstop = false;
        }
    }
    //now reading words
    int quantityOfNeededWords;
    vector<tuple<string, int, vector<int>>> neededWords;
    //string - the word; int - number of occurrences; vector - array of indexes of sentences with this word;
    myReadFile >> quantityOfNeededWords;
    string neededWord;
    getline(myReadFile, neededWord);  // this getline helps to move the caret to next word
    // (for some reason the caret is in another place xD)
    for (int i = 0; i < quantityOfNeededWords; ++i) {
        getline(myReadFile, neededWord);
        neededWords.emplace_back(make_tuple(neededWord, 0, 0));
    }
    myReadFile.close();
    auto _ = new pair<container, vector<basic_string<char>>> (neededWords, sentences);
    return _;
}

pair<container, vector<basic_string<char>>> search (container neededWords, vector<basic_string<char>> sentences) {
    for (auto &[word, qty, indexesOfSentences] : neededWords) {
        for (int sentenceIndex = 0; sentenceIndex < sentences.size(); ++sentenceIndex) {
            auto &string = sentences[sentenceIndex];
            while (string.find(' ' + word + '.') != string::npos || string.find(' ' + word + ' ') != string::npos) {
                qty++;  // add +1 occurrence of word in sentence
                if (find(begin(indexesOfSentences), end(indexesOfSentences), sentenceIndex) == end(indexesOfSentences)) {
                    indexesOfSentences.emplace_back(sentenceIndex); //if no repetition - save index of sentence to array
                }
                for (int firstIndex = string.find(word), letter = firstIndex; letter < firstIndex + word.length(); letter++)
                    string[letter] = toupper(string[letter]);
            }
        }
    }
    pair<container, vector<string>> _ (neededWords, sentences);
    return _;
}

int main() {
    auto [x, y] = *read();
    auto [neededWords, sentences] = search(x, y);

    ofstream myOutputFile("out.txt");
    for (auto &[printWord, printNum, printInd] : neededWords) {
        myOutputFile << printNum << '\n';
        for (auto &currentInd : printInd) {
            myOutputFile << sentences[currentInd] << '\n';
        }
    }
    myOutputFile.close();
    return 0;
}