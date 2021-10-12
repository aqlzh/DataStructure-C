#include <stdio.h>
#include <stdlib.h>
int main() {

	char a, b, c;
	a = 'a';
	b = 'b';
	c = 'c';
	putchar(a);
	//putchar('\b');  //输出转义字符  退格键
	putchar(b);
	putchar(c);
	putchar('\n');  //输出转义字符
	system("pause");
}
