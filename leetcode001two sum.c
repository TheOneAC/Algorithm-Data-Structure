/* c++ STL is much nore than what i think before in these aspects:
 * initializer for node element in struct node;
 * compare function in struct : overload operation
 * index not iterator used in this function.
 */
class Solution {
public:
    struct node{
    int value;
    int order;
    node(int v,int index):value(v), order(index){}
    };
    struct {
    bool operator()(node a, node b){    return a.value<=b.value; }
    }compare;
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>re;
        vector<node>sor;
        for(int i=0;i<nums.size();i++)sor.push_back(node(nums[i],i));
        sort(sor.begin(),sor.end(),compare);
        for(int tmp,i=0,j=sor.size()-1;i<j;)
        {
            tmp=sor[i].value+sor[j].value;
            if(tmp== target)
            {
                re.push_back(sor[i].order);
                re.push_back(sor[j].order);
                break;
            }
            else if(tmp < target)i++;
            else j--;
        }
        return re;
    }
   
};
