#include <bits/stdc++.h>
using namespace std;

/*用“指针”求丑数（这个指针是类比，是用另一个vector来标注目标需要乘uglg中对应的数的位置）*/
int main() {
    int S, n;
    cin >> S >> n;

    vector<long long> p(S);
    for (int i = 0; i < S; i++) {
        cin >> p[i];
    }

    vector<long long> ugly(n + 1);
    vector<int> idx(S, 0);
    ugly[0] = 1;
    for (int i = 1; i <= n; i++) {
        long long nxt = LLONG_MAX;
        for (int j = 0; j < S; j++) {
            nxt = min(nxt, p[j] * ugly[idx[j]]);
        }   
        ugly[i] = nxt;
        for (int j = 0; j < S; j++) {
            while (p[j] * ugly[idx[j]] <= nxt) {
                idx[j]++;
            }
        }
    }
    cout << ugly[n] << endl;
    return 0;
}






/*只用set版求丑数
#include<bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
         cin.tie(nullptr);
    set <long long>dui;
    set <int > fw;
    int S,n;
    cin >> S >>n;
    for(int i = 0 ;i<S;i++)
    {
        int var;
        cin >>var;
        fw.insert(var);    
    }

    dui.insert(1);
    long long result = 1;
    for(int i=0;i<n+1;i++)
    {
        result = *dui.begin();
        dui.erase(dui.begin());
        for(long long Min : fw){
            long long write = Min*result;
            dui.insert(write);
        }
    }
    cout << result <<'\n';

}
*/

/*用小根堆进行丑数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<long long, vector<long long>, greater<long long>> dui;
    set<long long> fw;
    unordered_set<long long> visited; // 去重
    
    int S;
    long long n;
    cin >> S >> n;
    
    // 读取质因数存入set
    for(int i = 0; i < S; i++) {
        long long var;
        cin >> var;
        fw.insert(var);
    }
    
    // 从1开始生成
    dui.push(1);
    visited.insert(1);
    
    long long result = 1;
    for(int i = 0; i < n; i++) {
        result = dui.top(); // 取出最小值
        dui.pop();
        
        // 用当前最小值乘以所有质因数，push进堆
        for(long long prime : fw) {
            long long next_val = result * prime;
            if(visited.find(next_val) == visited.end()) {//如果找不到next_val的话，那就是会返回visited的末尾位置，那如果与visited.end()相叠了就表示没有这个数
                dui.push(next_val);
                visited.insert(next_val);
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;

}

*/