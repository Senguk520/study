#include <bits/stdc++.h>
using namespace std;
int main() {
   int n;
   cin >> n;
   vector<int > location(n);
   for(int i = 0;i<n;i++){
    cin >> location[i];
   }

   int all =0;
   for(int i = 0;i<n;i++){
    int count =1;
    for(int j = i -1;j>=0;j--){
        if(location[j]<=location[j+1]){
            count++;
        }else{
            break;
        }
    }

    for(int j = i + 1;j<n;j++){
        if(location[j-1] >= location[j]){
            count++;
        }else{
            break;
        }
    }
    all = max(count,all);
   }
   cout << all <<endl;
}
