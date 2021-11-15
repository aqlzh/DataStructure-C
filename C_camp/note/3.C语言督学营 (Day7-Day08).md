>  必备的习惯 ： 感恩 自律 阅读 锻炼
负责的习惯 ： 不责备 不抱怨 不多解释
快乐的习惯 ： 不生气 不嫉妒  不多想  不说人非   


>人生在关键的时刻一定要做对的事！！ 
> 复盘  方法  高效

@[toc]

# 第07次直播 选择与循环

## 关系表达式与逻辑表达式
- 各个运算符的优先级顺序如下
 1. 单目运算符`！`逻辑非
 2. 算术运算符    加、减，乘除，取模
 3. 关系运算符   `> <   >=  <`
 4. 逻辑运算符   `&&  ||` 

例子：

![在这里插入图片描述](https://img-blog.csdnimg.cn/c35fdcfb66274f3b8a809e195bbad527.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

## 关于 if 语句使用

==**注意一： If   语句的写法。注意事项**==
![在这里插入图片描述](https://img-blog.csdnimg.cn/4066e28b865a4beda141f05f89e36e12.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- 不能按上述写法编写，否则下面的  `I  is  bigger  than 0`  ,无论输入什么条件都会一直执行。。



==**关于if   语句后面加大括号问题**==

![在这里插入图片描述](https://img-blog.csdnimg.cn/45ff294cf465450098475943c79048e4.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

## while  语句
- 当命令行（黑窗口），只有两种情况，①一种是卡在 `scanf（`这种情况下手输入内容，是可以输入进去的），②另外一种是死循环

- 在 Windows操作系统下的VS集成开发环境中，我们可以用`ffush`或 `rewind`清空标准输入缓冲区，但是这些函数在 Linux操作系统中是无法使用的。自己实现一个清空缓冲区的
 
```c
while((ch=getchar())!=EOF && ch!='\n') ;
```
## for 循环的使用

![在这里插入图片描述](https://img-blog.csdnimg.cn/71cc15629c48434f8f9433ec902bab20.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)


==while   语句中出现死循环的原因==  
 
- 1、 `while（）`后面加了分号
- 2、 while语句体内没有让表达式趋近于假的操作


**注意事项**： 关于在for()    语句后面加上 `;`  

![在这里插入图片描述](https://img-blog.csdnimg.cn/929ca929d4ed4c4b9281c6b262add19c.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

预期的结果为： 101 


## continue 、break语句
- continue   **跳出本轮循环**，即为从代码后面的语句不会执行
![在这里插入图片描述](https://img-blog.csdnimg.cn/29ad1991f562429190dcf2b2f30d1a1c.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- `break`  是结束整个循环

![在这里插入图片描述](https://img-blog.csdnimg.cn/1f39736d9bc54712b40eaee9aed5ee35.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)


# 第08次直播  数组  字符串数组
## 一维数组的表示
- 在C语言中一维数组的定义格式为 ： 

```c
类型说明符 数组名 [常量表达式3] ;   int a[10]; 
```
 
==声明数组时要遵循以下规则==：
- (1) 数组名的命名规则和变量名的相同，即遵循标识符命名规则 
- (2) 在定义数组时，需要指定数组中元素的个数，方括号中的常量表达式用来表示元素的个数，即数组长度。
- (3) 常量表达式中可以包含常量和符号常量，但不能包含变量。也就是说，**C语言不允许对数组的大小做动态定义**，即数组的大小不依赖于程序运行过程中变量的值。


## 一维数组在内存中的存储

![在这里插入图片描述](https://img-blog.csdnimg.cn/5962041acc8e4714aebf5a2646663e76.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_18,color_FFFFFF,t_70,g_se,x_16)
==进行调试==：


![在这里插入图片描述](https://img-blog.csdnimg.cn/d435722b10584ab880152f9b508b8759.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 小细节解析

### 存储空间分析

- 在微软中，先定义的变量存储于高地址
- 看任何变量的内存，都是将该变量取地址，拖入内存窗口来查看
- 微软的编译器设计，不同的变量之间有8个字节的保护空间（不是C标准）

微软编译器设计有8个字节的变量保护空间

![在这里插入图片描述](https://img-blog.csdnimg.cn/b27fa6e6eba14a7d8b9bfc2baa8992f0.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

### 数组打印易错分析

![在这里插入图片描述](https://img-blog.csdnimg.cn/605ae7645709491b8f64ee0fd2bbd381.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

- 上述的  `sizeof (a) / sizeof(int)`   仍然为1的原因为  `print()`  传递的数组个数为无法传递，只能传递首地址（数组的起始地址）

正确写法如下

![在这里插入图片描述](https://img-blog.csdnimg.cn/f7834869288c48b5894ba321445d4b8c.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)

> 注意： 在子函数中修改数组，原数组中也相应改变

![在这里插入图片描述](https://img-blog.csdnimg.cn/99876576bfc741358ac5e392d7bb3d88.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 字符数组
### 字符数组进行赋值
- 一般一个一个赋值较为麻烦，简写方式如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/b1f04c92d6d24929bfc8d10f53c88a1c.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 关于字符串数组常见错误
- 字符串输出乱码问题
![在这里插入图片描述](https://img-blog.csdnimg.cn/760c6876392142bd95f7c2dadcb1cea6.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
- hello 后面打出乱码“烫烫烫” 的原因，没有想 how 一样遇到结束符。
![在这里插入图片描述](https://img-blog.csdnimg.cn/88627a97ae22453f96cb2fd726bec532.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
- ==**总结结论**==： 在字符串初始化时一定要多初始化字节（用于存储结束符），`hello`    正好五个没有预留，how  三个足以存储。

- 因为C语言规定字符串的结東标志为  `'\0'`
- 上述正确写法为   `char c[6] = {'h','e','l','l','o'} ;`

**字符串的输入**
![在这里插入图片描述](https://img-blog.csdnimg.cn/9d111a6553b64c06b6b8848ee47f4bbf.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAUXVhbnR1bVlvdQ==,size_20,color_FFFFFF,t_70,g_se,x_16)
- 注意上述输入会自动添加结束符。


