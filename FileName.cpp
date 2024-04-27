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
int js(int x, int y, int z, int g) //计算楼层差值函数
{
    int c, b, sum;
    if (a[x].ZT == 0)//此时a[x]电梯处于静止状态
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
        printf("离用户最近并且符合条件的电梯为：1号\n");
        a[0].CSTKLC = golc;
    }
    else
    {
        printf("离用户最近并且符合条件的电梯为：4号\n");
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
            printf("离用户最近并且符合条件的电梯为：1号\n");
            a[0].CSTKLC = golc;
        }
        else
        {
            printf("离用户最近并且符合条件的电梯为：4号\n");
            a[3].CSTKLC = golc;
        }
    }
    else
    {
        if (lccz[1] < lccz[2])
        {
            printf("离用户最近并且符合条件的电梯为：3号\n");
            a[2].CSTKLC = golc;
        }
        else
        {
            printf("离用户最近并且符合条件的电梯为：4号\n");
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
            printf("离用户最近并且符合条件的电梯为：1号\n");
            a[0].CSTKLC = golc;

        }
        else
        {
            printf("离用户最近并且符合条件的电梯为：4号\n");
            a[3].CSTKLC = golc;

        }
    }
    else
    {
        if (lccz[1] < lccz[2])
        {
            printf("离用户最近并且符合条件的电梯为：2号\n");
            a[1].CSTKLC = golc;

        }
        else
        {
            printf("离用户最近并且符合条件的电梯为：4号\n");
            a[3].CSTKLC = golc;

        }
    }
}

int  main() //接人操作
{
    printf("*   全部楼层    单层       双层      全部楼层\n");
    printf("*   ******     ******     ******     ******   *\n");
    printf("*    1号          2号        3号        4号    *\n");
    printf("***********************************************\n");
    printf("*   ******     ******     ******     ******   *\n");
    printf("*   |    |     |    |     |    |     |    |   *\n");
    printf("*     2          11         8          19    *\n");
    printf("*   |    |     |    |     |    |     |    |   *\n");
    printf("*   ******     ******     ******     ******   *\n");
    printf("***********************************************\n");
    a[0].ZT = 0;//三种状态：静止，上行，下行
    a[1].ZT = 0;
    a[2].ZT = 0;
    a[3].ZT = 0;
    a[0].CSTKLC = 2;//表示此时电梯停在的楼层数为1楼
    a[1].CSTKLC = 11;//表示此时电梯停在的楼层数为7楼
    a[2].CSTKLC = 8;//表示此时电梯停在的楼层数为14楼
    a[3].CSTKLC = 19;//表示此时电梯停在的楼层数为20楼
    a[0].DSQTYPE = 2;//一号电梯所有楼层都停靠
    a[1].DSQTYPE = 1;//二号电梯单号楼层都停靠
    a[2].DSQTYPE = 0;//三号电梯双号楼层都停靠
    a[3].DSQTYPE = 2;//四号电梯所有楼层都停靠
    int i;
    int flag1 = 0;
    int j = 0;
    printf("--------------------------------------------------\n");
    printf("使用电梯请按按钮 1 \n");
    scanf_s("%d", &flag);//此时是否有人按电梯 1
    if (flag == 1)
    {
        printf("*****此时有用户按电梯！*****\n");
    }
    printf("您所在楼层为: ");
    scanf_s("%d", &szlc);//此时按电梯的人所在的楼层数 5
    printf("上楼请按 1 ，下楼请按 0: ");
    scanf_s("%d", &slxl);//用户请求是上楼还是下楼标记 1
    printf("请选择要去的楼层: ");
    scanf_s("%d", &golc);//用户要去的楼层 15
    if (flag == 1 && slxl == 1 && szlc % 2 == 0 && golc % 2 == 1)//用户需要电梯上楼在偶数层要去奇数层
        SL_XL_formOtoJ_AND_fromJtoO();//计算上楼下楼奇数层去偶数层和偶数层去奇数层
    if (flag == 1 && slxl == 1 && szlc % 2 == 0 && golc % 2 == 0)//用户需要电梯上楼在偶数层要去偶数层
        XL_SL_fromOtoO();//计算上楼下楼偶数层去偶数层
    if (flag == 1 && slxl == 1 && szlc % 2 == 1 && golc % 2 == 0)//用户需要电梯上楼在奇数层要去偶数层
        SL_XL_formOtoJ_AND_fromJtoO();
    if (flag == 1 && slxl == 1 && szlc % 2 == 1 && golc % 2 == 1)//用户需要电梯上楼在奇数层要去奇数层
        SL_XL_fromJtoJ();//计算上楼下楼奇数层去奇数层
    if (flag == 1 && slxl == 0 && szlc % 2 == 0 && golc % 2 == 1)//用户需要电梯下楼在偶数层要去奇数层
        SL_XL_formOtoJ_AND_fromJtoO();
    if (flag == 1 && slxl == 0 && szlc % 2 == 0 && golc % 2 == 0)//用户需要电梯下楼在偶数层要去偶数层
        XL_SL_fromOtoO();
    if (flag == 1 && slxl == 0 && szlc % 2 == 1 && golc % 2 == 0)//用户需要电梯下楼在奇数层要去偶数层
        SL_XL_formOtoJ_AND_fromJtoO();
    if (flag == 1 && slxl == 0 && szlc % 2 == 1 && golc % 2 == 1)//用户需要电梯下楼在奇数层要去奇数层
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