class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() ||
            beginWord == endWord)
            return 0;
        int m = wordList[0].size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> qb, qe;
        unordered_map<string, int> fromBegin, fromEnd;
        qb.push(beginWord);
        qe.push(endWord);
        fromBegin[beginWord] = 1;
        fromEnd[endWord] = 1;

        while (!qb.empty() && !qe.empty()) {
            if (qb.size() > qe.size()) {
                swap(qb, qe);
                swap(fromBegin, fromEnd);
            }
            int size = qb.size();
            for (int k = 0; k < size; k++) {
                string word = qb.front();
                qb.pop();
                int steps = fromBegin[word];
                for (int i = 0; i < m; i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word[i])
                            continue;
                        string nei = word.substr(0, i) +
                                     c + word.substr(i + 1);
                        if (!wordSet.count(nei))
                            continue;
                        if (fromEnd.count(nei))
                            return steps + fromEnd[nei];
                        if (!fromBegin.count(nei)) {
                            fromBegin[nei] = steps + 1;
                            qb.push(nei);
                        }
                    }
                }
            }
        }
        return 0;
    }
};