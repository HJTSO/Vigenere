#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 1000000

float IC(int show[26])	//计算IC
{
	int i;
	float ic,n=0,m=0;
	for(i=0;i<26;i++)
	{
		n=n+show[i];			     //n表示所有字母的总数
		m=m+show[i]*(show[i]-1);   //show[i]是第i个字母出现的次数
	}
	ic=m/(n*(n-1));
	return ic;
}
int MAX(int show[26])
{
	int m=0,max,i;
	for(i=0;i<25;i++)
		if(m<show[i])
		{
			m=show[i]; //记录的是出现次数最多的字母数的位置
			max=i+1;
		}
		return max;
}
int main()
{
	int i=0,j=0,k=0,l=0,d=1,letter[26],n,m;
	float ic;
	char encrypt[N]={"a"},ch,keyword[100]={"a"},s;
	FILE *fin,*fout;

	if((fin=fopen("miwen.txt","r"))==NULL)      //打开密文文件
	{
		printf("can't open miwen.txt\n");
		return;
	}
	while(!feof(fin))
	{
		ch=fgetc(fin);
		if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))
		{
			l=l+1;               //统计密文的字母总数
			encrypt[i]=ch;	//把所有的字母输入到encrypt数组中
			i++;				
		}

	}  
	fclose(fin);
	printf("total of letters: %d\n",l);
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<i+1;j++)      //对于每组每一行的遍历
		{
			for(n=0;n<26;n++)   //初始化letter数组
			{
				letter[n]=0;
			}
			for(n=0;(n<N/(i+1)+1)&&encrypt[j+n*(i+1)]!='\0';n++)
			{							
			 	m=encrypt[j+n*(i+1)]-'a';     //求出该字母在字母表中的位置
			 	letter[m]+=1;	//统计每个字母出现的次数,保存在letter数组中
			}
			ic=IC(letter);	//根据letter数组计算出ic
			if (fabs(ic-0.065)>0.010)		//测试ic是否符合,若超出0.010的误差,则继续寻找最佳ic值的情况
				continue;
		}
		if (fabs(ic-0.065)<=0.01)             //当ic的值足够接近0.065,则继续
		{
			d=i+1;
			break;                 //d代表分成几组
		}
	}
	
	//计算密钥
	for(j=0;j<d;j++)
	{
		for(n=0;n<26;n++)                   //置0
			letter[n]=0;
		for(n=0;(n<N/d+1)&&encrypt[j+n*d]!='\0';n++) //统计各个字母的出现次数
		{
			 m=encrypt[j+n*d]-'a';
			 letter[m]+=1;
		}
		keyword[j]=(21+MAX(letter))%26+'a';       //由于出现概率最大的字母即为e,相当于加上21
	}
	printf("the key is: %s\n",keyword);               //打印密钥
	return 0;
}

# Vigenere
