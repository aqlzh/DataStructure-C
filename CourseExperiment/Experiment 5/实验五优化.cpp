# include  <stdio.h>
# include  <stdlib.h>

#define OVERFLOW -1

typedef enum Bool
{
    FALSE,TRUE
}Bool; 


typedef struct {
	char * ch ;
	int length ;
} HString ;


Bool StrAssign(HString &T,const char * chars)
{
    int i;
    for(i = 0;*(chars+i);i++);
    if(i == 0)
    {
        T.ch = NULL;
        T.length = 0;
    }
    else
    {
        T.ch = (char *)malloc(i*sizeof(char));
        if(!T.ch)
        {
            printf("内存分配失败！\n");
            return TRUE;
        }
        else
        {
            for(int j = 0;j < i;j++)
            {
                *(T.ch+j) = *(chars+j);
            }
            T.length = i;
        }
    }
    return TRUE;
}


Bool StrPrint(HString &T)
{
    int i;
    i = T.length;
    if(i==0)
    printf("串为空\n");
    for(i = 0;i <T.length;i++)
    {
        printf("%c",*(T.ch+i));
    }
    return TRUE;
}

int StrLength(HString S){
	return S.length ;
}  


int StrCompare(HString S, HString T){
	for(int i = 0 ; i <S.length && i < T.length ; ++ i )
	  if(S.ch[i] != T.ch[i] )    return S.ch[i] - T.ch[i]  ;
	  printf("%c",S.ch[1]) ;
	  printf("%c",T.ch[1]) ;
	  return S.length - T.length ;
}

Bool ClearString(HString &S){
	if(S.ch) {
		free(S.ch) ;
		S.ch = NULL ;
	}
	S.length = 0;
	return TRUE  ;
} 

// 插入法连接 
HString Concat(HString str1,int pos,HString str2)
{
      if(pos<1||pos>str1.length)
      {
             printf("操作错误!\n");
             exit(0);
      }
      int i;
      for(i=pos;i<=str1.length;i++)
      {
            str1.ch[i+str2.length]=str1.ch[i];
      }
      for(i=0;i<=str2.length;i++)
      {
            str1.ch[i+pos-1]=str2.ch[i];
      }
      str1.length=str2.length+str1.length;
      return str1;
}

// 常规连接 
Bool strConcat(HString *T,HString S1,HString S2){
  if(T->ch)free(T->ch);

  int j;
  int i = S1.length + S2.length;
  T->ch = (char*)malloc(i*sizeof(char));

  for(j=0;j<S1.length;j++)
    T->ch[j]=S1.ch[j];

  for(j=S1.length;j<i;j++)
    T->ch[j]=S2.ch[j-S1.length];

  T->length = i;

  return TRUE;
}

int StrSub(HString &s,HString t,int pos,int n)
{
	
	// t 操作
	// s  返回 
    int i;
    if(n < 0 || n > t.length ||pos < 1  || pos > t.length-pos+1)
    {
        printf("error\n");
        return FALSE;
    }
    if(n == 0)
    {
        s.ch = NULL;
        s.length = 0;
    }
    else
    {
        s.ch = (char *)malloc(n *sizeof(char));
        for( i = 0;i < n;i++)
        {
            *(s.ch+i) = *(t.ch+pos+i-1);
        }
        s.length = n;

    }
    return TRUE;
}



int Index(HString S ,HString T , int pos){
	
	HString sub ; 

	if(pos > 0){
		
		int n = StrLength(S) ;  //  子 
		int m = StrLength(T) ;   //主
		int i = pos ;

	
		while( i <= m-n+1){
			
			StrSub(sub,T,i,n) ;
			if(StrCompare(sub,S) != 0)  ++i ;
			else {
			
				printf("%d",i) ;

				return i ;
			}
		}
	}

}



int main(){
	
	
	HString T ,S, N,S1,S2;
	char string[50] = "ABCDE";
	char str[50]  ;
	int val ;
	
	printf("--------------------菜单栏--------------------------\n")  ;
	printf("      李志鸿 串的相关操作实验     \n") ;
	printf("      (1) 串的创建             1          \n") ;
	printf("      (2) 求串的长度           2          \n") ;
	printf("      (3) 两个串的比较         3          \n") ;
	printf("      (4) 串的清空             4        \n") ;
	printf("      (5) 串的连接             5         \n") ;
	printf("      (6) 求串的子串           6         \n") ;
	printf("      (6) 求子串在主串的位置   7        \n") ;
	printf("----------------------------------------------\n") ;
	
	printf("注意： 默认串T  ABCDE\n\n") ; 
	printf("请输入要的操作\n") ; 
	scanf("%d",&val) ; 
	StrAssign(T,string) ; 
	//StrPrint(T) ;
	printf("\n\n") ;
	
	switch(val){
		case 1 :  
		
			printf("请输入要生成的字符串S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
			printf("\n") ;
			printf("串的创建完成结果如下\n") ;
			StrPrint(S) ;
			break ; 
			
		case 2 :
			printf("请输入要生成的字符串S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
			printf("字符串S的串长为%d\n",StrLength(S)) ;
			break ;	
		
		
		case 3 :
			printf("已知： 默认串T  ABCDE\n\n") ; 
			printf("请输入要生成的字符串S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
		    printf("两个串的比较差值为%d\n",StrCompare(S, T))  ;
		    break ;	
		case 4 :
		    printf("请输入要生成的字符串S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
			printf("字符串S的串长为%d\n",StrLength(S)) ;
		    printf("清空串\n") ;
		    ClearString(S) ;
		    printf("清空操作后，S的串长为%d\n",StrLength(S)) ;
		    break ;	
		case 5 :
		    	StrAssign(S1,"I Like");
	            StrAssign(S2," DataStructure");
	            strConcat(&T,S1,S2);
	            printf("S1，S2拼接完成后的T为:%s\n",T.ch);
	            break ;	
	            
	    case 6 :
	    	printf("已知： 默认串T  ABCDE\n\n") ; 
		  	StrSub(N,T,2,2)  ;
            StrPrint(N) ;
            break ;
            
        case 7 :
        	printf("已知： 默认串T  ABCDE\n\n") ; 
		    printf("请输入要生成的字符串S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
	        printf("字符串S在主串T的位置为%d",Index(S,T,1)) ; 
	        break ; 
	}

	 
	

    


	
}
