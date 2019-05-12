#include <iostream>

using namespace std;

void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*���ֱ�ĵ�һ����¼��Ϊ����*/

    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }

        a[first] = a[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/

        while(first < last && a[first] <= key)
        {
            ++first;
        }

        a[last] = a[first];
/*���ȵ�һ������Ƶ��߶�*/
    }
    a[first] = key;/*�����¼��λ*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}
int main()
{
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};

    Qsort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*����ԭ�ĵ���������Ҫ��1�����ڴ�Խ��*/

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}








2.3 code time

#include <iostream>
#include <cmath>
using namespace std;

int sign(int x)
{
    return x > 0 ? 1 : -1;
}

int divideConquer(int x, int y, int n)
{
    int s = sign(x) * sign(y);      // ������
    x = abs(x);
    y = abs(y);
    if(x == 0 || y == 0)
         return 0;
    else if(n == 1)
        return s * x * y;
    else
    {
        int A = (int) x / pow(10, (int)(n / 2));
        int B = x - A * pow(10, n / 2);
        int C = (int) y / pow(10, (int)(n / 2));
        int D = y - C * pow(10, n / 2);
        int AC = divideConquer(A, C, n / 2);
        int BD = divideConquer(B, D, n / 2);
        int ABDC = divideConquer((A - B), (D - C), n / 2) + AC + BD;
        return s * (AC * pow(10 , n) + ABDC * pow(10, (int)(n / 2)) + BD);
    }
}

int main()
{
    int a = 1234, b = -9876;
    int result = divideConquer(a,b,4);
    cout<<a<<" * " <<b<<" = "<<result;
}
//1�������sign������ʵ��
//2����Ϊ��nΪ1ʱ�ļ��㿼���������ԣ�����x��yӦ����abs���㣬���������йط��ŵĶ�����ȥ��Ҳ�ǿ��Եġ�
//3���������ֻ�Ǳ����˷����㷨��˼�룬���������Ĵ������ǲ��ܼ��㣨���ǵ������



03

Strassen�����㷨

3.1 ��������

����˷����ּ����ʱ�����㡣

��C = A ? BΪ��������A��B���� n x n �ľ��󡣸��ݾ���˷��Ķ��壬����������£�

//����˷���3��forѭ���㶨
void Mul(int** matrixA, int** matrixB, int** matrixC)
{
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            matrixC[i][j] = 0;
            for(int k = 0; k < 2; ++k)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}





3.3 code time

��������

#include <bits/stdc++.h>
using namespace std;

//����������ط�����
void Mul(int** MatrixA, int** MatrixB, int** MatrixResult,int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            MatrixResult[i][j] = 0;
            for (int k = 0; k < length; k++)
            {
                MatrixResult[i][j] = MatrixResult[i][j] + MatrixA[i][k] * MatrixB[k][j];
            }
        }
    }
}

//�����������
void Sub(int** MatrixA, int** MatrixB, int** MatrixResult,int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            MatrixResult[i][j] = MatrixA[i][j] - MatrixB[i][j];
        }
    }
}

//������Ӻ���
void Add(int** MatrixA, int** MatrixB, int** MatrixResult, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            MatrixResult[i][j] = MatrixA[i][j] + MatrixB[i][j];
        }
    }
}

//Strasssen��
void Strassen(int** matrixA, int** matrixB, int** matrixResult, int length)
{
    int halfLength = length / 2;
    int newlength = length / 2;

    //�������ά�ȵ���2����һ�㷨���
    if (length == 2)
    {
        Mul(matrixA, matrixB, matrixResult, length);
    }
    else
    {

        int** a11 = new int*[newlength];
        int** a12 = new int*[newlength];
        int** a21 = new int*[newlength];
        int** a22 = new int*[newlength];

        int** b11 = new int*[newlength];
        int** b12 = new int*[newlength];
        int** b21 = new int*[newlength];
        int** b22 = new int*[newlength];

        int** s1 = new int*[newlength];
        int** s2 = new int*[newlength];
        int** s3 = new int*[newlength];
        int** s4 = new int*[newlength];
        int** s5 = new int*[newlength];
        int** s6 = new int*[newlength];
        int** s7 = new int*[newlength];

        int** matrixResult11 = new int*[newlength];
        int** matrixResult12 = new int*[newlength];
        int** matrixResult21 = new int*[newlength];
        int** matrixResult22 = new int*[newlength];

        int** temp = new int*[newlength];
        int** temp1 = new int*[newlength];
        int newsize = newlength;

        //����ָ�
        for (int i = 0; i < newlength; i++)
        {
            a11[i] = new int[newsize];
            a12[i] = new int[newsize];
            a21[i] = new int[newsize];
            a22[i] = new int[newsize];

            b11[i] = new int[newsize];
            b12[i] = new int[newsize];
            b21[i] = new int[newsize];
            b22[i] = new int[newsize];

            s1[i] = new int[newsize];
            s2[i] = new int[newsize];
            s3[i] = new int[newsize];
            s4[i] = new int[newsize];
            s5[i] = new int[newsize];
            s6[i] = new int[newsize];
            s7[i] = new int[newsize];

            matrixResult11[i] = new int[newsize];
            matrixResult12[i] = new int[newsize];
            matrixResult21[i] = new int[newsize];
            matrixResult22[i] = new int[newsize];

            temp[i] = new int[newsize];
            temp1[i] = new int[newsize];
        }
        //����ָ����a,b
        for (int i = 0; i < length / 2; i++)
        {
            for (int j = 0; j < length / 2; j++)
            {
                a11[i][j] = matrixA[i][j];
                a12[i][j] = matrixA[i][j + length / 2];
                a21[i][j] = matrixA[i + length / 2][j];
                a22[i][j] = matrixA[i + length / 2][j + length / 2];
                b11[i][j] = matrixB[i][j];
                b12[i][j] = matrixB[i][j + length / 2];
                b21[i][j] = matrixB[i + length / 2][j];
                b22[i][j] = matrixB[i + length / 2][j + length / 2];
            }
        }

        //����s1
        Add(a11, a22, temp, halfLength);
        Add(b11, b22, temp1, halfLength);
        Strassen(temp, temp1, s1, halfLength);

        //����s2
        Add(a21, a22, temp, halfLength);
        Strassen(temp, b11, s2, halfLength);

        //����s3
        Sub(b12, b22, temp1, halfLength);
        Strassen(a11, temp1, s3, halfLength);

        //����s4
        Sub(b21, b11, temp1, halfLength);
        Strassen(a22, temp1, s4, halfLength);

        //����s5
        Add(a11, a12, temp, halfLength);
        Strassen(temp, b22, s5, halfLength);

        //����s6
        Sub(a21, a11, temp, halfLength);
        Add(b11, b12, temp1, halfLength);
        Strassen(temp, temp1, s6, halfLength);

        //����s7
        Sub(a12, a22, temp, halfLength);
        Add(b21, b22, temp1, halfLength);
        Strassen(temp, temp1, s7, halfLength);

        //����matrixResult11
        Add(s1, s4, temp, halfLength);
        Sub(s7, s5, temp1, halfLength);
        Add(temp, temp1, matrixResult11, halfLength);

        //����matrixResult12
        Add(s3, s5, matrixResult12, halfLength);

        //����matrixResult21
        Add(s2, s4, matrixResult21, halfLength);

        //����matrixResult22
        Add(s1, s3, temp, halfLength);
        Sub(s6, s2, temp1, halfLength);
        Add(temp, temp1, matrixResult22, halfLength);

        //����������
        for (int i = 0; i < length / 2; i++)
        {
            for (int j = 0; j < length / 2; j++)
            {
                matrixResult[i][j] = matrixResult11[i][j];
                matrixResult[i][j + length / 2] = matrixResult12[i][j];
                matrixResult[i + length / 2][j] = matrixResult21[i][j];
                matrixResult[i + length / 2][j + length / 2] = matrixResult22[i][j];
            }
            //�ͷ��ڴ�
            delete(a11[i]);
            delete(a12[i]);
            delete(a21[i]);
            delete(a22[i]);

            delete(b11[i]);
            delete(b12[i]);
            delete(b21[i]);
            delete(b22[i]);

            delete(s1[i]);
            delete(s2[i]);
            delete(s3[i]);
            delete(s4[i]);
            delete(s5[i]);
            delete(s6[i]);
            delete(s7[i]);

            delete(matrixResult11[i]);
            delete(matrixResult12[i]);
            delete(matrixResult21[i]);
            delete(matrixResult22[i]);

            delete(temp[i]);
            delete(temp1[i]);
        }
        delete(a11);
        delete(a12);
        delete(a21);
        delete(a22);

        delete(b11);
        delete(b12);
        delete(b21);
        delete(b22);

        delete(s1);
        delete(s2);
        delete(s3);
        delete(s4);
        delete(s5);
        delete(s6);
        delete(s7);

        delete(matrixResult11);
        delete(matrixResult12);
        delete(matrixResult21);
        delete(matrixResult22);

        delete(temp);
        delete(temp1);
    }

}

//����A��B��ʼ����ֵ����
void FillMatrix(int** MatrixA, int** MatrixB, int** MatrixResult, int length)
{
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            MatrixA[i][j] = rand()%10;
            MatrixB[i][j] = rand()%10;
            MatrixResult[i][j] = 0;
        }
    }
}
    int main()
    {
        int length = 8;  //��ʼ������ά��
        int** MatrixA;    //��ž���A
        int** MatrixB;    //��ž���B
        int** MatrixResult;    //��Ž������
        MatrixA =new int*[length];
        MatrixB =new int*[length];
        MatrixResult =new int*[length];
        for (int i = 0; i < length; i++)
        {
            MatrixA[i] =new int[length];
            MatrixB[i] =new int[length];
            MatrixResult[i] =new int[length];
        }

        //����ֵ
        FillMatrix(MatrixA, MatrixB, MatrixResult,length);

        cout << "��ʼ��A����Ϊ��" << endl;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
                cout << MatrixA[i][j] << " ";
            cout << endl;
        }

        cout << "��ʼ��B����Ϊ��" << endl;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
                cout << MatrixB[i][j] << " ";
            cout << endl;
        }

        //����Strassen�������A*B
        Strassen( MatrixA, MatrixB, MatrixResult, length);

        //�������A*B
        cout << "����A*B=" << endl;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
                cout << MatrixResult[i][j] << " ";
            cout << endl;
        }
        return 0;
    }










4.3 code time

#include <iostream>
using namespace std;

int tile = 0;//���Ʊ��
int Board[4][4];//����
void ChessBoard(int tr,int tc,int dr,int dc,int size);

int main()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            Board[i][j] = 0;
        }
    }

    ChessBoard(0,0,1,2,4);

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    }
}

/**
 * tr : �������Ͻǵ��кţ�tc�������Ͻǵ��к�
 * dr : ���ⷽ�����Ͻǵ��кţ�dc���ⷽ�����Ͻǵ��к�
 * size ��size = 2^k ���̹��Ϊ2^k*2^k
 */
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size == 1)
    {
        return;
    }
    int t = tile++;//L�͹��Ʊ��
    int s = size/2;//�ָ�����

    //�������Ͻ�������
    if(dr<tr+s && dc<tc+s)//���ⷽ���ڴ�������
    {
        ChessBoard(tr,tc,dr,dc,s);
    }
    else//���ⷽ���ڴ�������
    {
        //�ñ��Ϊt�Ĺ��Ƹ������½�
        Board[tr+s-1][tc+s-1] = t;
        //�������෽��
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }

    //�������Ͻ�������
    if(dr<tr+s && dc>=tc+s)//���ⷽ���ڴ�������
    {
        ChessBoard(tr,tc+s,dr,dc,s);
    }
    else//���ⷽ���ڴ�������
    {
        //�ñ��Ϊt�Ĺ��Ƹ������½�
        Board[tr+s-1][tc+s] = t;
        //�������෽��
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }

    //�������½�������
    if(dr>=tr+s && dc<tc+s)//���ⷽ���ڴ�������
    {
        ChessBoard(tr+s,tc,dr,dc,s);
    }
    else//���ⷽ���ڴ�������
    {
        //�ñ��Ϊt�Ĺ��Ƹ������Ͻ�
        Board[tr+s][tc+s-1] = t;
        //�������෽��
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }

    //�������½�������
    if(dr>=tr+s && dc>=tc+s)//���ⷽ���ڴ�������
    {
        ChessBoard(tr+s,tc+s,dr,dc,s);
    }
    else//���ⷽ���ڴ�������
    {
        //�ñ��Ϊt�Ĺ��Ƹ������Ͻ�
        Board[tr+s][tc+s] = t;
        //�������෽��
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }

}





RANDOMIZED-SELECT ( A, p, r, i )
if  p = r           // �ٽ����⴦��
       then  return A[p]
q �� RANDOMIZED-PARTITION( A, p, r )   //���л��֣����ػ���Ԫ�±�
k �� q �C p + 1
if  i = k
       then return A[q];
else if i < k
        then return RANDOMIZED-SELECT ( A, p, q - 1, i )
else
         return RANDOMIZED-SELECT( A, q+1, r, i �C k )



 5.3 code time

#include <iostream>
#include <ctime>
#define N 10
using namespace std;

//��������������ֵ
void exchange(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// ��ָ���λ��
int partition(int * array, int low, int high)
{
    int i = low - 1;
    //Ĭ�Ͻ����ֶε����һ��Ԫ��Ϊ��Ԫ
    int x = array[high];

    for (int j = low; j < high; j++)
    {
        if (array[j] <= x)//��array[i]��߶���С��x��array[high]�������ұ߾��Ǵ���������
        {
            i += 1;
            exchange(array[i], array[j]);
        }
    }
    exchange(array[i + 1], array[high]);
    return i + 1;       // ѭ����Ϻ�i+1���Ǹ�����ķָ��
}

// ��low ~ high ֮���һ�����Ԫ����Ϊ��Ԫ�����طָ���λ��
int RandomPartition(int *array, int low, int high)
{
    //�ҵ�low ~ high ֮���һ�����λ��
    int i = rand() % (high - low + 1) + low;

    //�����������Ԫ��β����
    exchange(array[i], array[high]);

    return partition(array, low, high);
}

// ������������ѡ���i����С��Ԫ��
int RandomizedSelect(int *data, int l, int h, int i)
{
    //������������н���һ��Ԫ��
    if (l == h)
        return data[l];

    //��ָ��pos,��λ�����Ԫ�ؾ�С��data[pos] , �ұ�Ԫ�ؾ�����data[pos]
    int pos = RandomPartition(data, l, h);

    //��÷ָ���ǵڼ�СԪ��
    int k = pos - l + 1;

    //������ǵ�ǰ��iСԪ�أ��򷵻�data[pos]
    if (k == i)
        return data[pos];
    else if (k < i)
        return RandomizedSelect(data, pos + 1, h, i - k);
    else
        return RandomizedSelect(data, l, pos - 1, i);
}

int main()
{
    //����һ������������
    int array[N];
    //������������ӣ�����ÿ�β�����ͬ�������
    srand((unsigned)time(NULL));
    for (int i = 0; i<N; i++)
        array[i] = rand() % 101;    //���鸳ֵʹ�������������1-100֮��������
    cout << "ԭ���У�" << endl;
    for (int j = 0; j<N; j++)
        cout << array[j] << "  ";

    cout << endl << "��С�������ڵ�5λ���ǣ� " ;
    cout << RandomizedSelect(array, 0, N - 1 , 5);
    cout << endl;

    return 0;
}





6.3 code time

//�ο���https://blog.csdn.net/liufeng_king/article/details/8484284
#include<bits/stddc++.h>
using namespace std;
const int maxn=100005;
struct Point{
  double x;
}p[maxn];

int a[maxn];
int cmpx(Point a,Point b){
  return a.x<b.x;
}
inline double dis(Point a,Point b){
   if(a.x>b.x) return a.x-b.x;
   else return b.x-a.x;
}

double closest(int low,int high){
  if(low+1==high)  //ֻ��������
    return dis(p[low],p[high]);
  if(low+2==high)  //ֻ��������
    return min(dis(p[low],p[high]),min(dis(p[low],p[low+1]),dis(p[low+1],p[high])));
  int mid=(low+high)/2; //���е㼴�����Ӽ��ķֽ���
  double d=min(closest(low,mid),closest(mid+1,high));
  d=min(d,dis(p[mid],p[mid+1])); //���һ�����ϲ�
  return d;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%lf",&p[i].x);
        sort(p,p+n,cmpx);
        printf("%.2lf\n",closest(0 , n-1));//�����Լ�ľ���
    }
    return 0;





// team: �������Žṹ��team[2k] vs team[2k+1]
// len: team������
// id: ��id�ֵİ��ţ�id�ķ�Χ[1, len-1]
#include<iostream>
using namespace std;
const int len = 8;

void game(int *team, int len, int id)
{
    int base = 2;
    while (id > len/base)
    {
        id = id - len/base;
        base = base * 2;
    }
    for (int i = 0; i < base/2; i++)
    {
        int start = i + base/2 + (id-1) * base;
        for (int j=0; j<len/base; j++)
        {
            team[i*2*len/base+2*j] = base*j+i;
            team[i*2*len/base+2*j+1] = (start+base*j)%len;
        }
    }
}

void dump(int *arr, int len)
{
    for (int i=0; i<len; i+=2)
        cout<< arr[i] <<" VS "<<arr[i+1]<<" ";
    cout<<endl;
}

int main()
{
    int team[len];
    for (int i=1; i<len; i++)
    {
        game(team, len, i);
        cout<<"DAY "<<i<<" ";
        dump(team, len);
    }
    return 0;


