#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 35;
typedef struct node
{
    int val;
    node *lchild = NULL, *rchild = NULL;
}node;
int pre[MAX_N];
int zho[MAX_N];
int N;
node* build(int px, int py, int zx, int zy)
{
    if(px > py) return NULL;
    int i;
    for(i = zx; i <= zy; i++)
        if(zho[i] == pre[px]) break;
    node *x = new node;
    x->val = pre[px];
    int len = i - zx;
    x->lchild = build(px+1, px+len, zx, i - 1);
    x->rchild = build(px+len+1, py, i+1, zy);
    return x;
}
node* fz(node *x)
{
    if(x == NULL) return NULL;
    node *now = new node;
    now->val = x->val;
    now->lchild = fz(x->rchild);
    now->rchild = fz(x->lchild);
    return now;
}
void bfs(node *x)
{
    int num = 1;
    queue<node*> q;
    q.push(x);
    while(!q.empty())
    {
        node *now = q.front();
        q.pop();
        cout<<now->val;
        num++;
        if(num <= N)
            cout<<" ";
        if(now->lchild != NULL)
            q.push(now->lchild);
        if(now->rchild != NULL)
            q.push(now->rchild);
    }
}
int main()
{
    
    cin>>N;
    for(int i = 1; i <= N; i++) cin>>zho[i];
    for(int i = 1; i <= N; i++) cin>>pre[i];
    node *x = build(1, N, 1, N);
    node *y = fz(x);
    bfs(y);
    return 0;
}