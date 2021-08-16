#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n, s = 0;
bool p(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main() {
    int i, j;
    cin >> n;//读入
    for (i = 4; i <= n; i++)//从4到n扫
        for (j = 2; j <= i / 2; j++)//因为1不是质数，不用考虑，一直到i的一半就可以了，不然i一减就重复了
            if (i % 2 != 0) break;//因为哥德巴赫猜想是说大于4的偶数，如果i是奇数就弹了
            else if (p(j) && p(i - j)) { cout << i << "=" << j << "+" << i - j << endl; break; }//其实没必要写else，因为如果不行的已经弹了，现在的i一定是偶数并且j和i-j都是质数的话就输出，再弹出这个循环
    return 0;
}