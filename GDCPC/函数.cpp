/*
lambda 表达式笔记

一、lambda 的基本格式

auto 函数名 = [](参数列表) {
    函数体;
};

例如：写一个通用排序函数

auto paixu = [](auto &v) {
    sort(v.begin(), v.end());
};

使用：

vector<int> a = {3, 1, 2};
paixu(a);

排序后：
a = {1, 2, 3};


二、为什么左边用 auto

lambda 表达式的真实类型由编译器自动生成，类型名很复杂，
一般不能直接手写出来，所以用 auto 让编译器自动推导。

也就是：

auto paixu = 一个匿名函数;


三、参数为什么写 auto &v

auto &v 分成两部分看：

1. auto

表示参数类型自动推导。

这样这个函数就可以接收很多种容器：

vector<int> a;
vector<long long> b;
vector<pair<int, int>> c;

paixu(a);
paixu(b);
paixu(c);

如果写成：

vector<int> &v

那就只能排序 vector<int>。


2. &

表示引用传参。

排序需要修改原数组，所以必须传引用。

正确：

auto paixu = [](auto &v) {
    sort(v.begin(), v.end());
};

如果不写 &：

auto paixu = [](auto v) {
    sort(v.begin(), v.end());
};

这里的 v 是复制出来的一份，排序的是副本，
原来的数组不会变化。


四、[] 和 [&] 的区别

[] 表示不捕获外部变量。

例如：

auto paixu = [](auto &v) {
    sort(v.begin(), v.end());
};

这个函数只使用传进来的 v，不需要外面的变量，
所以用 [] 就够了。


[&] 表示按引用捕获外部变量。

例如：

int x = 10;

auto add = [&]() {
    x++;
};

add();

这时 x 会变成 11。

如果 lambda 函数体里面需要使用并修改外面的变量，
可以用 [&]。


五、排序常用模板

1. 升序排序

auto paixu = [](auto &v) {
    sort(v.begin(), v.end());
};


2. 降序排序

auto paixu_desc = [](auto &v) {
    sort(v.begin(), v.end(), greater<>());
};


3. pair 默认排序

vector<pair<int, int>> nums;

sort(nums.begin(), nums.end());

pair 默认排序规则：

先按 first 升序排序；
如果 first 相同，再按 second 升序排序。

例如：

{3, 2}, {1, 5}, {3, 1}, {2, 4}

排序后：

{1, 5}, {2, 4}, {3, 1}, {3, 2}


4. 只按 pair 的 first 排序

auto paixu_first = [](auto &v) {
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.first < b.first;
    });
};


5. 只按 pair 的 second 排序

auto paixu_second = [](auto &v) {
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
};


六、两数之和中常见用法

如果题目要求保留原下标，可以用 pair：

vector<pair<int, int>> nums(n);

for (int i = 0; i < n; i++) {
    cin >> nums[i].first;
    nums[i].second = i + 1;
}

auto paixu = [](auto &v) {
    sort(v.begin(), v.end());
};

paixu(nums);

这时：

nums[i].first  是数值；
nums[i].second 是原来的下标。

排序之后，first 会按从小到大排列，
second 负责保存原来的位置。
*/
