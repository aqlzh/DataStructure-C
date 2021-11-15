**Description**

读取一个字符串，字符串可能含有空格，将字符串逆转，原来的字符串与逆转后字符串相同，输出0，原字符串小于逆转后字符串输出-1，大于逆转后字符串输出1。例如输入 hello，逆转后的字符串为 olleh，因为hello 小于 olleh，所以输出-1

注意最后的判断一定要这么写，因为strcmp标准C中并不是返回-1和1，而是负值和正值

int result = strcmp(c, d);

if (result < 0)

{

printf("%d\n",-1);

}

else if (result > 0)

{

printf("%d\n", 1);

}

else {

printf("%d\n", 0);

}



Input



输入一个字符串，例如 hello，当如输入的字符串也可能是 how are you，含有空格的字符串



Output



输出是一个整型数，如果输入的字符串是hello，那么输出的整型数为-1



Sample Input 1 

```
hello
```

Sample Output 1

```
-1
```

Sample Input 2 

```
cba
```

Sample Output 2

```
1
```

Sample Input 3 

```
aba
```

Sample Output 3

```
0
```

