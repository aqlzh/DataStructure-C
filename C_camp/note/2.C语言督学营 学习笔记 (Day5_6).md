> Always continue; Never break ;
> 静心  心态   清晰的思路

![在这里插入图片描述](https://img-blog.csdnimg.cn/f55ff8373247400298a0fb5acbab5b07.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_16,color_FFFFFF,t_70,g_se,x_16)

@[toc]
# Day05 常用的输入输出原理
## scanf() 的使用

```c
#include <stdio.h>
int scanf( const char *format, ... );
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/011701c1952a45379859e85bf7769a2f.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- `format` 是一个字符串，…是可变参数，参数的数目与`format`中的`%`的数目保持一致
- `%d`	一个十进制整数
- `%f`  一个浮点数
- `%c`	一个单一的字符
## 标准输入缓冲区的原理

- C语言未提供输入/输岀关键字，其输入和输岀是通过标准函数库来实现的。C语言通过 `scanf`函数读取键盘输入，键盘输入又被称为标准输入。当 scanf函数读取标准输入时，如果还没有输入任何内容，那么 scanf函数会被卡住（专业用语为阻塞）.下面来看一个例子 


![在这里插入图片描述](https://img-blog.csdnimg.cn/673f11c181db45e7af8c9ce69bae61bb.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
执行时输入10,然后回车，显示结果如图所示。为什么第二个 scanf函数不会被阻塞呢？其实是因为第二个 scanf函数读取了缓冲区中的“`\n`”,即 scanf("%c",&c)实现了读取，打印其实输出了换行，所以不会阻塞

![在这里插入图片描述](https://img-blog.csdnimg.cn/db2c2e1046d5458990bfed7f7a87a26f.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
如上因为 `\n` 的ASCII  为10，确实被读取到了



## 缓冲区的原理

- **行缓冲**：在这种情况下，当在输入和输出中遇到换行符时，将执行真正的IO操作。这时，我们输入的字符先存放到缓冲区中，等按下回车键换行时才进行实际的IO操作。典型代表是标准输入缓冲区（ `stdin`）和标准输出缓冲区（ `stdout`）如上面中的例子所示，我们向标准输入缓冲区中放入的字符为10\n’，输入`"\n"`（回车）后，scanf函数才开始匹配， scanf函数中的%d匹配整型数10，然后放入变量i中，接着进行打印输出，这时`'\n'`仍然在标准输入缓冲区（ stdin）内，如果第二个 scanf函数为 `scanf（"%d"，&i）`，那么依然会发生阻塞，因为 scanf函数在读取**整型数、浮点数、字符串**（后面介绍数组时讲解字符串）时，==会忽略"\n'==（回车符）、空格符等字符（忽略是指 scanf函数执行时会首先删除这些字符，然后再阻塞）. scanf函数匹配一个字符时，会在缓冲区删除对应的字符。因为在执行 `scanf（"%c"，&c)`语句时，不会忽略任何字符，所以 `scanf（"%c"，&c）`读取了还在缓冲区中残留的`"\n"`


## printf() 的输出运用
- `printf ()`  函数可以输出各种类型 的数据，包括整型、浮点型、字符型、字符串型等，实际原理是  `printf ()` 函数将这些类型的**数据格式化为字符串**后，放入标准输出缓冲区，然后通过`\n'`来刷新标准输出，并将结果显示到屏幕上


- 位于%和格式化命令之间的一个整数被称为**最小字段宽度说明符**，通常会加上足够多的==空格或0==使输岀足够长。如果想填充0，那么就在最小字段宽度说明符前面放置0 .
- 另外，也可以使用一个精度修饰符，精度修饰符根据使用的格式代码的不同通常有着不同的含义·
- 用`%f` 精度修饰符指定想要的小数位数。例如，`%5.2f`会至少显示5位数字并带有2位小数的浮点数
- 用`%s`精度修饰符简单地表示一个最大的长度，以补充句点前的最小字段长度`printf`函数的所有输出都是右对齐的，除非在%符号后放置了负号。例如，`%-5.2f`会显示5位字符、2位小数位的浮点数并且左对齐

# Day05  scanf() 循环读取 
##  内存地址原理解析
- 32位地址总线  32位数据总线

比如：   `0x  00 B5 F7 0F`

```bash
0000 0000 1011 0101 1111 0111 0000 1111
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/c45a31b4ee674b2d87bcfb8825840dd9.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/6d33b5115a10428fb6abc5539be9151e.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

## scanf()  循环读取原理
- 如下图所示，如果想输入多个整数（每次输入都回车），让 scanf函数读取并打印输出，那么我们需要一个 While循环.代码中为什么要加入 fflush（ stdin）函数呢？因为 fflush函数具有刷新（清空）标准输入缓冲区的作用。如果我们输错了，输入的为字符型数据，那么 scanf函数就无法匹配成功， scanf函数未匹配成功时其返回值为0，即ret的值为0，但这并不等于EOF，因为EOF的返回值为-1.当scanf函数无法匹配成功时，程序仍然会进入循环，这时会导致不断地重复打印。 最后我们按组合键Ctrl+Z  （3次），让 scanf函数匹配失败，循环结束。 
![在这里插入图片描述](https://img-blog.csdnimg.cn/3295e09f7c3946e4906beabdaad5c474.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
- **关于疯狂打印的原理解析**

![在这里插入图片描述](https://img-blog.csdnimg.cn/6b7ee2ab477342cf90a1fdb360cc5a19.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/b56c80d765a74302872b3ee442b0732c.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- 如果scanf()遇到一个字符集(用%[]控制字符表示), 那么在括号中的任意字符都会读取到变量中. scanf()的返回值是成功赋值的变量数量, 发生错误时返回EOF. 

- ==解决办法，使用清空缓冲区==   `rewind(stdin)`
-  `rewind(stdin)` 一般用于整型和浮点型的时候
![在这里插入图片描述](https://img-blog.csdnimg.cn/713be51ce1c64a5a9e61bf0f912b43a1.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

> 注意： scanf () 混合输入,读取多种类型的数据，混合输入时每次在%c之前需要加入一个空格


- `printf()`  控制输出格式，%4.2  , 代表四个字符（包括小数点），小数点后两位。

## getchar函数介绍（了解）
- 使用 `getchar()`函数可以一次从标准输入读取一个字符，它等价于 `char a, scanf("%c",&c)`
 

```c
#include <stdio. h>
#include <stdlib. h>
int main {
 char c
 c=getchar() ;
 printf("you input alphabet=%c\n",c)
 system("pause")
}
```

## getchar() 函数介绍（了解）

```c
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

```

# Day06  运算符与表达式

## 运算符的分类


![在这里插入图片描述](https://img-blog.csdnimg.cn/a72527eda8b342ab8353c6604dcf3caf.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_18,color_FFFFFF,t_70,g_se,x_16)
- ==注意==：关于逻辑运算符的使用易错项 
- 类似于“ 逻辑短路 ” 
![在这里插入图片描述](https://img-blog.csdnimg.cn/96f3474bb8024de4ba6986560358eb44.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- 在上述的例子中无论 a  输入什么值， 都是输出 `a is right`  ;


## 关于判断两个浮点数是否相等
![在这里插入图片描述](https://img-blog.csdnimg.cn/b3c9647139c44db78c3dcaeb47a018b1.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- ==注意==： 上述的输出为 下者，原因在于IEEE 的浮点数（计算机组成原理的相关知识）

**正确写法如下**：
![在这里插入图片描述](https://img-blog.csdnimg.cn/49a7d1039fc24c8ea6ab1240bb481dcf.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_19,color_FFFFFF,t_70,g_se,x_16)
## 逻辑表达式
- ==注意==： 在C语言中没有布尔值，只有真与假（即为零和非零）
 
- 关于逻辑非的，注意事项，`int j = 10 , int i = !! j ;`  i 的最后的值并不是负负得正为`10` 而是 `1`

## 关于类型转化栈溢出
- 如下代码

```c
int main(){
   char a ;
   scanf("%d",%a) ;
   printf("%c\n",a) ;
}
```
- 上述代码发生如下报错

![在这里插入图片描述](https://img-blog.csdnimg.cn/9af1419d82044946b14a5afedcbe9a11.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- 通过调试，发现我们操作的空间超出了变量本身占用的空间。
![在这里插入图片描述](https://img-blog.csdnimg.cn/43c800881fcd44b4ac39d79f935bae2a.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- 正确代码写法如下：

```c
int main(){
   int  a ;
   scanf("%d",%a) ;
   printf("%c\n",a) ;
}
```

整型数在0-128之间可以用%c 输出
