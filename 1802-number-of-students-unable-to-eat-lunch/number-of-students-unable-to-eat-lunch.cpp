class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        for(int i=0;i<n;i++){
            int x=0;
            if(q.front()==sandwiches[i]){
                q.pop();
            }
            else{
                while(x<q.size() && q.front()!=sandwiches[i]){
                    x++;
                    q.push(q.front());
                    q.pop();
                }
                if(x==q.size()) return x;
                q.pop();
            }
        }
        return 0;
    }
};