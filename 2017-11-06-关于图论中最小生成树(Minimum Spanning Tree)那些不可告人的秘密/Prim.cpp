#include<iostream>
#define NO 99999999   //99999999��������֮�䲻�ɴ�
#define N 5
using namespace std;

bool visit[N];
long long money[N] = { 0 };
long long graph[N][N] = {0};

void initgraph()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf(" %lld", &graph[i][j]);
		}
	}
	
}

void printgraph()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf(" %lld", graph[i][j]);
		}
	}

}

long long prim(int city)
{
	initgraph();
	int index = city;
	long long  sum = 0;
	int i = 0;
	int j = 0;
	cout <<"���ʽڵ㣺" <<index << "\n";
	memset(visit, false, sizeof(visit));
	visit[city] = true;
	for (i = 0; i < N; i++)
	{
		money[i] = graph[city][i];//��ʼ����ÿ�������city�������ķ��ô���money���Ա�����Ƚ�
	}
		
	for (i = 1; i < N; i++)
	{
		long long  minor = NO;
		for (j = 0; j < N; j++)
		{
			if ((visit[j] == false) && money[j] < minor)  //�ҵ�δ���ʵĳ����У��뵱ǰ��С�������еĳ��м������С�ĳ���
			{
				minor = money[j];
				index = j;
			}
		}
		visit[index] = true;
		cout << "���ʽڵ㣺" << index << "\n";
		sum += minor; //���ܵ���ͷ���
		/*������һ�����£����δ���ʳ����뵱ǰ���м�ķ��ø��ͣ��͸���money,������͵ķ���*/
		for (j = 0; j < N; j++)
		{
			if ((visit[j] == false) && money[j]>graph[index][j])
			{
				money[j] = graph[index][j];
			}
		}
	}
	cout << endl;
	return sum;               //�����ܷ�����Сֵ
}
int main()
{
	cout << "��·����ܷ���Ϊ��"<< prim(0) << endl;//�ӳ���0��ʼ

	system("pause");
	return 0;
}