#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        vector<string> words1 = splitSentence(sentence1);
        vector<string> words2 = splitSentence(sentence2);

        int n = words1.size();
        int m = words2.size();

        if (n < m) { //Check words1 is longer than words2 if not swap them
            swap(words1, words2);
            swap(n, m);
        }

        int i = 0, j = 0;

        while (i < m && words1[i] == words2[i]) { //Check prefix words
            i++;
        }
        
        while (j < m && words1[n - 1 - j] == words2[m - 1 - j]) { //Check from back
            j++;
        }
        return i + j >= m;
    }

private:
    vector<string> splitSentence(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence); //String stream helps with spliting, tokeninzing with int and float types.
        string word;

        while (ss >> word) { //Stream extraction is done from ss to word.
            words.push_back(word);
        }
        return words;
    }
};


auto tester(string& sentence1, string& sentence2) -> void {

    Solution soln;

    cout << "Sentence 1: " << sentence1 << endl;
    cout << "Sentence 2: " << sentence2 << endl;

    cout << "Are they similar?: " << (soln.areSentencesSimilar(sentence1, sentence2) ? "True" : "False") << endl;
    cout << endl;
}

auto main() -> int {

    string sent1 = "My Name is Sunil"; //Test case 1
    string sent2 = "My Sunil";
    tester(sent1, sent2);

    sent1 = "of";
    sent2 = "A lot of words";
    tester(sent1, sent2);

    sent1 = "Eating right now";
    sent2 = "Eating";
    tester(sent1, sent2);

    return 0;
}