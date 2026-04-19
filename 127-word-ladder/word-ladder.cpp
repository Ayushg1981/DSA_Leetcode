class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        if(s.find(endWord)==s.end()) return 0;

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);

        while(!q.empty()){
            string top=q.front().first;
            int level=q.front().second;
            q.pop();

            if(top==endWord) return level;

            for(int i=0;i<top.size();i++){
                string temp=top;
                for(char ch='a';ch<='z';ch++){
                    if(ch==top[i]) continue;
                    temp[i]=ch;

                    if(s.find(temp)!=s.end()){
                        q.push({temp,level+1});
                        s.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};