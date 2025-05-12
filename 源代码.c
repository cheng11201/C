#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void Member_Menu();//会员管理系统菜单
void Member_Switch(int n);//选择进入不同功能
void add_Member();
void amend_Member();
void inquire_Member();
void delete_Member();
void Playground_Menu();//娱乐设施管理菜单
void Playground_NewBuild();//新建设施
void Playground_Seek();//查询设施
void Playground_Remove();//移除设施
void Menu_Serve();
void Select_Serve(int n);
void add_Serve();
void delete_Serve();
void amend_Serve();
void set_Serve();
void check_Serve();
int serve_Num=0,i;
typedef struct resident{
    int Member_ID;//会员编号
    char Member_Name[50];
    char Member_Gender[50];//会员性别
    int Member_Age;//会员年龄
    int Serve_ID;//负责的服务人员编号
    int locate_housenum;
}RESIDENT;
typedef struct Serve{
	int serve_ID;
	char serve_name[20];
	int serve_State;
	int customer_ID;
	int customer_Mark;
	int total_Mark;
}SERVE;
void Playground_Menu()
{
    printf("********************************************\n");
    printf("********************************************\n");
    printf("**                                        **\n");
    printf("**        欢迎使用娱乐设施管理系统        **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
        printf("(警告！只有管理员才有权限操作！)\n\n");
        printf("1.新建娱乐设施\n");
        printf("2.查询娱乐设施\n");
        printf("3.移除娱乐设施\n");
        printf("4.返回\n");
}
 RESIDENT p[100];
 typedef struct facility
{
    int data;
    char name[20];
    int maxnum;
    int flag;
    struct facility*next;
}node;


void Playground_Management()
    {
        int choose;
    do
    {
        system("cls");
        Playground_Menu();
         printf("请选择功能\n");
         scanf("%d",&choose);
         if(choose==4) break;
         else{
        switch(choose)
        {
        case 1:Playground_NewBuild();
            break;
        case 2:Playground_Seek();
            break;
        case 3:Playground_Remove();
            break;
        }}}while(1);



    }
//新建设施
void Playground_NewBuild()
{
    int choose;
    node*head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node*p=head;
    while(1)
    {if(choose==-1) break;
    else{
    node*cur=(node*)malloc(sizeof(node));
    cur->next=NULL;
    printf("请输入设备编号:\n");
    scanf("%d",&cur->data);
    printf("请输入设备名称:\n");
    scanf("%s",cur->name);
    printf("请输入最大人数:\n");
    scanf("%d",&cur->maxnum);
    printf("结束新建请按-1\n");
    scanf("%d",&choose);
    cur->flag=0;
    p->next=cur;
    p=cur;}
    }
    FILE*fp1;
    fp1=fopen("娱乐设施信息.txt","a+");
    int ch;
    ch=fgetc(fp1);
    if(ch==EOF)
    fprintf(fp1,"编号    设备    最大人数 使用情况(0表示未使用，1代表已用)\n");
    fclose(fp1);
    FILE*fp2;
    fp2=fopen("娱乐设施信息.txt","a");
    node *k=head->next;
    while(k!=NULL)
    {
       fprintf(fp2,"%d\t",k->data);
       fprintf(fp2,"%s\t",k->name);
       fprintf(fp2,"%d\t",k->maxnum);
       fprintf(fp2,"%d\n",k->flag);
       k=k->next;
    }
    fclose(fp2);
}

void Playground_Seek()
{
     int flag=0;
     FILE *fp;
     fp=fopen("娱乐设施信息.txt","r");
     int n1,n2,n3,c;
     printf("请输入设施编号\n");
     scanf("%d",&c);
     char a[20];
     fscanf(fp,"%*[^\n]%*c");
     while(!feof(fp)){
     fscanf(fp,"%d%s%d%d",&n1,a,&n2,&n3);
     if(n1==c)
    {printf("查询结果如下\n");
     printf("编号    设备    最大人数 使用情况(0表示未使用，1代表已用)\n");
     printf("%d\t%s\t%d\t%d\n",n1,a,n2,n3);
     flag=1;}}
     if(flag==0) printf("查无此项\n");
     printf("请按任意键继续..\n");
     getch();
     fclose(fp);
}

void Playground_Remove()
{
	FILE* fp1;
	FILE* fp2;
	int data,n1,n2,n3;
	char a[20];
	fp1=fopen("娱乐设施信息.txt","r+");
	fp2=fopen("临时.txt","w+");//新建一个临时文件
	printf("请输入您要删除设施的编号\n");
	scanf("%d",&data);
	fscanf(fp1,"%d%s%d%d",&n1,a,&n2,&n3);
	while (!feof(fp1))
    {
       if (data!=n1)//不是要删除的内容
		{
			fprintf(fp2, "%d\t%s\t%d\t%d\n",n1,a,n2,n3);
		}
		fscanf(fp1,"%d%s%d%d",&n1,a,&n2,&n3);
	}
	fclose(fp1);
	fclose(fp2);
	remove("娱乐设施信息.txt");
	rename("临时.txt","娱乐设施信息.txt");
	printf("删除成功\n");
	printf("请按任意键返回..");
    getch();
}

int Member_Num=50,i;

void Member_Menu(){
    printf("********************************************\n");
    printf("********************************************\n");
    printf("**                                        **\n");
    printf("**          欢迎使用会员管理系统          **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
    printf(">>>>>>1.新建会员\n\n");
    printf(">>>>>>2.修改会员\n\n");
    printf(">>>>>>3.查询会员\n\n");
    printf(">>>>>>4.删除会员\n\n");
    printf(">>>>>>5.退出会员管理系统\n\n");
    int a;
    scanf("%d",&a);
    while(a>5){
        puts("输入错误，请重新输入！");
        scanf("%d",&a);
    }
    Member_Switch(a);
}//会员管理系统菜单

void Member_Switch(int a){
    switch(a){
        case 1:
            system("cls");
            add_Member();
            break;
        case 2:
            system("cls");
            amend_Member();
            break;
        case 3:
            system("cls");
            inquire_Member();
            break;
        case 4:
            system("cls");
            delete_Member();
            break;
        case 5:
            system("cls");
            main();
            break;
    }
}//选择进入不同功能

void add_Member(){
    int x1;
    FILE *fp=fopen("Member.txt","ab");
    RESIDENT p;
    puts("********** 新建会员 **********\n\n\n");
    printf("1.新建\n\n");
    printf("2.退出\n\n");
    scanf("%d",&x1);
    if(x1==1){
        system("cls");
        printf(">>>>>>本次只能新增一名会员，请输入新增会员的编号<<<<<<\n");
        scanf("%d",&p.Member_ID);
        printf("请输入新增会员的姓名\n");
        scanf("%s",p.Member_Name);
        printf("\n请输入新增会员的性别\n");
        scanf("%s",p.Member_Gender);
        printf("\n请输入新增会员的年龄\n");
        scanf("%d",&p.Member_Age);
        fwrite(&p,sizeof(RESIDENT),1,fp);
        fclose(fp);system("cls");
        printf("会员新增成功！\n请按1退回会员管理系统\n");
        int n1;
        scanf("%d",&n1);
        while(n1!=1){
            puts("\a输入错误！请再次输入！\n");
            scanf("%d",&n1);
            }
        system("cls");
        add_Member();
        }
    else if(x1==2){
        system("cls");
        Member_Menu();
        }
        else system("cls");
        printf("\a输入错误，请输入任意数字以返回！\n");
        scanf("%d",&x1);
        system("cls");
        add_Member();
}//新建会员

void amend_Member(){
    int x2;
    printf("**********  修改会员  **********\n\n\n");
	printf("1.修改\n\n");
	printf("2.退出\n\n");
	scanf("%d",&x2);
	if(x2==1){
	    printf(">>>>>>本功能用于修改会员信息，请输入人员编号<<<<<<\n");
	    FILE *fp=fopen("Member.txt","rb+");
	    if(fp==NULL)
            printf("File open failed!\n");
        RESIDENT p[50];
        int m2,n2,n22,k2,flag2=0;
        scanf("%d",&m2);
        system("cls");
        fread(p,sizeof(RESIDENT),Member_Num,fp);
        fclose(fp);
        for(i=0;i<Member_Num;i++){
            if(p[i].Member_ID==m2){
                flag2=1;
                printf("********** %d号会员信息 **********\n\n\n",m2);
                printf("会员姓名：%s\n\n",p[i].Member_Name);
                printf("会员性别：%s\n\n",p[i].Member_Gender);
                printf("会员年龄：%d\n\n",p[i].Member_Age);
                k2=i;
                break;
                }
            }
        if(flag2==0){
            printf("\a没有该会员！\n");
            printf("按1以返回会员管理系统\n");
            scanf("%d",&n2);
            system("cls");
            while(n2!=1){
                    printf("\a输入错误！请重新输入！\n");
                    scanf("%d",&n2);
                    }
            system("cls");
            amend_Member();
            }
        printf("请选择：\n\n");
        printf(">>>>>> 1.会员姓名\n\n");
        printf(">>>>>> 2.会员性别\n\n");
        printf(">>>>>> 3.会员年龄\n\n");
        printf(">>>>>> 5.返回上页\n\n");
        printf(">>>>>> 6.退出会员修改系统\n\n");
        printf("请输入一个数字：\n");
        scanf("%d",&n22);
        if(n22==5){
            system("cls");
            amend_Member();
            }
        if(n22==6){
            system("cls");
            Member_Menu();
            }
        system("cls");
        printf("请输入修改\n");
        switch(n22){
            case 1:
                scanf("%s",p[k2].Member_Name);
                system("cls");
                break;
            case 2:
                scanf("%s",p[k2].Member_Gender);
                system("cls");
                break;
            case 3:
                scanf("%d",&p[k2].Member_Age);
                system("cls");
                break;
            case 4:
                scanf("%d",&p[k2].Serve_ID);
                system("cls");
                break;
            }
        printf("修改信息成功！请按1以退回用户管理系统！\n");
        fp=fopen("Member.txt","wb");
        fwrite(p,sizeof(RESIDENT),Member_Num,fp);
        fclose(fp);
        scanf("%d",&n2);
        system("cls");
        while(n2!=1){
                printf("\a输入错误，请再次输入！\n");
                scanf("%d",&n2);
                }
        system("cls");
        amend_Member();
	}
	else if(x2==2){
        system("cls");
        Member_Menu();
	}
	else system("cls");
	printf("\a输入错误，请输入任意数字以返回！\n");
	scanf("%d",&x2);
	system("cls");
	amend_Member();
}//修改会员

void inquire_Member(){
    int x3;
    printf("**********  查询会员  **********\n\n\n");
    printf("1.查询\n\n");
    printf("2.退出\n\n");
    scanf("%d",&x3);
    if(x3==1){
        printf(">>>>>>本功能用于查询会员，请输入你想查询的会员编号<<<<<<\n");
        FILE *fp=fopen("Member.txt","rb");
        if(fp==NULL){
            printf("File open failed!\n");
            }
        RESIDENT p[50];
        int m3,n3,k3,flag3=0;
        scanf("%d",&m3);
        system("cls");
        fread(p,sizeof(RESIDENT),Member_Num,fp);
        fclose(fp);
        for(i=0;i<Member_Num;i++){
            if(p[i].Member_ID==m3){
                flag3=1;
                printf("********** %d号会员信息 **********\n\n\n",m3);
                printf("会员姓名：%s\n\n",p[i].Member_Name);
                printf("会员性别：%s\n\n",p[i].Member_Gender);
                printf("会员年龄：%d\n\n",p[i].Member_Age);
                printf("按1以返回查询系统\n");
                scanf("%d",&n3);
                while(n3!=1){
                    system("cls");
                    puts("\a输入错误，请重新输入！");
                    scanf("%d",&n3);
                    }
                system("cls");
                inquire_Member();
                }
            }
        if(flag3==0){
            printf("\a没有该会员！\n");
            printf("按1以返回会员查询系统\n");
            scanf("%d",&n3);
            system("cls");
            while(n3!=1){
                printf("\a输入错误，请重新输入！\n");
                scanf("%d",&n3);
                }
            system("cls");
            inquire_Member();
            }
        }
    else if(x3==2){
            system("cls");
            Member_Menu();
            }
            else system("cls");
            printf("\a输入错误，请输入任意数字以返回！\n");
            scanf("%d",&x3);
            system("cls");
            inquire_Member();
}//查询会员

void delete_Member(){
    int x4;
    printf("**********  删除会员  **********\n\n\n");
    printf("1.删除\n\n");
    printf("2.退出\n\n");
    scanf("%d",&x4);
    if(x4==1){
        printf(">>>>>>本功能用于删除会员信息，请输入人员编号<<<<<<\n");
        FILE *fp=fopen("Member.txt","rb+");
        if(fp==NULL){
                printf("File open failed!\n");
                }
        int m4,n4,k4,k41=0,n42,flag4=0;
        RESIDENT p[50];
        scanf("%d",&m4);
        system("cls");
        fread(p,sizeof(RESIDENT),Member_Num,fp);
        fclose(fp);
        for(i=0;i<Member_Num;i++){
            if(p[i].Member_ID==m4){
                flag4=1;
                printf("******* %d号会员信息 *******\n\n",m4);
                printf("会员姓名：%s\n\n",p[i].Member_Name);
                printf("会员性别：%s\n\n",p[i].Member_Gender);
                printf("会员年龄：%d\n\n",p[i].Member_Age);
                k4=i;
                }
            }
        if(flag4==0){
            printf("\a没有该会员！\n");
            printf("按1以返回会员删除系统\n");
            scanf("%d",&n4);
            system("cls");
            while(n4!=1){
                printf("\a输入错误！请再次输入！\n");
                scanf("%d",&n4);
                }
            system("cls");
            delete_Member();
            }
        if(flag4==1){
            printf("确定删除该会员信息？\n");
            printf(">>>>>> 1.确定\n");
            printf(">>>>>> 2.取消\n");
            scanf("%d",&n42);
            system("cls");
            if(n42==1){
                for(i=0;i<Member_Num;i++){
                    if(i!=k4){
                        p[k41]=p[i];
                        k41++;
                        }
                    }
                fp=fopen("Member.txt","wb");
                fwrite(p,sizeof(RESIDENT),Member_Num,fp);
                fclose(fp);
                printf("删除会员信息成功！\n");
                printf("按1以退回会员删除系统\n");
                scanf("%d",&n4);
                system("cls");
                }
                else delete_Member();
                while(n4!=1){
                    printf("输入错误！请再次输入！\n");
                    scanf("%d",&n4);
                    }
                system("cls");
                delete_Member();
                }
            }
            else if(x4==2){
                system("cls");
                Member_Menu();
                }
                else system("cls");
                printf("\a输入错误，请输入任意数字以返回！\n");
                scanf("%d",&x4);
                system("cls");
                delete_Member();
}//删除会员

  typedef struct HOUSE
{
    int num1;
    int num2;
    int num3;//房间号
    int price;
    int type;//1代表公寓，2代表普通住宅，3代表别墅
    int area;//面积
    int user;//会员编号初始为0
    int flag;//0为无人购买，1为有人购买
}HOUSE;

void House_Built()
{
     FILE *fp1;
     fp1=fopen("房屋信息.txt","a+");
     int ch;
     ch=fgetc(fp1);
     if(ch==EOF)
    {fprintf(fp1,"n号楼      n单元        n室    房屋类型   面积(m2) 价格(w) 会员编号 出售情况\n");
     fprintf(fp1,"(其中:房屋类型中1代表公寓,2代表普通住宅,3代表别墅;出售情况中0代表暂未出售,1代表已经售出,2代表出租，3代表空置)");}
     fclose(fp1);
     FILE *fp2;
     fp2=fopen("房屋信息.txt","a");
     HOUSE house;
     printf(">>新建房屋<<\n\n");
     printf("请输入房屋位置\n");
     printf("(例如:该房屋为1号楼1单元101室,则请您依次输入1 1 101)\n");
     scanf("%d",&house.num1);
     scanf("%d",&house.num2);
     scanf("%d",&house.num3);
     printf("请输入房屋类型\n");
     printf("(房屋类型中1代表公寓,2代表普通住宅,3代表别墅)\n");
     scanf("%d",&house.type);
     printf("请输入房屋面积(单位:平方米)\n");
     scanf("%d",&house.area);
     printf("请输入房屋价格(单位:万)\n");
     scanf("%d",&house.price);
     house.user=0;
     house.flag=0;
     fprintf(fp2,"\n%d\t%d\t%d\t%d\t%d\t%d\t%d %d",house.num1,house.num2,house.num3,house.type,house.area,house.price,house.user,house.flag);
     fclose(fp2);
     printf("房屋信息创建成功\n");
     printf("..即将返回上一级,请按任意键继续..");
     getch();
}

void House_Buy()
{
    printf(">>购买房屋<<\n\n");
    FILE *fp1;
    if((fp1=fopen("房屋信息.txt","r+"))==NULL)
   {printf("操作失败,请先创建房屋信息\n");
    exit(1);}
    int i,c1,c2,c3,c4,c5,c6,c7,n1,n2,n3,n4,n5,n6,n7,n8,flag=0;
    printf("请输入想要购买的房屋的类型\n");
    printf("(房屋类型中1代表公寓,2代表普通住宅,3代表别墅)\n");
    scanf("%d",&c4);
    printf("请输入想要购买的房屋的面积\n");
    printf("(例如:需购房屋面积为50-59平,只需输入50)\n");
    scanf("%d",&c5);
    printf("请输入想要购买的房屋的价格\n");
    printf("(例如：需购房屋价格为10-19万，只需输入10)\n");
    scanf("%d",&c6);
    for(i=0;i<2;i++)
   {fscanf(fp1,"%*[^\n]%*c");}
    while(!feof(fp1))
   {fscanf(fp1,"%d%d%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8);
    if(n4==c4&&(n5>=c5&&n5<c5+10)&&(n6>=c6&&n6<c6+10)&&n8==0)
   {if(flag==0)
   {printf("符合条件的房屋信息如下:\n");
    printf("***************************************************\n");
    printf("n号楼n单元n室 房屋类型 面积(平米)价格(万)\n");
    printf("(其中:房屋类型中1代表公寓,2代表普通住宅,3代表别墅)\n");
    flag=1;}
    printf("%d    %d    %d\t%d\t%d\t%d\n",n1,n2,n3,n4,n5,n6);}}
    fclose(fp1);
    FILE *fp2;
    if((fp2=fopen("房屋信息.txt","r+"))==NULL)
   {printf("操作失败,请先创建房屋信息\n");
    exit(1);}
    if(flag==1)
   {printf("***************************************************\n");
    printf("请选择会员想要购买的房屋\n");
    printf("(例如:该房屋为1号楼1单元101室,则请您依次输入1 1 101)\n");
    scanf("%d",&c1);
    scanf("%d",&c2);
    scanf("%d",&c3);
    printf("请输入会员编号\n");
    scanf("%d",&c7);
    for(i=0;i<2;i++)
   {fscanf(fp2,"%*[^\n]%*c");}
    while(!feof(fp2))
   {fscanf(fp2,"%d%d%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8);
    if(c1==n1&&c2==n2&&c3==n3&&n8==0)
   {fseek(fp2,-4,SEEK_CUR);
    fprintf(fp2," %d 1",c7);
    printf("房屋购买成功\n");
    flag=1;
    break;}}}
    if(flag==0)
    printf("暂无符合条件的房屋\n");
    printf("..即将返回上一级,请按任意键继续..");
    getch();
    fclose(fp2);
}

void House_Search()
{
    printf(">>>房屋信息查询<<<\n\n");
    FILE *fp;
    if((fp=fopen("房屋信息.txt","r+"))==NULL)
   {printf("操作失败,请先创建房屋信息\n");
    exit(1);}
    int i,c1,c2,c3,n1,n2,n3,n4,n5,n6,n7,n8,flag=0;
    printf("请输入想要查询的房屋的位置信息\n");
    printf("(例如:该房屋为1号楼1单元101室,则请您依次输入1 1 101)\n");
    scanf("%d",&c1);
    scanf("%d",&c2);
    scanf("%d",&c3);
    for(i=0;i<2;i++)
   {fscanf(fp,"%*[^\n]%*c");}
    while(!feof(fp))
   {fscanf(fp,"%d%d%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8);
    if(n1==c1&&n2==c2&&n3==c3)
   {if(flag==0)
   {printf("查询结果如下:\n");
    printf("***************************************************\n");
    printf("n号楼n单元n室 房屋类型 面积(平米)价格(万)会员编号 出售情况\n");
    printf("(其中:房屋类型中1代表公寓,2代表普通住宅,3代表别墅)\n");
    flag=1;}
    printf("%d    %d    %d\t%d\t%d\t%d\t%d\t%d\n",n1,n2,n3,n4,n5,n6,n7,n8);}}
    if(flag==1)
    printf("***************************************************\n");
    if(flag==0)
    printf("房屋不存在\n");
    printf("..即将返回上一级,请按任意键继续..");
    getch();
    fclose(fp);
}

void House_Management_menu()
{
     printf("********************************************\n");
    printf("********************************************\n");
    printf("**                                        **\n");
    printf("**          欢迎使用房屋管理系统          **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
    printf("1.新建房屋\n");
    printf("2.房屋信息查询\n");
    printf("3.购买房屋\n");
    printf("4.返回上一级\n");
}

void House_Management()
{
    int choose;
    while(1)
    {
       system("cls");
       House_Management_menu();
       printf("请选择\n");
       scanf("%d",&choose);
       system("cls");
       if(choose==4) break;
       else
       switch(choose)
       {
           case 1:House_Built();
           break;
           case 2:House_Search();
           break;
           case 3:House_Buy();
           break;
       }
    }
}

 int user()
{
    printf("********************************************\n");
    printf("********************************************\n");
    printf("**                                        **\n");
    printf("**          欢迎使用入住管理系统          **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
   printf("请输入您要查询的会员编号\n");
   int i=0;
   scanf("%d",&i);
   return i;
}
void checkin(int num)
{
    //打印改用户的所有房产
    FILE *fp1=fopen("房屋信息.txt","a+");
    fscanf(fp1,"%*[^\n]%*c");
    fscanf(fp1,"%*[^\n]%*c");
    int a,b,c,d,e,f,g,h;
    printf(">>>选择入住<<<\n\n");
    printf("以下为您的房产信息\n");
    printf("n号楼      n单元        n室    房屋类型   面积(m2) 价格(w)会员编号 出售情况\n");
     while(!feof(fp1)){
            fscanf(fp1,"%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
            if(g==num)
   printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a,b,c,d,e,f,g,h);
   }
  printf("请输入您进行操作的房屋的编号\n");
  int i,t,r;
  printf("例如:该房屋为1号楼1单元101室,则请您依次输入1 1 101\n");
  scanf("%d %d %d",&i,&t,&r);
  fclose(fp1);
  printf("请输入你要进行的操作\n");
  printf("1.入住\n");
  printf("2.出租\n");
  printf("3.空置\n");
  int v;
  scanf("%d",&v);
   FILE *fp2=fopen("房屋信息.txt","r+");
    fscanf(fp2,"%*[^\n]%*c");
    fscanf(fp2,"%*[^\n]%*c");
    while(!feof(fp2))
    {
        fscanf(fp2,"%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
        if(i==a&&t==b&&r==c)
       {fseek(fp2,-1,SEEK_CUR);
        fprintf(fp2,"%d",v);
        break;
    }}
    fclose(fp2);
   switch(v)
{
    case 1:printf("入住办理已成功\n");
    break;
    case 2:printf("出租办理已成功\n");
        break;
    case 3:printf("空置办理已成功\n");
    break;
}
   printf("即将返回上一级，请按任意键继续..\n");
   getch();
   system("cls");
}
 void apply()
 {
    char b[20];
    int a,c,d;
    printf(">>>申请娱乐设施<<<\n\n");
    FILE *fp;
    fp=fopen("娱乐设施信息.txt","r");
    printf("以下为全部娱乐设施信息\n");
    printf("编号\t名称\t最大容纳量\t使用情况(0表示未使用，1代表已用)\n");
    fscanf(fp,"%*[^\n]%*c");
    while(!feof(fp))
   {fscanf(fp,"%d%s%d%d",&a,b,&c,&d);
    printf("%d\t%s\t%d\t%d\n",a,b,c,d);}
    fclose(fp);
    FILE *fp2;
    fp2=fopen("娱乐设施信息.txt","r+");
    printf("请输入您要申请的娱乐设施的编号\n");
    int i,flag=0;
    scanf("%d",&i);
    fscanf(fp2,"%*[^\n]%*c");
    while(!feof(fp2))
    {
        fscanf(fp2,"%d%s%d%d",&a,b,&c,&d);
       if(a==i&&d==0)
       {
           fseek(fp2,-1,SEEK_CUR);
           fprintf(fp2,"1");
           printf("申请成功,您现在可以使用该设施\n");
           flag=1;
           break;
       }

   }
   fclose(fp2);
   if(flag==0)
    printf("该设施已有人使用\n");
   printf("即将返回上一级，请按任意键继续..");
   getch();
   system("cls");
 }
void result()
{
    printf("服务成功.\n");
}
void choice(int num)
{
        int i=0;
       while(i!=3)
      {printf("1.选择入住\n");
       printf("2.申请娱乐设施\n");
       printf("3.返回\n");
       int i=0;
       scanf("%d",&i);
       system("cls");
       switch(i){
       case 1:checkin(num);
       break;
       case 2:apply();
       break;
       case 3:
        return 0;
       }
       }

}
void mainmenu(void)
{   printf("******************************\n");
    printf("************** ***************\n");
    printf("*************   **************                请选择功能\n");
    printf("************     *************\n");
    printf("***********       ************              >>>>>1.会员管理\n");
    printf("**                         ***\n");
    printf("***       欢迎使用        ****              >>>>>2.房屋管理\n");
    printf("****                     *****\n");
    printf("*****   活力长者社区    ******              >>>>>3.入住管理\n");
    printf("******                 *******\n");
    printf("*****     管理系统       *****              >>>>>4.场馆设施排队管理\n");
    printf("****                     *****\n");
    printf("***                       ****              >>>>>5.用户管理\n");
    printf("**                         ***\n");
    printf("***********       ************              >>>>>6.退出\n");
    printf("************     *************\n");
    printf("*************   **************\n");
    printf("************** ***************\n");
    printf("******************************\n\n");
    system("color 1F");
}
void Serve_Menu(){
    printf("********************************************\n");
    printf("********************************************\n");
    printf("**                                        **\n");
    printf("**       欢迎使用服务人员管理系统         **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
	printf("1.新增服务人员\n");
	printf("2.修改服务人员\n");
	printf("3.删除服务人员\n");
	printf("4.设置服务对象\n");
	printf("5.查看服务人员\n");
	printf("6.退出系统\n");
	int n;
	scanf("%d",&n);
	Select(n);
}
void Select(int n){
	switch(n){
		case 1:
			system("cls");
			add_Serve();
			break;
		case 2:
			system("cls");
		    amend_Serve();
		    break;
		case 3:
			system("cls");
		    delete_Serve();
		    break;
		case 4:
			system("cls");
		    set_Serve();
		    break;
		case 5:
			system("cls");
		    check_Serve();
		    break;
		case 6:
			system("cls");
			printf("欢迎下次使用\n");
			return;
	}
}

void add_Serve(){
	printf("**********  新增服务人员  **********\n\n");
	FILE *fp=fopen("Serve.txt","ab");
	SERVE p;
	printf("请输入新增服务人员编号\n");
	scanf("%d",&(p).serve_ID);
	printf("\n\n");
	printf("请输入新增服务人员姓名\n");
	scanf("%s",(p).serve_name);
	p.customer_Mark=0;
	p.total_Mark=0;
	p.serve_State=0;
	p.customer_ID=0;

	fwrite(&p,sizeof(SERVE),1,fp);
	fclose(fp);
	system("cls");
	printf("新增成功！\n按1反回用户管理系统.\n");
	serve_Num++;
	int n;
	scanf("%d",&n);
	while(n!=1){
		printf("\a输入错误！请再次输入！\n");
		scanf("%d",&n);
	}
	system("cls");
	Serve_Menu();
}

void amend_Serve(){
	printf("**********  修改服务人员  **********\n\n");
	printf("请输入人员编号\n");

	FILE *fp=fopen("Serve.txt","rb+");

	if(fp==NULL)
	  printf("File open failed!\n");

	SERVE p[10];
	int m,n,n2,k,flag=0;
	scanf("%d",&m);
	system("cls");
	fread(p,sizeof(SERVE),serve_Num,fp);
	fclose(fp);
	for(i=0;i<serve_Num;i++){
		if(p[i].serve_ID==m){
			flag=1;
		printf("******* %d号服务人员信息 *******\n\n");
		printf("服务人员编号：%d\n\n",p[i].serve_ID);
	    printf("服务人员姓名：%s\n\n",p[i].serve_name);
	    printf("服务人员详情：%d\n\n",p[i].serve_State);
	    printf("服务人员对象：%d\n\n",p[i].customer_ID);
	    printf("服务人员评分：%d\n\n",p[i].customer_Mark);
	    k=i;
	    break;
		}
	}
	if(flag==0){
	  printf("\a没有该服务人员！\n");
	  printf("按1以退回用户管理系统。\n");
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a输入错误！请再次输入！\n");
		scanf("%d",&n);
	  }
	     system("cls");
     Serve_Menu();
    }
	printf("请输入你想修改的信息\n");
	printf(">>> 1服务详情\n\n");
	printf(">>> 2服务评分\n\n");
	scanf("%d",&n2);
	printf("请输入修改\n") ;
	if(n2==1){
		scanf("%d",&p[k].serve_State);
	}
	else{
		scanf("%d",&p[k].customer_Mark);
	}
	fp=fopen("Serve.txt","wb");
	fwrite(p,sizeof(SERVE),serve_Num,fp);
	fclose(fp);
	printf("修改成功，按1以退回用户管理系统\n");
	scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a输入错误，请再次输入\n");
		scanf("%d",&n);
	  }
	     system("cls");
    Serve_Menu();
}

void delete_Serve(){

	printf("**********  删除服务人员  **********\n\n\n");

	printf("请输入您想删除的人员编号：\n");

	FILE *fp=fopen("Serve.txt","rb+");

	if(fp==NULL)
	  printf("打开失败\n");
	int m,n,k,n2,flag;
	SERVE p[10];
	scanf("%d",&m);
	system("cls");
	fread(p,sizeof(SERVE),serve_Num,fp);
	fclose(fp);
	for(i=0;i<serve_Num;i++){
		if(p[i].serve_ID==m){
			flag=1;
		printf("******* %d号*******\n\n");
		printf("服务人员编号：%d\n\n",p[i].serve_ID);
	    printf("服务人员姓名：%s\n\n",p[i].serve_name);
	    printf("服务人员详情：%d\n\n",p[i].serve_State);
	    printf("服务人员对象：%d\n\n",p[i].customer_ID);
	    printf("服务人员评分：%d\n\n",p[i].customer_Mark);
	    k=i;
	    break;
		}
	}
	if(flag==0){
	  printf("\a没有该服务人员\n");
	  printf("按1以退回用户管理系统。\n");
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a输入错误，请再次输入\n");
		scanf("%d",&n);
	  }
	     system("cls");
   Serve_Menu();
    }
    printf("是否删除该人员信息？\n");
    printf("1.确定\n");
    printf("2.取消\n");
    scanf("%d",&n2);
    system("cls");
    if(n2==1){
    	for(i=k;i<serve_Num-1;i++){
    		p[i]=p[i+1];
		}
		serve_Num--;
		fp=fopen("Serve.txt","wb");
		fwrite(p,sizeof(SERVE),serve_Num,fp);
		fclose(fp);
	}
	printf("删除人员信息成功！\n");
	printf("按1以退回用户管理系统。\n");
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("输入错误！请再次输入！\n");
		scanf("%d",&n);
	  }
	     system("cls");
   Serve_Menu();
}

void set_Serve(){
	int k;
	printf("********** 服务对象设置  **********\n\n\n");
	printf("请输入服务人员编号.\n");
	int m,flag=0,d;
	scanf("%d",&m);
	SERVE p[10];

	FILE *fp=fopen("Serve.txt","rb");
	if(fp==NULL)
	  printf("File open failed!\n");
	fread(p,sizeof(SERVE),serve_Num,fp);
	fclose(fp);


	for(i=0;i<serve_Num;i++){
	  if(p[i].serve_ID==m){
	  	flag=1;
	  	printf("\n\n**********  服务人员信息  **********\n\n\n");
	    printf("服务人员编号：%d\n\n",p[i].serve_ID);
	    printf("服务人员姓名：%s\n\n",p[i].serve_name);
	    printf("服务人员详情：%d\n\n",p[i].serve_State);
	    printf("服务人员对象：%d\n\n",p[i].customer_ID);
	    printf("服务人员评分：%d\n\n",p[i].customer_Mark);
	    k=i;
       }
      }
      if(flag==0)
        printf("\a该人员编号不存在\n");
      else{
		printf("请输入要设置的对象编号:\n");
      	scanf("%d",&p[k].customer_ID);
      	fp=fopen("serve.txt","wb");
      	fwrite(p,sizeof(SERVE),serve_Num,fp);
      	fclose(fp);
      	system("cls");
      	printf("设置服务对象成功\n");
	  }

      printf("按1以退回用户管理系统\n");
	  int n;
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a输入错误，请再次输入\n");
		scanf("%d",&n);
	  }
	     system("cls");
    Serve_Menu();

  }


void check_Serve(){
	printf("**********  服务人员查询  **********\n\n\n");
	printf("请输入服务人员的编号\n");
	int m,flag=0;
	scanf("%d",&m);

	FILE *fp=fopen("Serve.txt","rb");
	if(fp==NULL)
	  printf("File open failed!\n");

	SERVE p[10];
	fread(p,sizeof(SERVE),serve_Num,fp);
	fclose(fp);
	for(i=0;i<serve_Num;i++){
	  if(p[i].serve_ID==m){
	  	flag=1;
	  	printf("\n\n**********  服务人员信息  **********\n\n\n");
	    printf("服务人员编号：%d\n\n",p[i].serve_ID);
	    printf("服务人员姓名：%s\n\n",p[i].serve_name);
	    printf("服务人员详情：%d\n\n",p[i].serve_State);
	    printf("服务人员对象：%d\n\n",p[i].customer_ID);
	    printf("服务人员评分：%d\n\n",p[i].customer_Mark);
       }
      }
      if(flag==0)
        printf("\a编号为空！\n");
      printf("按1以退回用户管理系统。\n");
	  int n;
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a输入错误！请再次输入！\n");
		scanf("%d",&n);
	  }
	     system("cls");
  Serve_Menu();
}
void selection(void)
{
    int choose;
    int usernum;
    do
    {
        mainmenu();
         scanf("%d",&choose);
        switch(choose)
        {

       case 1:
           system("cls");
           Member_Menu();
       break;
        case 2:House_Management();
            break;
        case 3:
            system("cls");
            usernum=user();
            choice(usernum);
            break;
        case 4:Playground_Management();
            break;
        case 5:
            system("cls");
            Serve_Menu();
            break;
        case 6: exit(1);
        break;
        }
        system("cls");
    }while(1);
}
int main()
{
    selection();
}
