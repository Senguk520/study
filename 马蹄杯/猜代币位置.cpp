/*标准答案*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> first(n + 1, m + 1);
    vector<int> last(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int input;
        cin >> input;
        first[input] = min(first[input], i);
        last[input] = i;
    }

    long long count = 0;

    for (int i = 1; i <= n; i++) {
        // 不移动：这个格子从来没被问过
        if (last[i] == 0) {
            count++;
        }

        // 从 i 移到 i - 1
        if (i > 1 && last[i - 1] < first[i]) {
            count++;
        }

        // 从 i 移到 i + 1
        if (i < n && last[i + 1] < first[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}




/*自己写的
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n,m;
    cin >> n >>m;
    vector<int>first(n+1,INT_MAX);
    vector<int>last(n+1,0   );

    int input;
    for(int i = 1;i<=m;i++){
        cin >> input;
        first[input]=min(first[input],i);
        last[input]=i;
    }

    for(int i= 1;i<=n;i++){
        if(first[i]==INT_MAX){
            first[i]=m+1;
        }
        
    }

    int count =0;
    for(int i = 1;i<=n;i++){
        if(i>1 && first[i]>last[i-1]){
            count++;
        }
        if(i<n && first[i]>last[i+1]){
            count++;
        }
        if(last[i]==0){
            count++;
        }
    }

    cout << count << endl;

}



*/