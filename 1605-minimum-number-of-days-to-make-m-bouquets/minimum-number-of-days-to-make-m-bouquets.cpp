class Solution {
public:
    int minDays(vector<int>& arr, int m, int a) {
        if(long(m)*a>arr.size()) return -1;
        int i=INT_MAX,j=0;
        for(int k=0;k<arr.size();k++){
            i=min(i,arr[k]);
            j=max(j,arr[k]);
        }
        int ans=j;
        while(i<=j){
            int mid=i+(j-i)/2;
            int x=0;
            int count=0;
            int b=0;
            for(int k=0;k<arr.size();k++){
                x=max(x,arr[k]);
                b++;
                if(x>mid){
                    b=0;
                    x=0;
                }
                if(b==a){
                    count++;
                    x=0;
                    b=0;
                }
            }
            if(count>=m){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};