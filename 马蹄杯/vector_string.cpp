#include <bits/stdc++.h>
using namespace std;

using Point = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string>g(N);
    vector<Point>dui;
    for(int x = 0;x<N;x++){
        cin >> g[x];
        for(int y = 0;y<N;y++){
            if(g[x][y] == 'J'){
                dui.emplace_back(x,y);
            }
        }
    }

    auto inside = [&](int x,int y ){
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    auto IF_Excise = [&](Point C,Point D){
        auto [x3,y3]=C;
        auto [x4,y4]=D;

        if(!inside(x3,y3) || !inside(x4,y4)) return false;
        if(g[x3][y3] == 'B' || g[x4][y4]== 'B') return false;

        if(g[x3][y3]=='J' || g[x4][y4]=='J') return true;
        
        return false;
    };

    int ans = 0;

    for(int i = 0;i<(int)dui.size();i++){
        for(int j = i+1;j<(int)dui.size();j++){
            auto [x1,y1] = dui[i]; // Point A
            auto [x2,y2] = dui[j]; // Point B

            int vx = x2-x1;
            int vy = y2-y1;
            
            int ls_mj = vx*vx + vy*vy;//这里是求面积，向量求长度就是√(x²+y²)，而面积是长度的平方，故(√(x²+y²))² 化简就是x²+y²


            //情况一： dx 和 -dy
            Point C1 = {x1+vy,y1-vx};
            Point D1 = {x2+vy,y2-vx};
            //判断是否满足条件
            if(IF_Excise(C1,D1)){
                ans = max(ans,ls_mj);
            }

            //情况二： -dx 和 dy
            Point C2 = {x1-vy,y1+vx};
            Point D2 = {x2-vy,y2+vx};
            if(IF_Excise(C2,D2)){
                ans = max(ans,ls_mj);
            }

        }
    }

    // auto fill_other = [&](Point A,Point B){
    //     auto [x1,y1] = A;
    //     auto [x2,y2] = B;

    //     //求向量
    //     vx = x2-x1;
    // };
    cout << ans <<endl;
   
    return 0;
}
