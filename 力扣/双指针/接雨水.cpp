/*
前后缀判别法
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pro(n,0);
        pro[0] = height[0];
        for(int i = 1;i<n;i++){
            pro[i]=max(pro[i-1],height[i]);
        }

        vector <int> Sen(n,0);
        Sen[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            Sen[i] = max(Sen[i+1],height[i]);
        }

        int count = 0;
        for (int i = 0; i<n;i++){
            int a = n-i-1;
            count += min(pro[i],Sen[i])-height[i];
        }
        return count;
    }
};
*/


/*
双指针法
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pro(n,0);
        pro[0] = height[0];
        for(int i = 1;i<n;i++){
            pro[i]=max(pro[i-1],height[i]);
        }

        vector <int> Sen(n,0);
        Sen[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            Sen[i] = max(Sen[i+1],height[i]);
        }

        int count = 0;
        for (int i = 0; i<n;i++){
            int a = n-i-1;
            count += min(pro[i],Sen[i])-height[i];
        }
        return count;
    }
};
*/