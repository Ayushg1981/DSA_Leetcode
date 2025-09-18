class TaskManager {
public:
    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,int> mp;
    unordered_map<int,int> m;
    TaskManager(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++){
            mp[tasks[i][1]]=tasks[i][2];
            m[tasks[i][1]]=tasks[i][0];
            pq.push({tasks[i][2],{tasks[i][1],tasks[i][0]}});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority,{taskId,userId}});
        mp[taskId]=priority;
        m[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId]=newPriority;
        pq.push({newPriority,{taskId,m[taskId]}});
    }
    
    void rmv(int taskId) {
        mp[taskId]=-1;
    }
    
    int execTop() {
        while(pq.size()>0){
            auto x=pq.top();
            int prio=x.first;
            int task=x.second.first;
            int user=x.second.second;
            if(mp[task]==prio){
                rmv(task);
                return user;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */