class Solution {
public:
    
    int maximumSum(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>v(9,0);
        int k=2;
        int g=2;
        int y=2;
        for(int i=n-1;i>=0;i--)
        {
    
            if(nums[i]%3==0&&k>=0)
            {
                v[k]=nums[i];
                k--;
            }
                
            if(nums[i]%3==1&&g>=0)
            {
                v[g+3]=nums[i];
                g--;
            }
                
            if(nums[i]%3==2&&y>=0)
            {
               
                v[y+6]=nums[i];
                y--;
            }        
        }
        int ans=0;
        for(int i=0;i<9;i++)
            {
                for(int j=i+1;j<9;j++)
                    {
                        for(int k=j+1;k<9;k++)
                            {
                                
                                if(v[i]!=0&&v[j]!=0&&v[k]!=0)
                                {
                                    int s=v[i]+v[k]+v[j];
                        
                                    if(s%3==0)ans=max(ans,s);
                                }
                            }
                    }
            }
        
        
        
   return ans; }
};