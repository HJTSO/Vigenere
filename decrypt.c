#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 1000000

float IC(int show[26])	//����IC
{
	int i;
	float ic,n=0,m=0;
	for(i=0;i<26;i++)
	{
		n=n+show[i];			     //n��ʾ������ĸ������
		m=m+show[i]*(show[i]-1);   //show[i]�ǵ�i����ĸ���ֵĴ���
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
			m=show[i]; //��¼���ǳ��ִ���������ĸ����λ��
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

	if((fin=fopen("miwen.txt","r"))==NULL)      //�������ļ�
	{
		printf("can't open miwen.txt\n");
		return;
	}
	while(!feof(fin))
	{
		ch=fgetc(fin);
		if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))
		{
			l=l+1;               //ͳ�����ĵ���ĸ����
			encrypt[i]=ch;	//�����е���ĸ���뵽encrypt������
			i++;				
		}

	}  
	fclose(fin);
	printf("total of letters: %d\n",l);
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<i+1;j++)      //����ÿ��ÿһ�еı���
		{
			for(n=0;n<26;n++)   //��ʼ��letter����
			{
				letter[n]=0;
			}
			for(n=0;(n<N/(i+1)+1)&&encrypt[j+n*(i+1)]!='\0';n++)
			{							
			 	m=encrypt[j+n*(i+1)]-'a';     //�������ĸ����ĸ���е�λ��
			 	letter[m]+=1;	//ͳ��ÿ����ĸ���ֵĴ���,������letter������
			}
			ic=IC(letter);	//����letter��������ic
			if (fabs(ic-0.065)>0.010)		//����ic�Ƿ����,������0.010�����,�����Ѱ�����icֵ�����
				continue;
		}
		if (fabs(ic-0.065)<=0.01)             //��ic��ֵ�㹻�ӽ�0.065,�����
		{
			d=i+1;
			break;                 //d����ֳɼ���
		}
	}
	
	//������Կ
	for(j=0;j<d;j++)
	{
		for(n=0;n<26;n++)                   //��0
			letter[n]=0;
		for(n=0;(n<N/d+1)&&encrypt[j+n*d]!='\0';n++) //ͳ�Ƹ�����ĸ�ĳ��ִ���
		{
			 m=encrypt[j+n*d]-'a';
			 letter[m]+=1;
		}
		keyword[j]=(21+MAX(letter))%26+'a';       //���ڳ��ָ���������ĸ��Ϊe,�൱�ڼ���21
	}
	printf("the key is: %s\n",keyword);               //��ӡ��Կ
	return 0;
}

# Vigenere
