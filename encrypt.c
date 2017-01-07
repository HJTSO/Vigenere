#include <string.h> 
#include <stdio.h> 

int main()
{
	int l,i,k;       //l是密钥的长度,i,k是计数用的
	char ch,key[50];	//ch是文件中读取的每个字符的变量,key是密钥字符串
	printf("please input key:\n");
	scanf("%s",key);
	for(i=0;key[i]!='\0';i++)
		l=i+1;   //计算密钥长度
	FILE *fin=freopen("mingwen.txt","r",stdin); //定义读取的文件指针,明文
   	FILE *fout=freopen("miwen.txt","w",stdout); //定义写入的文件指针,密文
	
	k = 0;
	while (!feof(fin)&&(ch!=-1))   
	{
		ch=fgetc(fin);     //每次从文件里读一个字符
		if(ch!=-1)		//判断是否到达文件尾
		{
			if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))	//如果该字符是字母的话
			{
			    k=k+1;                              //密钥每次自增
			    if(ch>='a'&&ch<='z')		//大小写分开加密
					ch=(ch-'a'+key[(k-1)%l]-'a')%26+'a';//如果字符在a和z之间则进行加密运算
			    else if(ch>='A'&&ch<='Z')
			    		ch=(ch-'A'+key[(k-1)%l]-'A')%26+'A';//如果字符在A和Z之间则进行加密运算
			}
			fputc(ch,fout);	    //加密后的字符写到文件
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

# Vigenere
