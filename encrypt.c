#include <string.h> 
#include <stdio.h> 

int main()
{
	int l,i,k;       //l����Կ�ĳ���,i,k�Ǽ����õ�
	char ch,key[50];	//ch���ļ��ж�ȡ��ÿ���ַ��ı���,key����Կ�ַ���
	printf("please input key:\n");
	scanf("%s",key);
	for(i=0;key[i]!='\0';i++)
		l=i+1;   //������Կ����
	FILE *fin=freopen("mingwen.txt","r",stdin); //�����ȡ���ļ�ָ��,����
   	FILE *fout=freopen("miwen.txt","w",stdout); //����д����ļ�ָ��,����
	
	while (!feof(fin)&&(ch!=-1))   
	{
		ch=fgetc(fin);     //ÿ�δ��ļ����һ���ַ�
		if(ch!=-1)		//�ж��Ƿ񵽴��ļ�β
		{
			if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))	//������ַ�����ĸ�Ļ�
			{
			    k=k+1;                              //��Կÿ������
			    if(ch>='a'&&ch<='z')		//��Сд�ֿ�����
					ch=(ch-'a'+key[(k-1)%l]-'a')%26+'a';//����ַ���a��z֮������м�������
			    else if(ch>='A'&&ch<='Z')
			    		ch=(ch-'A'+key[(k-1)%l]-'A')%26+'A';//����ַ���A��Z֮������м�������
			}
			fputc(ch,fout);	    //���ܺ���ַ�д���ļ�
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

# Vigenere
