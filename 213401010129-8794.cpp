#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define N 100
typedef struct staff {
	int ID;//职工号
	string name;//名字
	int num;//完成总数量
	int time;//完成总时间
	struct number* first;
}SF;

typedef struct number
{
	int Num = 0;//完成数量
	int Time;//完成时间
	struct number* next;
}number;

int n = 1; SF sf[N];

fstream f;
void PYdata(int b) {
	int i = 0;
	number* p = sf[b].first;
	for (;; p = p->next)
	{
		if (p->next == NULL)
			break;
	}
	printf("请输入职工完成的产品数量：\n");
	p->next = (number*)malloc(sizeof(number));//申请空间，将数据存入其中
	p->next->next = NULL;//申请的新空间的指针指向空
	scanf("%d", &p->Num);
	f << p->Num << endl;
	sf[b].num += p->Num;//完成的累计
	printf("请输入职工完成的时间：\n");
	scanf("%d", &p->Time);
	f << p->Time << endl;
	f.close();//关闭并保存文件
	sf[b].time += p->Time;
	printf("\n");
}

//添加产品完成数量
void creat()
{
	f.open("text.txt", ios::app);//打开文件，如果文件不存在则创建一个
	int i = 0, a;
	printf("请输入职工工号\n");
	int b = 0, k = 0;
	cin >> b;
	f << b << endl;//保存数据，以下同理
	//找到该职工
	for (int i = 0; i < n; i++)
	{
		if (sf[i].ID == b)
		{
			printf("请输入职工姓名：\n");
			cin >> sf[i].name;
			f << sf[i].name << endl;
			PYdata(i);
			k = 1;
			break;
		}
	}
	//如果找不到职工，新建职工
	if (k == 0) {
		for (int i = 0; i < n; i++)
		{
			if (sf[i].ID == 0) {
				sf[i].ID = b;
				printf("请输入职工姓名：\n");
				cin >> sf[i].name;
				f << sf[i].name << endl;
				PYdata(i);
				n++;
				break;
			}
		}
	}
}
//读取函数
void read()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);//打开文件
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	int y = 1;
	string buf; string str2;
	int o = 0; int v = 0; int q = 0;
	while (getline(ifs, buf))
	{
		if (y % 4 == 1) {//判断读取的字符串代表实名，以下同理
			o = atoi(buf.c_str());
			printf("%d  ", o);
		}
		if (y % 4 == 2) {
			str2 = buf;
			cout << str2 << "   ";
		}
		if (y % 4 == 3) {
			v = atoi(buf.c_str());
			printf("%d  ", v);
		}
		if (y % 4 == 0) {
			q = atoi(buf.c_str());
			printf("%d\n", q);
			int i = 0, a;
			int b = 0, k = 0;
			b = o;
			//找到该职工
			for (int i = 0; i < n; i++)
			{
				if (sf[i].ID == b)
				{
					sf[i].name = str2;
					number* p = sf[i].first;
					for (;; p = p->next)
					{
						if (p->next == NULL)
							break;
					}
					p->next = (number*)malloc(sizeof(number));//申请空间，将数据存入其中
					p->next->next = NULL;//申请的新空间的指针指向空
					p->Num = v;
					sf[i].num += p->Num;//完成的累计
					p->Time = q;
					sf[i].time += p->Time;
					k = 1;
					break;
				}
			}
			//如果找不到职工，新建职工
			if (k == 0) {
				for (int i = 0; i < n; i++)
				{
					if (sf[i].ID == 0) {
						sf[i].ID = b;
						sf[i].name = str2;
						number* p = sf[i].first;
						for (;; p = p->next)
						{
							if (p->next == NULL)
								break;
						}
						p->next = (number*)malloc(sizeof(number));//申请空间，将数据存入其中
						p->next->next = NULL;//申请的新空间的指针指向空
						p->Num = v;
						sf[i].num += p->Num;//完成的累计
						p->Time = q;
						sf[i].time += p->Time;
						n++;
						break;
					}
				}
			}
		}y++;
	}
	ifs.close();//关闭并保存文件
}

//输出函数排序中使用
void PR(staff S[], int i)
{
	cout << "ID:" << S[i].ID << "     " << "名称:" << S[i].name << "     " << "完成数量:"
		<< S[i].num << "     " << "完成时间:" << S[i].time << endl;
}
//交换函数
void Swap(staff S[], int i) {
	staff a;
	a.ID = 0;
	a.name = "0";
	a.num = 0;
	a.first = (number*)malloc(sizeof(number));
	a.first->next = NULL;
	a.first->Num = 0;
	a.first->Time = 0;
	a.ID = S[i].ID;
	S[i].ID = S[i + 1].ID;
	S[i + 1].ID = a.ID;

	a.name = S[i].name;
	S[i].name = S[i + 1].name;
	S[i + 1].name = a.name;

	a.num = S[i].num;
	S[i].num = S[i + 1].num;
	S[i + 1].num = a.num;

	a.time = S[i].time;
	S[i].time = S[i + 1].time;
	S[i + 1].time = a.time;

	a.first = S[i].first;
	S[i].first = S[i + 1].first;
	S[i + 1].first = a.first;
}
//冒泡排序
void Bubble_sort(staff S[])
{
	for (int p = n - 1; p >= 0; p--)
	{
		int flag = 0;
		for (int i = 0; i < p; i++)
		{
			if (S[i].num < S[i + 1].num)
			{
				Swap(S, i);
				flag = 1;
			}
		}if (flag == 0)break;//如果一次循环中未发生交换则说明排序完成

	}
	for (int i = 0; i < n - 1; i++)
	{
		if (sf[i].name != "0") {
			printf("第%d名\n", i + 1);
			PR(S, i);
		}
	}
}

void Printf(int b)
{
	number* p = sf[b].first;//p是临时指针，调用sf[b].first中内容
	do
	{
		cout << "完成数量:" << p->Num << "      " << "完成时间:" << p->Time << endl;
		p = p->next;
	} while (p->next != NULL);

}
//查询个人完成记录
void Find() {
	int i = 0, a;
	printf("请输入职工工号\n");
	int b = 0, k = 0;
	cin >> b;
	for (int i = 0; i < n; i++)
	{
		if (sf[i].ID == b)
		{
			cout << "ID:" << sf[i].ID << endl;
			cout << "名字:" << sf[i].name << endl;
			Printf(i);
			k = 1;
			break;
		}
	}
	if (k == 0)
		cout << "未找到该员工" << endl;
}
int main()
{
	int a;

	//初始化，0和空指针
	for (int i = 0; i < N; i++) {
		sf[i].ID = 0;
		sf[i].name = "0";
		sf[i].num = 0;
		sf[i].first = (number*)malloc(sizeof(number));
		sf[i].first->next = NULL;
		sf[i].first->Num = 0;
		sf[i].first->Time = 0;
	}

	do {
		printf("\t\t\t\t|======请输入所需服务：======|\n");
		printf("\t\t\t\t|      0.退出程序            |\n");
		printf("\t\t\t\t|      1.读取之前记录        |\n");
		printf("\t\t\t\t|      2.添加产品完成数量    |\n");
		printf("\t\t\t\t|      3.查询总量完成排名    |\n");
		printf("\t\t\t\t|      4.查询个人完成记录    |\n");
		printf("\t\t\t\t|============================|\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:read(); break;
		case 2:creat(); break;
		case 3:Bubble_sort(sf); break;
		case 4:Find(); break;
		case 0:printf("感谢使用"); return 1;
		default:
		{
			cout << "输入错误，请重新输入\n";
			break; }
		}

	} while (a != 5);
	return 0;
}


