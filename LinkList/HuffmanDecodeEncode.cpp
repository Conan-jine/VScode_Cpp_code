#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
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
	string Code;
};

HuffmanNode HT[50*2-1];
HuffmancharCode HCD[50];
int LeafNum;
int NodeNum;
string AllenCodestr;
string AlldeCodestr="";
string realStr;
int AllWeight[50]={0};

void Readfile(string name, string &str);
void Writefile(string name, string &str);
void Statistics();
void CreateHuffmanTree();
void SelectMin(int &min1, int &min2);
void CreateHuffmanCode();
void ReverseStr(char *str);
void EnCodeStr();
void DeCodeHuffmanCode();
void EnCode01Str(string name);
void DeCode01Str(string name);

int main()
{
	
	// cout<<AllenCodestr<<endl;
	// cout<<"Results of statistics:"<<endl;
	// Statistics();
	// cout<<"Results of each character:"<<endl;
	// CreateHuffmanTree();
	// CreateHuffmanCode();
	// cout<<"Results of encode:"<<endl;
	// EnCodeStr();
	// DeCodeHuffmanCode();
	int num;
	while(1)
	{
		// cout<<"1. 打开 data.txt	将内容转化为	01字符串	存储于 01.txt "<<endl;
		// cout<<"2. 打开 01.txt	将内容转化为	原文		存储于 da.txt"<<endl;
		// cout<<"3. 打开 01.txt	将01八位压缩				存储于	zip.txt"<<endl;
		// cout<<"4. 打开 zip.txt	将内容解压为	01字符串	存储于	01.txt"<<endl;
		cin>>num;
		if(num==1)
		{
			Readfile("data.txt",AllenCodestr);
			Statistics();
			CreateHuffmanTree();
			CreateHuffmanCode();
			EnCodeStr();
			Writefile("01.txt",AlldeCodestr);
		}
		else if(num==2)
		{
			DeCodeHuffmanCode();
		}
		else if(num==3)
		{
			EnCode01Str("da.txt");
		}
		else if(num==4)
		{
			DeCode01Str("zip.txt");
		}
	}
	return 0;
}

void Readfile(string name, string &str)
{
	str.clear();
	string linestr;
	fstream essay;
	essay.open(name,ios::in);
	if(essay.is_open())
		cout<<"Openfile successful."<<endl;
	else
		cout<<"Openfile failed."<<endl;
	
	while(getline(essay,linestr))
	{
		linestr+='\n';
		// cout<<linestr<<endl;
		str+=linestr;
	}
}

void Writefile(string name, string &str)
{
	fstream essay;
	essay.open(name,ios::out|ios::binary);
	if(essay.is_open())
		cout<<"Openfile successful."<<endl;
	else
		cout<<"Openfile failed."<<endl;
	
	essay.write(str.c_str(),str.size());
	essay.close();
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
	}
	int i=0,j=0;
	for(;i<=50;i++)
	{
		if(AllWeight[i]!=0)
		{
			HT[j].weight = AllWeight[i];
			if(i<26)	HT[j].ch='a'+i;
			else if(i>37)	HT[j].ch='0'+i-38;
			else if(i==26)	HT[j].ch=",";
			else if(i==27)	HT[j].ch=".";
			else if(i==28)	HT[j].ch="-";
			else if(i==29)	HT[j].ch="?";
			else if(i==30)	HT[j].ch="!";
			else if(i==31)	HT[j].ch="'";
			else if(i==32)	HT[j].ch="\"";
			else if(i==33)	HT[j].ch="%";
			else if(i==34)	HT[j].ch=":";
			else if(i==35)	HT[j].ch=";";
			else if(i==36)	HT[j].ch=" ";
			else if(i==37)	HT[j].ch="\n";
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
			if(HT[HT[j].parent].lchild==j)	HCD[i].Code+='0'+0;
			else	HCD[i].Code+='0'+1;
			j=HT[j].parent;
		}
		reverse(HCD[i].Code.begin(),HCD[i].Code.end());
	}
	for(int i=0;i<LeafNum;i++)	cout<<HT[i].ch[0]<<':'<<HCD[i].Code<<endl;
	// printf("%c:%s\n",HT[i].ch,HCD[i].Code);
		
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
	int len=AllenCodestr.size();
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<LeafNum;j++)
		{
			if(AllenCodestr[i]==HCD[j].ch[0])
			{
				// printf("%s",HCD[j].Code);
				cout<<HCD[j].Code;
				AlldeCodestr+=HCD[j].Code;
			}
		}
	}
	printf("\n");
}

void DeCodeHuffmanCode()
{
	// cout<<"AlldeCode"<<endl<<AlldeCodestr<<endl;
	int k=NodeNum-1;
	int len=0,i=0;
	while(AlldeCodestr[i])
	{
		if(AlldeCodestr[i]=='0')	k=HT[k].lchild;
		else if(AlldeCodestr[i]=='1')	k=HT[k].rchild;

		if(HT[k].lchild==-1 && HT[k].rchild==-1)
		{
			realStr+=HT[k].ch;
			k=NodeNum-1;
		}
		i++;
	}
	if(k==NodeNum-1)	cout<<realStr<<endl;
	Writefile("da.txt",realStr);
}


void EnCode01Str(string name)
{
    char *fileName = (char *)name.data();
    FILE *fileIn = fopen(fileName,"r");
    FILE *fileOut = fopen("zip.txt","wb");
    unsigned char c;
    unsigned char value = 0;
    int index = 0;
    fseek(fileIn,0L,SEEK_SET);
    c = fgetc(fileIn);
    while(!feof(fileIn))
    {
        string str;
		if(isalpha(c))
		{
			c=tolower(c);
			str=HCD[int(c-'a')].Code;
		}
		else if(isdigit(c))	str=HCD[38+int(c)-48].Code;
		else if(int(c)==44)	str=HCD[26].Code;
		else if(int(c)==46)	str=HCD[27].Code;
		else if(int(c)==45)	str=HCD[28].Code;
		else if(int(c)==63)	str=HCD[29].Code;
		else if(int(c)==33)	str=HCD[30].Code;
		else if(int(c)==39)	str=HCD[31].Code;
		else if(int(c)==34)	str=HCD[32].Code;
		else if(int(c)==37)	str=HCD[33].Code;
		else if(int(c)==58)	str=HCD[34].Code;
		else if(int(c)==59)	str=HCD[35].Code;
		else if(int(c)==32)	str=HCD[36].Code;
		else if(int(c)==10)	str=HCD[37].Code;
		cout<<c<<' '<<str<<endl;
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == '0')
            {
                ((value)&=(~(1<<((index)^7))));
            }
            else if(str[i] == '1')
            {
                ((value)|=(1<<((index)^7)));
            }
            index++;
            if(index >= 8)
            {
                index = 0;
                fwrite(&value,sizeof(unsigned char),1,fileOut);
            }
        }
        c = fgetc(fileIn);
    }
    fclose(fileIn);
    fclose(fileOut);
}

void DeCode01Str(string name)
{
	AlldeCodestr.clear();
	realStr.clear();
    char *fileName = (char *)name.data();
    FILE *fileIn = fopen(fileName,"rb");
    unsigned char value = 0;
    int index = 0;
    fseek(fileIn,0L,SEEK_SET);
    int k = NodeNum-1;
    fread(&value,sizeof(unsigned char),1,fileIn);
    while(!feof(fileIn))
    {
        if(HT[k].lchild==-1 && HT[k].rchild==-1)
        {
            realStr+=HT[k].ch;
            k=NodeNum-1;
        }
        if(((value)&(1<<((index)^7))) == 0)
        {
            k=HT[k].lchild;
			AlldeCodestr+='0';
        }
        else if(((value)&(1<<((index)^7))) != 0)
        {
            k=HT[k].rchild;
			AlldeCodestr+='1';
        }
        index++;
        if(index >= 8)
        {
            index = 0;
            fread(&value,sizeof(unsigned char),1,fileIn);
        }
    }
    fclose(fileIn);
	Writefile("ad.txt",realStr);
}