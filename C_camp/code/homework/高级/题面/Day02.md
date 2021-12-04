Description



图的顶点和边如下，直接初始化好，无需读取标准输入，完成有向图的邻接表初始化，完成深度优先遍历，广度优先遍历

char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

char edges[][2] = {

{'A', 'B'},

{'B', 'C'},

{'B', 'E'},

{'B', 'F'},

{'C', 'E'},

{'D', 'C'},

{'E', 'B'},

{'E', 'D'},

{'F', 'G'}};



Input



无需输入



Output



输出内容如下（注意每个字母占两个字符位置%2d）：

A B C E D F G

A B C E F D G



Sample Input 1 

```
无
```

Sample Output 1

```
 A B C E D F G
 A B C E F D G
```