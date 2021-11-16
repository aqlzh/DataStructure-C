Description



输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表，查找第二个位置的值并输出，在2个位置插入99，输出为 3 99 4 5 6 7，删除第4个位置的值，打印输出为 3 99 4 5 6 7。

输出函数如下：

void PrintList(LinkList L)

{

L = L->next;

while (L != NULL)

{

printf("%3d", L->data);//打印当前结点数据

L = L->next;//指向下一个结点

}

printf("\n");

}

针对双向链表，有时间的同学自己练习即可，这道题同样也可以用双向链表来实现一遍



Input



输入是3 4 5 6 7 9999



Output



输出是

4

3 99 4 5 6 7

3 99 4 6 7



Sample Input 1 

```
3 4 5 6 7 9999
```

Sample Output 1

```
4
  3 99  4  5  6  7
  3 99  4  6  7
```

Sample Input 2 

```
1 3 5 7 9 9999
```

Sample Output 2

```
3
  1 99  3  5  7  9
  1 99  3  7  9
```