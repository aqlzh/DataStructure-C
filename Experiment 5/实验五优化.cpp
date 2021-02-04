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
            printf("�ڴ����ʧ�ܣ�\n");
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
    printf("��Ϊ��\n");
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

// ���뷨���� 
HString Concat(HString str1,int pos,HString str2)
{
      if(pos<1||pos>str1.length)
      {
             printf("��������!\n");
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

// �������� 
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
	
	// t ����
	// s  ���� 
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
		
		int n = StrLength(S) ;  //  �� 
		int m = StrLength(T) ;   //��
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
	
	printf("--------------------�˵���--------------------------\n")  ;
	printf("      ��־�� ������ز���ʵ��     \n") ;
	printf("      (1) ���Ĵ���             1          \n") ;
	printf("      (2) �󴮵ĳ���           2          \n") ;
	printf("      (3) �������ıȽ�         3          \n") ;
	printf("      (4) �������             4        \n") ;
	printf("      (5) ��������             5         \n") ;
	printf("      (6) �󴮵��Ӵ�           6         \n") ;
	printf("      (6) ���Ӵ���������λ��   7        \n") ;
	printf("----------------------------------------------\n") ;
	
	printf("ע�⣺ Ĭ�ϴ�T  ABCDE\n\n") ; 
	printf("������Ҫ�Ĳ���\n") ; 
	scanf("%d",&val) ; 
	StrAssign(T,string) ; 
	//StrPrint(T) ;
	printf("\n\n") ;
	
	switch(val){
		case 1 :  
		
			printf("������Ҫ���ɵ��ַ���S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
			printf("\n") ;
			printf("���Ĵ�����ɽ������\n") ;
			StrPrint(S) ;
			break ; 
			
		case 2 :
			printf("������Ҫ���ɵ��ַ���S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
			printf("�ַ���S�Ĵ���Ϊ%d\n",StrLength(S)) ;
			break ;	
		
		
		case 3 :
			printf("��֪�� Ĭ�ϴ�T  ABCDE\n\n") ; 
			printf("������Ҫ���ɵ��ַ���S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
		    printf("�������ıȽϲ�ֵΪ%d\n",StrCompare(S, T))  ;
		    break ;	
		case 4 :
		    printf("������Ҫ���ɵ��ַ���S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
			printf("�ַ���S�Ĵ���Ϊ%d\n",StrLength(S)) ;
		    printf("��մ�\n") ;
		    ClearString(S) ;
		    printf("��ղ�����S�Ĵ���Ϊ%d\n",StrLength(S)) ;
		    break ;	
		case 5 :
		    	StrAssign(S1,"I Like");
	            StrAssign(S2," DataStructure");
	            strConcat(&T,S1,S2);
	            printf("S1��S2ƴ����ɺ��TΪ:%s\n",T.ch);
	            break ;	
	            
	    case 6 :
	    	printf("��֪�� Ĭ�ϴ�T  ABCDE\n\n") ; 
		  	StrSub(N,T,2,2)  ;
            StrPrint(N) ;
            break ;
            
        case 7 :
        	printf("��֪�� Ĭ�ϴ�T  ABCDE\n\n") ; 
		    printf("������Ҫ���ɵ��ַ���S\n") ;
			scanf("%s",&str) ;
			StrAssign(S,str) ;
	        printf("�ַ���S������T��λ��Ϊ%d",Index(S,T,1)) ; 
	        break ; 
	}

	 
	

    


	
}
