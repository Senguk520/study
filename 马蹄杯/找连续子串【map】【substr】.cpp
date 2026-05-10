#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n;
    string s;
    map<string,int> mp;
    cin >> n >> s;

    for(int i = 0 ; i < n -1 ; i++)//只要 i 后面还有一个字符，就可以组成长度为 2 的子串。
    {
        mp[s.substr(i,2)]++;
    }

    string ans = "";
    int best = 0;
    for(auto val : mp){
        if(val.second > best){
            best = val.second;
            ans = val.first;
        }
    }

    /*
    //不同的写法
    string ans;
    int best = 0;
    for (auto [sub, num] : mp) {
        if (num > best) {
            best = num;
            ans = sub;
        }
    }
    */
    cout << ans << endl;
    return 0;
}