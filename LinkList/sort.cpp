#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;
#define MAX 100000

int Arr[MAX]={0};
int copyarr[MAX];
int allot[10][MAX];
int times=0;
string names[8]=
{
    "bubble_sort",    "selection_sort", "insertion_sort", "shell_sort",
    "merge_sort",     "quick_sort",     "heap_sort",      "RadixSort"
};

void bubble_sort(int *arr, int l, int r, int len);
void insertion_sort(int *arr, int l, int r,int len);
void selection_sort(int *arr, int l, int r,int len);
void shell_sort(int *arr, int l, int r,int len);
void merge_sort(int *arr, int l, int r,int len);
void RadixSort(int *arr, int l, int r,int len);
void heap_sort(int *arr, int l, int r, int len);
void quick_sort(int *arr, int l, int r, int len);
void countTime(void (*fun)(int *, int, int, int ) ,int *arr, int l, int r, int len);
void Writefile(int *arr, int len);

int main()
{
    srand(time(NULL));
    void (*fun_arr[8])(int *, int, int, int)=
    {   
        bubble_sort,    selection_sort, insertion_sort, shell_sort,
        merge_sort,     quick_sort,     heap_sort,      RadixSort
    };
    for(int i=0;i<MAX;i++)  Arr[i]=rand();
    Writefile(Arr,MAX);
    for(int i=0;i<8;i++)
        countTime(fun_arr[times-1],copyarr,0,MAX-1,MAX);
    return 0;
}

void countTime(void (*fun)(int *, int, int, int ) ,int *arr, int l, int r, int len)
{
    double start,end;
    for(int i=0;i<MAX;i++)  arr[i]=Arr[i];
    start=clock();
    (*fun)(arr,l,r,len);
    end=clock();
    cout<<names[times-1]<<":"<<end-start<<"ms"<<endl;
    Writefile(copyarr,MAX);
}

void Writefile(int *arr, int len)
{
    string name=to_string(times)+".txt";
    fstream file;
    file.open(name,ios::out);
    if(times!=0)    file<<names[times-1];
    for(int i=0;i<len;i++)
    {
        if(i%20==0)  file<<"\n";
        file<<arr[i]<<' ';
    }
    file.close();
    times++;
}


// 冒泡排序
void bubble_sort(int *arr, int l, int r,int len)
{
    for(int i = 0; i < len - 1; i++)
        for(int j = 0; j < len - 1 - i; j++)
            if(copyarr[j] > arr[j + 1])
                swap(copyarr[j], arr[j + 1]);
}

// 选择排序
void selection_sort(int *arr, int l, int r,int len)
{
    for(int i = 0 ; i < len - 1 ; i++)
    {
        int min = i;
        for(int j = i + 1; j < len; j++)     
            if(copyarr[j] < arr[min])    
                min = j;   
        swap(copyarr[min],arr[i]);   
    }
}

// 插入排序
void insertion_sort(int *arr, int l, int r,int len)
{
    for(int i=1;i<len;i++)
    {
        int key=arr[i];
        int j=i-1;
        while((j>=0) && (key<arr[j]))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// 希尔排序
void shell_sort(int *arr, int l, int r,int len)
{
    int h = 1;
    while(h < len / 3)  h = 3 * h + 1;
    while(h >= 1)
    {
        for(int i = h; i < len; i++)
        {
            for(int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
            {
                swap(copyarr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

// 归并排序
void merge_sort_recursive(int arr[], int reg[], int start, int end)
{
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(copyarr, reg, start1, end1);
    merge_sort_recursive(copyarr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

void merge_sort(int *arr, int l, int r,int len)
{
    int reg[len];
    merge_sort_recursive(copyarr, reg, 0, len - 1);
}

// 快速排序
void quick_sort(int *arr, int l, int r,int len)
{
    if (l < r)
    {
        int i = l, j = r, x = arr[l];
        while (i < j)
        {
            while(i < j && arr[j] >= x) 
                j--;  
            if(i < j) 
                arr[i++] = arr[j];
            
            while(i < j && arr[i] < x)
                i++;  
            if(i < j) 
                arr[j--] = arr[i];
        }
        arr[i] = x;
        quick_sort(copyarr, l, i - 1,len);
        quick_sort(copyarr, i + 1, r,len);
    }
}

// 堆排序
void max_heapify(int *arr, int start, int end)
{
    
    int dad = start;
    int son = dad * 2 + 1;
    while(son <= end)
    {
        if(son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if(arr[dad] > arr[son])
            return;
        else
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
    
}

void heap_sort(int *arr, int l, int r,int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

// 基数排序
int GetDigit(int M, int i)
{
	while(i > 1)
	{
		M /= 10;
		i--;
	}
	return M % 10;
}

void RadixSort(int *arr, int l, int r,int len)
{
	int i, j, k, m, digit;
	memset(allot, 0, sizeof(allot));
	for(i = 1; i <= 10; i++)
	{
		int flag = 0;
		for(j = 0; j < len; j++)	
		{			
			digit = GetDigit(copyarr[j], i);
			k = 0;
			while(allot[digit][k])
				k++;
			allot[digit][k] = arr[j];
			if(digit)
				flag = 1;
		}
		if(!flag)
			break;
		m = 0; 
		for(j = 0; j < 10; j++)	
		{	
			k = 0;
			while(allot[j][k] > 0)
			{
				arr[m++] = allot[j][k];
				k++;
			}
		}
		memset(allot, 0, sizeof(allot));
	}
}