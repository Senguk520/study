
//两数求和
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , target;
    cin >> n >> target;
    vector<int>dui(n);
    for(int i = 0;i<n;i++){
        cin >> dui[i];
    }
    int L = 0;
    int R = n-1;
    while(R>L){
        if(dui[L]+dui[R] == target){
            break;
        }
        if(dui[L]+dui[R] > target){
            R--;
            continue;
        }else{
            L++;
            continue;
        }
    }
    cout << L+1 << "|" << R+1;
    return 0;
}
