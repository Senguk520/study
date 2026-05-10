/*古法编程  //在first=second处其实是可以补上直接跳到有能真正合并的轮次的代码，加快效率，现在确实是每一轮都扫一遍
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,var;
    cin >> n;
    vector<int >dui(n+1);
    vector<int >LB(n+1);
    for(int i = 1;i<=n;i++){
        cin >> dui[i];
        if(i==n){
            LB[i]=0;
        }else{
        LB[i]=i+1;
    }
}  

    int second = 0;
    int third = 0;
    int rest = n;
    int cs =0;
    while(rest > 2){
        cs++;
        int first = 1;
        while(first!=0&&rest>2){
            second = LB[first];
            if(second == 0){
                break;
            }
            third = LB[second];
            if(third == 0){
                break;
            }
            int sum = dui[first]+dui[second]+dui[third];
            if(sum <= cs*3){
                dui[first]=sum;
                LB[first]=LB[third];
                rest-=2;
                first=LB[first];
            }else{
                first=second;
            }

    }
        
    }
    cout << cs <<endl;

    

    return 0;
}
*/


