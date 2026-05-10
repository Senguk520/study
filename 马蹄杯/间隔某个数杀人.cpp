#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;

    while (cin >> n >> k >> m) {
        if (n == 0 && k == 0 && m == 0) break;

        vector<bool> alive(n, true);
        int rest = n;

        int a = 0;      // A starts from 1
        int b = n - 1;  // B starts from n
        bool first = true;
        //这里的&alive和&n是捕获列表，表示lambda函数可以访问并修改外部的alive和n变量
        //当仅仅为[&]时，表示函数可以访问外部的所有变量，并且可以修改它们；当为[=]时，表示函数可以访问外部的所有变量，但不能修改它们；当为[&var1, var2]时，表示函数可以访问并修改var1，但只能访问var2，不能修改它。
        auto move = [&alive, &n](int pos, int dir, int cnt) {//定义一个lambda函数，模拟A和B的移动过程
            while (cnt > 0) {
                if (alive[pos]) {
                    cnt--;
                }

                if (cnt == 0) break;

                pos = (pos + dir + n) % n;
            }

            return pos;
        };

        while (rest > 0) {
            a = move(a, 1, k);
            b = move(b, -1, m);

            if (!first) cout << ",";
            first = false;

            cout << setw(3) << a + 1;

            if (a != b) {
                cout << setw(3) << b + 1;//按照题目要求输出格式，输出时每个数字占3个字符宽度
                alive[a] = false;
                alive[b] = false;
                rest -= 2;
            } else {
                alive[a] = false;
                rest--;
            }

            a = (a + 1) % n;
            b = (b - 1 + n) % n;
        }

        cout << endl;
    }

    return 0;
}
