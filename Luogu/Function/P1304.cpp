#include <iostream>
using namespace std;
#include <algorithm>

/// <summary>
///  ��� ����     P1304 
/// ֪ʶ�� ������   �°ͺղ���
/// </summary>

// ����
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
		for (int j = 2; j <= n / 2; j += 2) {   // ������2 ��ʼ     n/2  ��ԭ��������  һ���Ϊ�ظ�
			if (is_prime(j) && is_prime(i - j)) cout << i << "=" << j << "+" << i - j << endl; break;
		}
	}

	system("pause");
	return 0;
}