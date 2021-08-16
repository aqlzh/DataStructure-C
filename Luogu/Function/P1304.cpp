#include <iostream>
using namespace std;
#include <algorithm>

/// <summary>
///  洛谷 函数     P1304 
/// 知识点 ：质数   德巴赫猜想
/// </summary>

// 质数
bool is_prime(int n){
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
		else return true;
	}
}


int main01() {
	int n;
	cin >> n;

	for (int i = 4; i <= n; i++) {
		for (int j = 2; j <= n / 2; j += 2) {   // 质数从2 开始     n/2  的原因后面减法  一版皆为重复
			if (is_prime(j) && is_prime(i - j)) cout << i << "=" << j << "+" << i - j << endl; break;
		}
	}

	system("pause");
	return 0;
}