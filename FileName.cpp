#include<stdio.h>
struct DTZT
{
    int ZT;
    int DSQTYPE;
    int CSTKLC;
    int BDY;
    int flag;
}a[4];
int flag, slxl, szlc, golc, lccz[3], dth[3], i, flag1 = 0;
int js(int x, int y, int z, int g) //����¥���ֵ����
{
    int c, b, sum;
    if (a[x].ZT == 0)//��ʱa[x]���ݴ��ھ�ֹ״̬
    {
        if (y == z)
            return 0;
        else if (y < z)
        {
            c = z - y;
            if (y > g)
            {
                b = y - g;
            }
            else
            {
                b = g - y;
            }
            sum = c + b;
        }
        else if (y > z)
        {
            c = y - z;
            if (y > g)
            {
                b = y - g;
            }
            else
            {
                b = g - y;
            }
            sum = c + b;
        }
        return sum;
    }
}

void SL_XL_formOtoJ_AND_fromJtoO()
{
    lccz[0] = js(0, szlc, a[0].CSTKLC, golc);
    lccz[1] = js(1, szlc, a[3].CSTKLC, golc);
    if (lccz[0] < lccz[1])
    {
        printf("���û�������ҷ��������ĵ���Ϊ��1��\n");
        a[0].CSTKLC = golc;
    }
    else
    {
        printf("���û�������ҷ��������ĵ���Ϊ��4��\n");
        a[3].CSTKLC = golc;
    }

}
void XL_SL_fromOtoO()
{
    lccz[0] = js(0, szlc, a[0].CSTKLC, golc);
    lccz[1] = js(1, szlc, a[2].CSTKLC, golc);
    lccz[2] = js(2, szlc, a[3].CSTKLC, golc);
    if (lccz[0] < lccz[1])
    {
        if (lccz[0] < lccz[2])
        {
            printf("���û�������ҷ��������ĵ���Ϊ��1��\n");
            a[0].CSTKLC = golc;
        }
        else
        {
            printf("���û�������ҷ��������ĵ���Ϊ��4��\n");
            a[3].CSTKLC = golc;
        }
    }
    else
    {
        if (lccz[1] < lccz[2])
        {
            printf("���û�������ҷ��������ĵ���Ϊ��3��\n");
            a[2].CSTKLC = golc;
        }
        else
        {
            printf("���û�������ҷ��������ĵ���Ϊ��4��\n");
            a[3].CSTKLC = golc;
        }
    }

}

void SL_XL_fromJtoJ()
{
    lccz[0] = js(0, szlc, a[0].CSTKLC, golc);
    lccz[1] = js(1, szlc, a[1].CSTKLC, golc);
    lccz[2] = js(2, szlc, a[3].CSTKLC, golc);
    if (lccz[0] < lccz[1])
    {
        if (lccz[0] < lccz[2])
        {
            printf("���û�������ҷ��������ĵ���Ϊ��1��\n");
            a[0].CSTKLC = golc;

        }
        else
        {
            printf("���û�������ҷ��������ĵ���Ϊ��4��\n");
            a[3].CSTKLC = golc;

        }
    }
    else
    {
        if (lccz[1] < lccz[2])
        {
            printf("���û�������ҷ��������ĵ���Ϊ��2��\n");
            a[1].CSTKLC = golc;

        }
        else
        {
            printf("���û�������ҷ��������ĵ���Ϊ��4��\n");
            a[3].CSTKLC = golc;

        }
    }
}

int  main() //���˲���
{
    printf("*   ȫ��¥��    ����       ˫��      ȫ��¥��\n");
    printf("*   ******     ******     ******     ******   *\n");
    printf("*    1��          2��        3��        4��    *\n");
    printf("***********************************************\n");
    printf("*   ******     ******     ******     ******   *\n");
    printf("*   |    |     |    |     |    |     |    |   *\n");
    printf("*     2          11         8          19    *\n");
    printf("*   |    |     |    |     |    |     |    |   *\n");
    printf("*   ******     ******     ******     ******   *\n");
    printf("***********************************************\n");
    a[0].ZT = 0;//����״̬����ֹ�����У�����
    a[1].ZT = 0;
    a[2].ZT = 0;
    a[3].ZT = 0;
    a[0].CSTKLC = 2;//��ʾ��ʱ����ͣ�ڵ�¥����Ϊ1¥
    a[1].CSTKLC = 11;//��ʾ��ʱ����ͣ�ڵ�¥����Ϊ7¥
    a[2].CSTKLC = 8;//��ʾ��ʱ����ͣ�ڵ�¥����Ϊ14¥
    a[3].CSTKLC = 19;//��ʾ��ʱ����ͣ�ڵ�¥����Ϊ20¥
    a[0].DSQTYPE = 2;//һ�ŵ�������¥�㶼ͣ��
    a[1].DSQTYPE = 1;//���ŵ��ݵ���¥�㶼ͣ��
    a[2].DSQTYPE = 0;//���ŵ���˫��¥�㶼ͣ��
    a[3].DSQTYPE = 2;//�ĺŵ�������¥�㶼ͣ��
    int i;
    int flag1 = 0;
    int j = 0;
    printf("--------------------------------------------------\n");
    printf("ʹ�õ����밴��ť 1 \n");
    scanf_s("%d", &flag);//��ʱ�Ƿ����˰����� 1
    if (flag == 1)
    {
        printf("*****��ʱ���û������ݣ�*****\n");
    }
    printf("������¥��Ϊ: ");
    scanf_s("%d", &szlc);//��ʱ�����ݵ������ڵ�¥���� 5
    printf("��¥�밴 1 ����¥�밴 0: ");
    scanf_s("%d", &slxl);//�û���������¥������¥��� 1
    printf("��ѡ��Ҫȥ��¥��: ");
    scanf_s("%d", &golc);//�û�Ҫȥ��¥�� 15
    if (flag == 1 && slxl == 1 && szlc % 2 == 0 && golc % 2 == 1)//�û���Ҫ������¥��ż����Ҫȥ������
        SL_XL_formOtoJ_AND_fromJtoO();//������¥��¥������ȥż�����ż����ȥ������
    if (flag == 1 && slxl == 1 && szlc % 2 == 0 && golc % 2 == 0)//�û���Ҫ������¥��ż����Ҫȥż����
        XL_SL_fromOtoO();//������¥��¥ż����ȥż����
    if (flag == 1 && slxl == 1 && szlc % 2 == 1 && golc % 2 == 0)//�û���Ҫ������¥��������Ҫȥż����
        SL_XL_formOtoJ_AND_fromJtoO();
    if (flag == 1 && slxl == 1 && szlc % 2 == 1 && golc % 2 == 1)//�û���Ҫ������¥��������Ҫȥ������
        SL_XL_fromJtoJ();//������¥��¥������ȥ������
    if (flag == 1 && slxl == 0 && szlc % 2 == 0 && golc % 2 == 1)//�û���Ҫ������¥��ż����Ҫȥ������
        SL_XL_formOtoJ_AND_fromJtoO();
    if (flag == 1 && slxl == 0 && szlc % 2 == 0 && golc % 2 == 0)//�û���Ҫ������¥��ż����Ҫȥż����
        XL_SL_fromOtoO();
    if (flag == 1 && slxl == 0 && szlc % 2 == 1 && golc % 2 == 0)//�û���Ҫ������¥��������Ҫȥż����
        SL_XL_formOtoJ_AND_fromJtoO();
    if (flag == 1 && slxl == 0 && szlc % 2 == 1 && golc % 2 == 1)//�û���Ҫ������¥��������Ҫȥ������
        SL_XL_fromJtoJ();
    printf("***********************************************\n");
    printf("*   ******     ******     ******     ******   *\n");
    printf("*   |    |     |    |     |    |     |    |   *\n");
    printf("*   *  %2d     * %2d      *  %2d        *%2d     *\n", a[0].CSTKLC, a[1].CSTKLC, a[2].CSTKLC, a[3].CSTKLC);
    printf("*   |    |     |    |     |    |     |    |   *\n");
    printf("*   ******     ******     ******     ******   *\n");
    printf("***********************************************\n");
    return 0;
}