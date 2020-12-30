#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define MAX 9999
#define NUM 50
using namespace std;

struct HuffmanNode
{
	string ch;
	int weight;
	int parent;
	int lchild, rchild;
};

struct HuffmancharCode
{
	string ch;
	char Code[NUM];
};

HuffmanNode HT[50*2-1];
HuffmancharCode HCD[50];
int LeafNum;
int NodeNum;
string AllenCodestr;
string AlldeCodestr;
string realStr;
int AllWeight[50]={0};

void Statistics();
void CreateHuffmanTree();
void SelectMin(int &min1, int &min2);
void CreateHuffmanCode();
void ReverseStr(char *str);
void EnCodeStr();
void DeCodeHuffmanCode();

int main()
{
	string linestr;
	fstream essay;
	essay.open("data1.txt", ios::in);
	if(essay.is_open())
		cout<<"Openfilesuccessful."<<endl;
	while(getline(essay,linestr))
	{
		linestr+='\n';
		// cout<<linestr<<endl;
		AllenCodestr+=linestr;
	}
	cout<<AllenCodestr<<endl;
	cout<<"Results of statistics:"<<endl;
	Statistics();
	cout<<"Results of each character:"<<endl;
	CreateHuffmanTree();
	CreateHuffmanCode();
	cout<<"Results of encode:"<<endl;
	EnCodeStr();
	// scanf("%s", EnterCode);
	// getchar();
	// DeCodeHuffmanCode();
	return 0;
}

void Statistics()
{
	int len = AllenCodestr.size();

	for (int j=0;j<len;j++)
	{
		if(isalpha(AllenCodestr[j]))
		{
			AllenCodestr[j] = tolower(AllenCodestr[j]);
			AllWeight[AllenCodestr[j] - 'a']++;
		}
		else if(int(AllenCodestr[j])==44)	AllWeight[26]++;	// ','
		else if(int(AllenCodestr[j])==46)	AllWeight[27]++;	// '.'
		else if(int(AllenCodestr[j])==45)	AllWeight[28]++;	// '-'
		else if(int(AllenCodestr[j])==63)	AllWeight[29]++;	// '?'
		else if(int(AllenCodestr[j])==33)	AllWeight[30]++;	// '!'
		else if(int(AllenCodestr[j])==39)	AllWeight[31]++;	// '''
		else if(int(AllenCodestr[j])==34)	AllWeight[32]++;	// ''''
		else if(int(AllenCodestr[j])==37)	AllWeight[33]++;	// '%'
		else if(int(AllenCodestr[j])==58)	AllWeight[34]++;	// ':'
		else if(int(AllenCodestr[j])==59)	AllWeight[35]++;	// ';'
		else if(int(AllenCodestr[j])==32)	AllWeight[36]++;	// ' '
		else if(int(AllenCodestr[j])==10)	AllWeight[37]++;	// '\n'
		else if(isdigit(AllenCodestr[j]))	AllWeight[38+int(AllenCodestr[j])-48]++;
		else	exit(-1);
	}
	int i=0,j=0;
	for(;i<=50;i++)
	{
		if(AllWeight[i]!=0)
		{
			HT[j].weight = AllWeight[i];
			if(isalpha(AllenCodestr[i]))	HT[j].ch[0]='a'+i;
			else if(isdigit(AllenCodestr[i]))	HT[j].ch[0]='0'+i-38;
			else if(i==26)	HT[j].ch=',';
			else if(i==27)	HT[j].ch='.';
			else if(i==28)	HT[j].ch='-';
			else if(i==29)	HT[j].ch='?';
			else if(i==30)	HT[j].ch='!';
			else if(i==31)	HT[j].ch='\'';
			else if(i==32)	HT[j].ch='\"';
			else if(i==33)	HT[j].ch='%';
			else if(i==34)	HT[j].ch=':';
			else if(i==35)	HT[j].ch=';';
			else if(i==36)	HT[j].ch=' ';
			else if(i==37)	HT[j].ch='\\';
			else
			{
				j++;
				continue;
			}
			j++;
		}
	}
	int n = 0;
	for(int i=0;i<=50;i++)
	{
		if(AllWeight[i]!=0)
		{
			n++;
			if(i<26)	cout<<char(97+i);
			else if(i>37)	cout<<char(48+i-38);
			else if(i==26)	cout<<',';
			else if(i==27)	cout<<'.';
			else if(i==28)	cout<<'-';
			else if(i==29)	cout<<'?';
			else if(i==30)	cout<<'!';
			else if(i==31)	cout<<'\'';
			else if(i==32)	cout<<'\'';
			else if(i==33)	cout<<'%';
			else if(i==34)	cout<<':';
			else if(i==35)	cout<<';';
			else if(i==36)	cout<<' ';
			else if(i==37)	cout<<'\\';
			else continue;
			// printf(":%d\n", AllWeight[i]);
			cout<<':'<<AllWeight[i]<<endl;
		}
	}
	LeafNum=n;
	NodeNum=2*LeafNum-1;
}

void CreateHuffmanTree()
{
	int i;
	for(i=0;i<LeafNum;i++)
	{
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
		HT[i].weight=HT[i].weight;
	}
	for(;i<NodeNum;i++)
	{
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
		HT[i].weight=MAX;
	}
	int min1,min2;
	for(i=LeafNum;i<NodeNum;i++)
	{
		SelectMin(min1,min2);
		HT[min1].parent=i;
		HT[min2].parent=i;
		HT[i].lchild=min1;
		HT[i].rchild=min2;
		HT[i].weight=HT[min1].weight+HT[min2].weight;
	}
}

void SelectMin(int &min1, int &min2)
{
	int i=0;
	int temp;
	int wetmin1,wetmin2;
	while(HT[i].parent!=-1)	i++;
	wetmin1=HT[i].weight;
	min1=i;
	i++;
	while(HT[i].parent!=-1)	i++;	
	wetmin2=HT[i].weight;
	min2=i;
	i++;
	if(wetmin1>wetmin2)
	{
		temp=wetmin2;
		wetmin2=wetmin1;
		wetmin1=temp;
		temp=min2;
		min2=min1;
		min1=temp;
	}
	for(;i<NodeNum;i++)
	{
		if(HT[i].weight<wetmin1 && HT[i].parent==-1)
		{
			wetmin2=wetmin1;
			wetmin1=HT[i].weight;
			min2=min1;
			min1=i;
		}
		else if(HT[i].weight<wetmin2 && HT[i].parent==-1)
		{
			wetmin2=HT[i].weight;
			min2=i;
		}
	}
}

void CreateHuffmanCode()
{
	int i,j,len;
	for(i=0;i<LeafNum;i++)
	{
		len=0;
		j=i;
		HCD[i].ch=HT[j].ch;
		while(HT[j].parent!=-1)
		{
			if(HT[HT[j].parent].lchild==j)	HCD[i].Code[len++] = '0' + 0;
			else	HCD[i].Code[len++] = '0' + 1;
			j=HT[j].parent;
		}
		HCD[i].Code[len] ='\0';
		ReverseStr(HCD[i].Code);
	}
	for(int i=0;i<LeafNum;i++)	cout<<HT[i].ch[0]<<':'<<HCD[i].Code<<endl;	// printf("%c:%s\n",HT[i].ch,HCD[i].Code);
		
}

void ReverseStr(char *str)
{
	int i, j;
	char c;
	for(i=0,j=strlen(str)-1;i<j;i++,j--)
	{
		c=str[i];
		str[i]=str[j];
		str[j]=c;
	}
}

void EnCodeStr()
{
	cout<<"Yes"<<endl;
	int len=AllenCodestr.size();
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<LeafNum;j++)
		{
			if(AllenCodestr[i]==HCD[j].ch[0])	printf("%s",HCD[j].Code);
		}
	}
	printf("\n");
}

void DeCodeHuffmanCode()
{
	int k=NodeNum-1;
	int len=0,i=0;
	while(AlldeCodestr[i])
	{
		if(AlldeCodestr[i]=='0'+0)	k=HT[k].lchild;
		else if(AlldeCodestr[i]=='0'+1)	k=HT[k].rchild;			
		else	exit(-1);

		if(HT[k].lchild==-1 && HT[k].rchild==-1)
		{
			realStr[len++]=HT[k].ch[0];
			k=NodeNum-1;
		}
		i++;
	}
	realStr[len]='\0';
	if(k==NodeNum-1)
	{
		printf("\n***������***\n%s\n\n", realStr);
		exit(0);
	}
	exit(-1);
}
