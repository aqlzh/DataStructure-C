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
    cin >> n;//����
    for (i = 4; i <= n; i++)//��4��nɨ
        for (j = 2; j <= i / 2; j++)//��Ϊ1�������������ÿ��ǣ�һֱ��i��һ��Ϳ����ˣ���Ȼiһ�����ظ���
            if (i % 2 != 0) break;//��Ϊ��°ͺղ�����˵����4��ż�������i�������͵���
            else if (p(j) && p(i - j)) { cout << i << "=" << j << "+" << i - j << endl; break; }//��ʵû��Ҫдelse����Ϊ������е��Ѿ����ˣ����ڵ�iһ����ż������j��i-j���������Ļ���������ٵ������ѭ��
    return 0;
}