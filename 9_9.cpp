#include <iostream>
using namespace std;

struct Sequence_list
{
	int arr[1000];
	int last;
};
//初始化
void Init_List(Sequence_list *L)
{
	L->last=-1;
	for(int i=0;i<1000;i++) L->arr[i]=0;
}
//输入数据
void put_List(Sequence_list *L)
{
    int len;
    cout<<"请输入表的长度："<<endl;
    cin>>len;
	cout<<"请输入表的数据"<<endl;
    for(int i=0;i<len;i++)  cin>>L->arr[i];
    L->last+=len;
}
//求表长
bool len_List(Sequence_list *L)
{
    if(L->last==-1) return false;
    cout<<"表长为："<<L->last<<endl;
    return true;
}
//按位置查找元素
bool find_List_loc(Sequence_list *L)
{
    int loc;
    cout<<"请输入需要查找的位置："<<endl;
    cin>>loc;
    if(loc-1<0||loc-1>L->last)  return false;
    cout<<"第"<<loc<<"位元素为："<<L->arr[loc-1]<<endl;
    return true;
}
//按数值查找元素
bool find_List_num(Sequence_list *L)
{
    int num,cnt=0;
    cout<<"请输入需要查找的数值："<<endl;
    cin>>num;
    for(int i=0;i<L->last;i++)
    {
        if(L->arr[i]==num)
        {
            cout<<"该元素位于第"<<i+1<<"位"<<endl;
            cnt++;
        }
    }
    cout<<"共找到"<<cnt<<"个元素"<<endl;
    if(cnt==0)  return false;
    else    return true;
}
//插入元素
bool insert_List(Sequence_list *L)
{
    int num,loc;
    cout<<"请输入需要插入的数字和位置，如a b："<<endl;
    cin>>num>>loc;
    if(loc<0||loc-1>L->last)    return false;
    for(int i=L->last;i>=loc-1;i--) L->arr[i+1]=L->arr[i];
    L->last++;
    L->arr[loc-1]=num;
    return true;
}
//按位置删除元素
bool delete_List_member(Sequence_list *L)
{
    int loc;
    cout<<"请输入需要删除的元素的位置："<<endl;
    cin>>loc;
    for(int i=0;i<L->last;i++)
    {
        if(i==loc-1)
        {
            for(int j=i;j<L->last;j++)  L->arr[j]=L->arr[j+1];
            return true;
        }
    }
    return false;
}
//按数值删除元素
bool delete_List_loc(Sequence_list *L)
{
    int num,cnt=0;
    cout<<"请输入需要删除的元素的数值："<<endl;
    cin>>num;
    for(int i=0;i<L->last;i++)
    {
        if(L->arr[i]==num)
        {
            for(int j=i;j<L->last;j++)  L->arr[j]=L->arr[j+1];
            cnt++;
        }
    }
    if(cnt==0)  return false;
    else
    {
        cout<<"共删除"<<cnt<<"个元素"<<endl;
        return true;
    }
}
//打印表
void print_List(Sequence_list *L)
{
    if(L->last==-1) cout<<"表为空！"<<endl;
    else
    {
        for(int i=0;i<L->last;i++)  cout<<L->arr[i]<<' ';
        cout<<endl;
    }
}
int main()
{
    Sequence_list List;
    while(1)
    {
        cout<<endl;
        cout<<"请输入你的选择"<<endl
            <<"1.初始化列表"<<endl
            <<"2.列表读入数据"<<endl
            <<"3.输出列表长度"<<endl
            <<"4.按位置查找元素"<<endl
            <<"5.按数值查找元素"<<endl
            <<"6.插入元素"<<endl
            <<"7.按位置删除元素"<<endl
            <<"8.按数值删除元素"<<endl
            <<"9.打印表"<<endl
            <<"0.退出系统"<<endl;
        int choice,end=0;
        cout<<endl<<"你的选择是：";
        cin>>choice;
        switch(choice)
        {
            case 1:
                Init_List(&List);
                cout << "操作成功！" << endl;
                break;
            case 2:
                put_List(&List);
                cout << "操作成功！" << endl;
                break;
            case 3:
                if (len_List(&List)) cout << "操作成功！" << endl;
                else cout << "操作违法！请重新选择(列表为空或元素不存在)" << endl;
                break;
            case 4:
                if (find_List_loc(&List)) cout << "操作成功！" << endl;
                else cout << "操作违法！请重新选择(列表为空或元素不存在或位置越界)" << endl;
                break;
            case 5:
                if (find_List_num(&List)) cout << "操作成功！" << endl;
                else cout << "操作违法！请重新选择(列表为空或元素不存在)" << endl;
                break;
            case 6:
                if (insert_List(&List)) cout << "操作成功！" << endl;
                else cout << "操作违法！请重新选择(列表为空或元素不存在)" << endl;
                break;
            case 7:
                if (delete_List_loc(&List)) cout << "操作成功！" << endl;
                else cout << "操作违法！请重新选择(列表为空或元素不存在)" << endl;
                break;
            case 8:
                if (delete_List_member(&List)) cout << "操作成功！" << endl;
                else cout << "操作违法！请重新选择(列表为空或元素不存在)" << endl;
                break;
            case 9:
                print_List(&List);	cout << "操作成功！" << endl;
                break;
            case 0:
                end=1;
                break;
            default:
                cout << "输入违法!" << endl;
                break;
        }
        if(end==1)  break;
    }
    cout<<"退出系统成功！"<<endl;
	return 0;
}