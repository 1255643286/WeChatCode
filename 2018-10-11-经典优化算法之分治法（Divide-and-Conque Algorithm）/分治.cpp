

//���������������壬ʵ���˷ָ�Ĳ���
void mergesort(int a[],int n,int left,int right)
{
    if(left+1<right)
    {
        int mid=(left+right)/2;
        mergesort(a,n,left,mid);
        mergesort(a,n,mid,right);
        merge(a,n,left,mid,right);
    }
}
```
```
//������д�Լ���merge������
//L,R�Ǹ������飡
void merge(int a[],int n,int left,int mid,int right)
{
    int n1=mid-left,n2=right-mid;
    for(int i=0;i<n1;i++)
        L[i]=a[left+i];//����������
    for(int i=0;i<n2;i++)
        R[i]=a[mid+i];//����������
    L[n1]=R[n2]=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++)//�ϲ�
    {
        if(L[i]<=R[j])
            a[k]=L[i++];
        else
            a[k]=R[j++];
    }
}

#include<bits/stdc++>
using namespace std;
const int maxn=500000,INF=0x3f3f3f3f;
int L[maxn],R[maxn];
void merge(int a[],int n,int left,int mid,int right)
{
    int n1=mid-left,n2=right-mid;
    for(int i=0;i<n1;i++)
        L[i]=a[left+i];
    for(int i=0;i<n2;i++)
        R[i]=a[mid+i];
    L[n1]=R[n2]=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++)
    {
        if(L[i]<=R[j])
            a[k]=L[i++];
        else
            a[k]=R[j++];
    }
}
void mergesort(int a[],int n,int left,int right)
{
    if(left+1<right)
    {
        int mid=(left+right)/2;
        mergesort(a,n,left,mid);
        mergesort(a,n,mid,right);
        merge(a,n,left,mid,right);
    }
}
int main()
{
    int a[maxn],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,n,0,n);
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}




int maxsum(int l,int r)
{
    if(l==r)return a[l];
    int m=(l+r)/2;
    int Max=max(maxsum(l,m),maxsum(m+1,r));//���ֽ⣩���1����ȫ�������䣬������ȫ��������

    //���ϲ������2�����������������
    int suml=a[m],t=0;
    for(int i=m;i>=l;i--)
        suml=max(suml,t+=a[i]);
    int sumr=a[m+1];t=0;
    for(int i=m+1;i<=r;i++)
        sumr=max(sumr,t+=a[i]);

    return max(Max,suml+sumr);//ȡ������������ġ�


}






#include <iostream> 
void move(int,char,char,char); 
int main()
{    
     int m;
     cin>>m; 
     move(m,'A','B','C');
} 
/*XYZ�ֱ������������*/

void move(int m,char x,char y,char z)
{    
    if(m==1)    
    {        
        cout<<x<<"->"<<z<<endl"; //���ֻ��һ����Ƭ�ˣ���ô����ֱ�ӽ����X����Z���ɡ�        
        return;    
    }    
    move(m-1,x,z,y); //�Ƚ�m-1����Ƭ��X����Y��    
    cout<<x<<"->"<<z<<endl);//ÿ�εݹ�ʱ���������ǽ�1�Ž�Ƭ����Z��    
    move(m-1,y,x,z); //�ٽ����������m-1����Ƭ��Y����Z
}
