#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    long long n,m,s;
    cin >> n >> m >> s;
    
    long n_y = n%s;
    long ncs = n/s;
    if(n_y>0){//如果n%s有余数，就说明可以整体移动多少格，如果没有余数，那就是可以整体移动s格
        ncs++;//如果有余数，说明有一部分是不完整的，那这部分在使用“/”的时候会一起被抹去，所以需要自增
    }else{
        n_y=s;
    }

    long m_y = m%s;
    long mcs = m/s;
    if(m_y>0){
        mcs++;   
    }else{
        m_y=s;
    }


    long sum = m_y*n_y*ncs*mcs;
    cout << sum;
    return 0;
}