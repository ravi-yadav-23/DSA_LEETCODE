class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int maj=0;

        for(int i=0;i<nums.size();i++){
            if(count==0){
                maj=nums[i];
                count++;
            }
            else if(nums[i]==maj){
                count++;
            }
            else{
                count--;
            }
        }
        return maj;
    }
};