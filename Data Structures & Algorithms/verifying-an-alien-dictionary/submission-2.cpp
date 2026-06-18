class Solution {
public:

    bool checkAreInOrder(string &left,string &right, int alienLanguageIndexes[]){
	int n = left.size() , m = right.size();
	int i = 0;
	for(i;i<min(n,m);i++){
		if(left[i] == right[i]) continue;
		if(alienLanguageIndexes[left[i]-'a'] > alienLanguageIndexes[right[i]-'a']) return false;
		else return true;
	}
	if(i < n) return false;
	return true;

}

bool isAlienSorted(vector<string> &words,string order){
	int alienLanguageIndexes[26];
	for(int i=0;i<(int)order.size();i++){
		alienLanguageIndexes[order[i]-'a'] = i;
	}
	
	for(int i=0;i<(int)words.size()-1;i++){
		if(!checkAreInOrder(words[i],words[i+1],alienLanguageIndexes)) return false;
	}
	
	return true;
}
};