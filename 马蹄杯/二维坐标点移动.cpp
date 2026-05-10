
//直接算出移动K后的结果
#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int N,M;
    cin >> N >> M;
    vector<int >dui(N*M);
    vector<int>jg(N*M);
    for(int i = 0 ;i<N*M;i++){
        cin >> dui[i];
    }
    int K;
    cin >> K;
    K%=(N*M);
    for(int i = 0;i<N*M;i++){
         jg[(i+K)%(N*M)]=dui[i];
    }
    for(int a = 0;a<N;a++){
        for(int b = 0;b<M;b++){
            cout << jg[a*M+b] << " ";
        }
        cout << endl;
    }
    return 0;
}


//用LB充当链表
/*
#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int N,M;
    cin >> N >> M;
    vector<int >dui(N*M);
    vector<int >LB(N*M);
    for(int i = 0 ;i<N*M;i++){
        cin >> dui[i];
        LB[i]=i;
    }
    int K;
    cin >> K;
    K%=(N*M);
    for(int a = 1;a<=K;a++){
        for(int i = 0 ;i<N*M;i++){
            LB[i]=(LB[i]+1)%(N*M);
        }
    }
    vector<int>jg(N*M);
    for(int i = 0;i<N*M;i++){
        jg[LB[i]]=dui[i];
    }
    for(int a = 0;a<N;a++){
        for(int b = 0;b<M;b++){
            cout << jg[a*M+b] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/