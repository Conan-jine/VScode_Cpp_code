#include <iostream>
using namespace std;

struct Sequence_list
{
	int arr[1000];
	int last;
};
//��ʼ��
void Init_List(Sequence_list *L)
{
	L->last=-1;
	for(int i=0;i<1000;i++) L->arr[i]=0;
}
//��������
void put_List(Sequence_list *L)
{
    int len;
    cout<<"�������ĳ��ȣ�"<<endl;
    cin>>len;
	cout<<"������������"<<endl;
    for(int i=0;i<len;i++)  cin>>L->arr[i];
    L->last+=len;
}
//���
bool len_List(Sequence_list *L)
{
    if(L->last==-1) return false;
    cout<<"��Ϊ��"<<L->last<<endl;
    return true;
}
//��λ�ò���Ԫ��
bool find_List_loc(Sequence_list *L)
{
    int loc;
    cout<<"��������Ҫ���ҵ�λ�ã�"<<endl;
    cin>>loc;
    if(loc-1<0||loc-1>L->last)  return false;
    cout<<"��"<<loc<<"λԪ��Ϊ��"<<L->arr[loc-1]<<endl;
    return true;
}
//����ֵ����Ԫ��
bool find_List_num(Sequence_list *L)
{
    int num,cnt=0;
    cout<<"��������Ҫ���ҵ���ֵ��"<<endl;
    cin>>num;
    for(int i=0;i<L->last;i++)
    {
        if(L->arr[i]==num)
        {
            cout<<"��Ԫ��λ�ڵ�"<<i+1<<"λ"<<endl;
            cnt++;
        }
    }
    cout<<"���ҵ�"<<cnt<<"��Ԫ��"<<endl;
    if(cnt==0)  return false;
    else    return true;
}
//����Ԫ��
bool insert_List(Sequence_list *L)
{
    int num,loc;
    cout<<"��������Ҫ��������ֺ�λ�ã���a b��"<<endl;
    cin>>num>>loc;
    if(loc<0||loc-1>L->last)    return false;
    for(int i=L->last;i>=loc-1;i--) L->arr[i+1]=L->arr[i];
    L->last++;
    L->arr[loc-1]=num;
    return true;
}
//��λ��ɾ��Ԫ��
bool delete_List_member(Sequence_list *L)
{
    int loc;
    cout<<"��������Ҫɾ����Ԫ�ص�λ�ã�"<<endl;
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
//����ֵɾ��Ԫ��
bool delete_List_loc(Sequence_list *L)
{
    int num,cnt=0;
    cout<<"��������Ҫɾ����Ԫ�ص���ֵ��"<<endl;
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
        cout<<"��ɾ��"<<cnt<<"��Ԫ��"<<endl;
        return true;
    }
}
//��ӡ��
void print_List(Sequence_list *L)
{
    if(L->last==-1) cout<<"��Ϊ�գ�"<<endl;
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
        cout<<"���������ѡ��"<<endl
            <<"1.��ʼ���б�"<<endl
            <<"2.�б��������"<<endl
            <<"3.����б���"<<endl
            <<"4.��λ�ò���Ԫ��"<<endl
            <<"5.����ֵ����Ԫ��"<<endl
            <<"6.����Ԫ��"<<endl
            <<"7.��λ��ɾ��Ԫ��"<<endl
            <<"8.����ֵɾ��Ԫ��"<<endl
            <<"9.��ӡ��"<<endl
            <<"0.�˳�ϵͳ"<<endl;
        int choice,end=0;
        cout<<endl<<"���ѡ���ǣ�";
        cin>>choice;
        switch(choice)
        {
            case 1:
                Init_List(&List);
                cout << "�����ɹ���" << endl;
                break;
            case 2:
                put_List(&List);
                cout << "�����ɹ���" << endl;
                break;
            case 3:
                if (len_List(&List)) cout << "�����ɹ���" << endl;
                else cout << "����Υ����������ѡ��(�б�Ϊ�ջ�Ԫ�ز�����)" << endl;
                break;
            case 4:
                if (find_List_loc(&List)) cout << "�����ɹ���" << endl;
                else cout << "����Υ����������ѡ��(�б�Ϊ�ջ�Ԫ�ز����ڻ�λ��Խ��)" << endl;
                break;
            case 5:
                if (find_List_num(&List)) cout << "�����ɹ���" << endl;
                else cout << "����Υ����������ѡ��(�б�Ϊ�ջ�Ԫ�ز�����)" << endl;
                break;
            case 6:
                if (insert_List(&List)) cout << "�����ɹ���" << endl;
                else cout << "����Υ����������ѡ��(�б�Ϊ�ջ�Ԫ�ز�����)" << endl;
                break;
            case 7:
                if (delete_List_loc(&List)) cout << "�����ɹ���" << endl;
                else cout << "����Υ����������ѡ��(�б�Ϊ�ջ�Ԫ�ز�����)" << endl;
                break;
            case 8:
                if (delete_List_member(&List)) cout << "�����ɹ���" << endl;
                else cout << "����Υ����������ѡ��(�б�Ϊ�ջ�Ԫ�ز�����)" << endl;
                break;
            case 9:
                print_List(&List);	cout << "�����ɹ���" << endl;
                break;
            case 0:
                end=1;
                break;
            default:
                cout << "����Υ��!" << endl;
                break;
        }
        if(end==1)  break;
    }
    cout<<"�˳�ϵͳ�ɹ���"<<endl;
	return 0;
}