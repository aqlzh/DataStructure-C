Description



初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，然后通过scanf读取一个元素（假如插入的是6），插入到第2个位置，打印输出顺序表，每个元素占3个空格，格式为1 6 2 3，然后scanf读取一个整型数，是删除的位置（假如输入为1），然后输出顺序表 6 2 3，假如输入的位置不合法，输出false字符串。提醒，Language一定要选为C++。



Input



第一次输入插入的元素值，第二次输入删除的位置



Output



假如插入的元素为6，那么输出为
1 6 2 3

假如删除的位置为1，那么输出为


6 2 3



Sample Input 1 

```
6
1
```

Sample Output 1

```
  1  6  2  3
  6  2  3
```

Sample Input 2 

```
9
3
```

Sample Output 2

```
  1  9  2  3
  1  9  3
```

Sample Input 3 

```
9
6
```

Sample Output 3

```
  1  9  2  3
false
```