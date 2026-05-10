/*使用大根堆*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long L;
    cin >> n >> L;

    priority_queue<long long> dui;

    for (int i = 0; i < n; i++) {
        long long input;
        cin >> input;
        dui.push(input);
    }

    long long maxPos = dui.top();
    double ans = L - maxPos;

    long long last = dui.top();
    dui.pop();

    while (!dui.empty()) {
        long long cur = dui.top();
        dui.pop();

        ans = max(ans, (last - cur) / 2.0);
        last = cur;
    }

    ans = max(ans, last * 1.0);

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}



/*对用户输入的数进行排序*/
/*古法编程
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long L;
    cin >> n >> L;
    vector <long long> dui(n);
    for(int i = 0;i<n;i++){
        cin >> dui[i];
    }
    sort(dui.begin(),dui.end());
    double jg = max(dui[0],(L-dui[n-1]))*1.0;
    for(int i = 1;i<n;i++){
        jg = max(jg,(dui[i] - dui [i-1]/2.0));
    }
    cout << fixed << setprecision(2) << jg <<endl;//这部分中fixed是表示“固定小数位输出” | setprecision(2)是表示“保留两位有效数字”
    // 如果没有 fixed，setprecision(2) 表示最多保留 2 位有效数字。
    // 当 jg = 234 时，输出结果是：230
    // 相当于fixed是把保留两位有效数字转到了小数点后
    
} 
*/

/*AI生成的答案
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L;
    cin >> n >> L;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double ans = max(a[0], L - a[n - 1]) * 1.0;

    for (int i = 1; i < n; i++) {
        ans = max(ans, (a[i] - a[i - 1]) / 2.0);
    }

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}

*/

