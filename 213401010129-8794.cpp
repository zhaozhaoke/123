#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define N 100
typedef struct staff {
	int ID;//ְ����
	string name;//����
	int num;//���������
	int time;//�����ʱ��
	struct number* first;
}SF;

typedef struct number
{
	int Num = 0;//�������
	int Time;//���ʱ��
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
	printf("������ְ����ɵĲ�Ʒ������\n");
	p->next = (number*)malloc(sizeof(number));//����ռ䣬�����ݴ�������
	p->next->next = NULL;//������¿ռ��ָ��ָ���
	scanf("%d", &p->Num);
	f << p->Num << endl;
	sf[b].num += p->Num;//��ɵ��ۼ�
	printf("������ְ����ɵ�ʱ�䣺\n");
	scanf("%d", &p->Time);
	f << p->Time << endl;
	f.close();//�رղ������ļ�
	sf[b].time += p->Time;
	printf("\n");
}

//��Ӳ�Ʒ�������
void creat()
{
	f.open("text.txt", ios::app);//���ļ�������ļ��������򴴽�һ��
	int i = 0, a;
	printf("������ְ������\n");
	int b = 0, k = 0;
	cin >> b;
	f << b << endl;//�������ݣ�����ͬ��
	//�ҵ���ְ��
	for (int i = 0; i < n; i++)
	{
		if (sf[i].ID == b)
		{
			printf("������ְ��������\n");
			cin >> sf[i].name;
			f << sf[i].name << endl;
			PYdata(i);
			k = 1;
			break;
		}
	}
	//����Ҳ���ְ�����½�ְ��
	if (k == 0) {
		for (int i = 0; i < n; i++)
		{
			if (sf[i].ID == 0) {
				sf[i].ID = b;
				printf("������ְ��������\n");
				cin >> sf[i].name;
				f << sf[i].name << endl;
				PYdata(i);
				n++;
				break;
			}
		}
	}
}
//��ȡ����
void read()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);//���ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	int y = 1;
	string buf; string str2;
	int o = 0; int v = 0; int q = 0;
	while (getline(ifs, buf))
	{
		if (y % 4 == 1) {//�ж϶�ȡ���ַ�������ʵ��������ͬ��
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
			//�ҵ���ְ��
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
					p->next = (number*)malloc(sizeof(number));//����ռ䣬�����ݴ�������
					p->next->next = NULL;//������¿ռ��ָ��ָ���
					p->Num = v;
					sf[i].num += p->Num;//��ɵ��ۼ�
					p->Time = q;
					sf[i].time += p->Time;
					k = 1;
					break;
				}
			}
			//����Ҳ���ְ�����½�ְ��
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
						p->next = (number*)malloc(sizeof(number));//����ռ䣬�����ݴ�������
						p->next->next = NULL;//������¿ռ��ָ��ָ���
						p->Num = v;
						sf[i].num += p->Num;//��ɵ��ۼ�
						p->Time = q;
						sf[i].time += p->Time;
						n++;
						break;
					}
				}
			}
		}y++;
	}
	ifs.close();//�رղ������ļ�
}

//�������������ʹ��
void PR(staff S[], int i)
{
	cout << "ID:" << S[i].ID << "     " << "����:" << S[i].name << "     " << "�������:"
		<< S[i].num << "     " << "���ʱ��:" << S[i].time << endl;
}
//��������
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
//ð������
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
		}if (flag == 0)break;//���һ��ѭ����δ����������˵���������

	}
	for (int i = 0; i < n - 1; i++)
	{
		if (sf[i].name != "0") {
			printf("��%d��\n", i + 1);
			PR(S, i);
		}
	}
}

void Printf(int b)
{
	number* p = sf[b].first;//p����ʱָ�룬����sf[b].first������
	do
	{
		cout << "�������:" << p->Num << "      " << "���ʱ��:" << p->Time << endl;
		p = p->next;
	} while (p->next != NULL);

}
//��ѯ������ɼ�¼
void Find() {
	int i = 0, a;
	printf("������ְ������\n");
	int b = 0, k = 0;
	cin >> b;
	for (int i = 0; i < n; i++)
	{
		if (sf[i].ID == b)
		{
			cout << "ID:" << sf[i].ID << endl;
			cout << "����:" << sf[i].name << endl;
			Printf(i);
			k = 1;
			break;
		}
	}
	if (k == 0)
		cout << "δ�ҵ���Ա��" << endl;
}
int main()
{
	int a;

	//��ʼ����0�Ϳ�ָ��
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
		printf("\t\t\t\t|======�������������======|\n");
		printf("\t\t\t\t|      0.�˳�����            |\n");
		printf("\t\t\t\t|      1.��ȡ֮ǰ��¼        |\n");
		printf("\t\t\t\t|      2.��Ӳ�Ʒ�������    |\n");
		printf("\t\t\t\t|      3.��ѯ�����������    |\n");
		printf("\t\t\t\t|      4.��ѯ������ɼ�¼    |\n");
		printf("\t\t\t\t|============================|\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:read(); break;
		case 2:creat(); break;
		case 3:Bubble_sort(sf); break;
		case 4:Find(); break;
		case 0:printf("��лʹ��"); return 1;
		default:
		{
			cout << "�����������������\n";
			break; }
		}

	} while (a != 5);
	return 0;
}


