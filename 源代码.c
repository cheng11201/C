#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void Member_Menu();//��Ա����ϵͳ�˵�
void Member_Switch(int n);//ѡ����벻ͬ����
void add_Member();
void amend_Member();
void inquire_Member();
void delete_Member();
void Playground_Menu();//������ʩ����˵�
void Playground_NewBuild();//�½���ʩ
void Playground_Seek();//��ѯ��ʩ
void Playground_Remove();//�Ƴ���ʩ
void Menu_Serve();
void Select_Serve(int n);
void add_Serve();
void delete_Serve();
void amend_Serve();
void set_Serve();
void check_Serve();
int serve_Num=0,i;
typedef struct resident{
    int Member_ID;//��Ա���
    char Member_Name[50];
    char Member_Gender[50];//��Ա�Ա�
    int Member_Age;//��Ա����
    int Serve_ID;//����ķ�����Ա���
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
    printf("**        ��ӭʹ��������ʩ����ϵͳ        **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
        printf("(���棡ֻ�й���Ա����Ȩ�޲�����)\n\n");
        printf("1.�½�������ʩ\n");
        printf("2.��ѯ������ʩ\n");
        printf("3.�Ƴ�������ʩ\n");
        printf("4.����\n");
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
         printf("��ѡ����\n");
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
//�½���ʩ
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
    printf("�������豸���:\n");
    scanf("%d",&cur->data);
    printf("�������豸����:\n");
    scanf("%s",cur->name);
    printf("�������������:\n");
    scanf("%d",&cur->maxnum);
    printf("�����½��밴-1\n");
    scanf("%d",&choose);
    cur->flag=0;
    p->next=cur;
    p=cur;}
    }
    FILE*fp1;
    fp1=fopen("������ʩ��Ϣ.txt","a+");
    int ch;
    ch=fgetc(fp1);
    if(ch==EOF)
    fprintf(fp1,"���    �豸    ������� ʹ�����(0��ʾδʹ�ã�1��������)\n");
    fclose(fp1);
    FILE*fp2;
    fp2=fopen("������ʩ��Ϣ.txt","a");
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
     fp=fopen("������ʩ��Ϣ.txt","r");
     int n1,n2,n3,c;
     printf("��������ʩ���\n");
     scanf("%d",&c);
     char a[20];
     fscanf(fp,"%*[^\n]%*c");
     while(!feof(fp)){
     fscanf(fp,"%d%s%d%d",&n1,a,&n2,&n3);
     if(n1==c)
    {printf("��ѯ�������\n");
     printf("���    �豸    ������� ʹ�����(0��ʾδʹ�ã�1��������)\n");
     printf("%d\t%s\t%d\t%d\n",n1,a,n2,n3);
     flag=1;}}
     if(flag==0) printf("���޴���\n");
     printf("�밴���������..\n");
     getch();
     fclose(fp);
}

void Playground_Remove()
{
	FILE* fp1;
	FILE* fp2;
	int data,n1,n2,n3;
	char a[20];
	fp1=fopen("������ʩ��Ϣ.txt","r+");
	fp2=fopen("��ʱ.txt","w+");//�½�һ����ʱ�ļ�
	printf("��������Ҫɾ����ʩ�ı��\n");
	scanf("%d",&data);
	fscanf(fp1,"%d%s%d%d",&n1,a,&n2,&n3);
	while (!feof(fp1))
    {
       if (data!=n1)//����Ҫɾ��������
		{
			fprintf(fp2, "%d\t%s\t%d\t%d\n",n1,a,n2,n3);
		}
		fscanf(fp1,"%d%s%d%d",&n1,a,&n2,&n3);
	}
	fclose(fp1);
	fclose(fp2);
	remove("������ʩ��Ϣ.txt");
	rename("��ʱ.txt","������ʩ��Ϣ.txt");
	printf("ɾ���ɹ�\n");
	printf("�밴���������..");
    getch();
}

int Member_Num=50,i;

void Member_Menu(){
    printf("********************************************\n");
    printf("********************************************\n");
    printf("**                                        **\n");
    printf("**          ��ӭʹ�û�Ա����ϵͳ          **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
    printf(">>>>>>1.�½���Ա\n\n");
    printf(">>>>>>2.�޸Ļ�Ա\n\n");
    printf(">>>>>>3.��ѯ��Ա\n\n");
    printf(">>>>>>4.ɾ����Ա\n\n");
    printf(">>>>>>5.�˳���Ա����ϵͳ\n\n");
    int a;
    scanf("%d",&a);
    while(a>5){
        puts("����������������룡");
        scanf("%d",&a);
    }
    Member_Switch(a);
}//��Ա����ϵͳ�˵�

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
}//ѡ����벻ͬ����

void add_Member(){
    int x1;
    FILE *fp=fopen("Member.txt","ab");
    RESIDENT p;
    puts("********** �½���Ա **********\n\n\n");
    printf("1.�½�\n\n");
    printf("2.�˳�\n\n");
    scanf("%d",&x1);
    if(x1==1){
        system("cls");
        printf(">>>>>>����ֻ������һ����Ա��������������Ա�ı��<<<<<<\n");
        scanf("%d",&p.Member_ID);
        printf("������������Ա������\n");
        scanf("%s",p.Member_Name);
        printf("\n������������Ա���Ա�\n");
        scanf("%s",p.Member_Gender);
        printf("\n������������Ա������\n");
        scanf("%d",&p.Member_Age);
        fwrite(&p,sizeof(RESIDENT),1,fp);
        fclose(fp);system("cls");
        printf("��Ա�����ɹ���\n�밴1�˻ػ�Ա����ϵͳ\n");
        int n1;
        scanf("%d",&n1);
        while(n1!=1){
            puts("\a����������ٴ����룡\n");
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
        printf("\a����������������������Է��أ�\n");
        scanf("%d",&x1);
        system("cls");
        add_Member();
}//�½���Ա

void amend_Member(){
    int x2;
    printf("**********  �޸Ļ�Ա  **********\n\n\n");
	printf("1.�޸�\n\n");
	printf("2.�˳�\n\n");
	scanf("%d",&x2);
	if(x2==1){
	    printf(">>>>>>�����������޸Ļ�Ա��Ϣ����������Ա���<<<<<<\n");
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
                printf("********** %d�Ż�Ա��Ϣ **********\n\n\n",m2);
                printf("��Ա������%s\n\n",p[i].Member_Name);
                printf("��Ա�Ա�%s\n\n",p[i].Member_Gender);
                printf("��Ա���䣺%d\n\n",p[i].Member_Age);
                k2=i;
                break;
                }
            }
        if(flag2==0){
            printf("\aû�иû�Ա��\n");
            printf("��1�Է��ػ�Ա����ϵͳ\n");
            scanf("%d",&n2);
            system("cls");
            while(n2!=1){
                    printf("\a����������������룡\n");
                    scanf("%d",&n2);
                    }
            system("cls");
            amend_Member();
            }
        printf("��ѡ��\n\n");
        printf(">>>>>> 1.��Ա����\n\n");
        printf(">>>>>> 2.��Ա�Ա�\n\n");
        printf(">>>>>> 3.��Ա����\n\n");
        printf(">>>>>> 5.������ҳ\n\n");
        printf(">>>>>> 6.�˳���Ա�޸�ϵͳ\n\n");
        printf("������һ�����֣�\n");
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
        printf("�������޸�\n");
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
        printf("�޸���Ϣ�ɹ����밴1���˻��û�����ϵͳ��\n");
        fp=fopen("Member.txt","wb");
        fwrite(p,sizeof(RESIDENT),Member_Num,fp);
        fclose(fp);
        scanf("%d",&n2);
        system("cls");
        while(n2!=1){
                printf("\a����������ٴ����룡\n");
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
	printf("\a����������������������Է��أ�\n");
	scanf("%d",&x2);
	system("cls");
	amend_Member();
}//�޸Ļ�Ա

void inquire_Member(){
    int x3;
    printf("**********  ��ѯ��Ա  **********\n\n\n");
    printf("1.��ѯ\n\n");
    printf("2.�˳�\n\n");
    scanf("%d",&x3);
    if(x3==1){
        printf(">>>>>>���������ڲ�ѯ��Ա�������������ѯ�Ļ�Ա���<<<<<<\n");
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
                printf("********** %d�Ż�Ա��Ϣ **********\n\n\n",m3);
                printf("��Ա������%s\n\n",p[i].Member_Name);
                printf("��Ա�Ա�%s\n\n",p[i].Member_Gender);
                printf("��Ա���䣺%d\n\n",p[i].Member_Age);
                printf("��1�Է��ز�ѯϵͳ\n");
                scanf("%d",&n3);
                while(n3!=1){
                    system("cls");
                    puts("\a����������������룡");
                    scanf("%d",&n3);
                    }
                system("cls");
                inquire_Member();
                }
            }
        if(flag3==0){
            printf("\aû�иû�Ա��\n");
            printf("��1�Է��ػ�Ա��ѯϵͳ\n");
            scanf("%d",&n3);
            system("cls");
            while(n3!=1){
                printf("\a����������������룡\n");
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
            printf("\a����������������������Է��أ�\n");
            scanf("%d",&x3);
            system("cls");
            inquire_Member();
}//��ѯ��Ա

void delete_Member(){
    int x4;
    printf("**********  ɾ����Ա  **********\n\n\n");
    printf("1.ɾ��\n\n");
    printf("2.�˳�\n\n");
    scanf("%d",&x4);
    if(x4==1){
        printf(">>>>>>����������ɾ����Ա��Ϣ����������Ա���<<<<<<\n");
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
                printf("******* %d�Ż�Ա��Ϣ *******\n\n",m4);
                printf("��Ա������%s\n\n",p[i].Member_Name);
                printf("��Ա�Ա�%s\n\n",p[i].Member_Gender);
                printf("��Ա���䣺%d\n\n",p[i].Member_Age);
                k4=i;
                }
            }
        if(flag4==0){
            printf("\aû�иû�Ա��\n");
            printf("��1�Է��ػ�Աɾ��ϵͳ\n");
            scanf("%d",&n4);
            system("cls");
            while(n4!=1){
                printf("\a����������ٴ����룡\n");
                scanf("%d",&n4);
                }
            system("cls");
            delete_Member();
            }
        if(flag4==1){
            printf("ȷ��ɾ���û�Ա��Ϣ��\n");
            printf(">>>>>> 1.ȷ��\n");
            printf(">>>>>> 2.ȡ��\n");
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
                printf("ɾ����Ա��Ϣ�ɹ���\n");
                printf("��1���˻ػ�Աɾ��ϵͳ\n");
                scanf("%d",&n4);
                system("cls");
                }
                else delete_Member();
                while(n4!=1){
                    printf("����������ٴ����룡\n");
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
                printf("\a����������������������Է��أ�\n");
                scanf("%d",&x4);
                system("cls");
                delete_Member();
}//ɾ����Ա

  typedef struct HOUSE
{
    int num1;
    int num2;
    int num3;//�����
    int price;
    int type;//1����Ԣ��2������ͨסլ��3�������
    int area;//���
    int user;//��Ա��ų�ʼΪ0
    int flag;//0Ϊ���˹���1Ϊ���˹���
}HOUSE;

void House_Built()
{
     FILE *fp1;
     fp1=fopen("������Ϣ.txt","a+");
     int ch;
     ch=fgetc(fp1);
     if(ch==EOF)
    {fprintf(fp1,"n��¥      n��Ԫ        n��    ��������   ���(m2) �۸�(w) ��Ա��� �������\n");
     fprintf(fp1,"(����:����������1����Ԣ,2������ͨסլ,3�������;���������0������δ����,1�����Ѿ��۳�,2������⣬3�������)");}
     fclose(fp1);
     FILE *fp2;
     fp2=fopen("������Ϣ.txt","a");
     HOUSE house;
     printf(">>�½�����<<\n\n");
     printf("�����뷿��λ��\n");
     printf("(����:�÷���Ϊ1��¥1��Ԫ101��,��������������1 1 101)\n");
     scanf("%d",&house.num1);
     scanf("%d",&house.num2);
     scanf("%d",&house.num3);
     printf("�����뷿������\n");
     printf("(����������1����Ԣ,2������ͨסլ,3�������)\n");
     scanf("%d",&house.type);
     printf("�����뷿�����(��λ:ƽ����)\n");
     scanf("%d",&house.area);
     printf("�����뷿�ݼ۸�(��λ:��)\n");
     scanf("%d",&house.price);
     house.user=0;
     house.flag=0;
     fprintf(fp2,"\n%d\t%d\t%d\t%d\t%d\t%d\t%d %d",house.num1,house.num2,house.num3,house.type,house.area,house.price,house.user,house.flag);
     fclose(fp2);
     printf("������Ϣ�����ɹ�\n");
     printf("..����������һ��,�밴���������..");
     getch();
}

void House_Buy()
{
    printf(">>������<<\n\n");
    FILE *fp1;
    if((fp1=fopen("������Ϣ.txt","r+"))==NULL)
   {printf("����ʧ��,���ȴ���������Ϣ\n");
    exit(1);}
    int i,c1,c2,c3,c4,c5,c6,c7,n1,n2,n3,n4,n5,n6,n7,n8,flag=0;
    printf("��������Ҫ����ķ��ݵ�����\n");
    printf("(����������1����Ԣ,2������ͨסլ,3�������)\n");
    scanf("%d",&c4);
    printf("��������Ҫ����ķ��ݵ����\n");
    printf("(����:�蹺�������Ϊ50-59ƽ,ֻ������50)\n");
    scanf("%d",&c5);
    printf("��������Ҫ����ķ��ݵļ۸�\n");
    printf("(���磺�蹺���ݼ۸�Ϊ10-19��ֻ������10)\n");
    scanf("%d",&c6);
    for(i=0;i<2;i++)
   {fscanf(fp1,"%*[^\n]%*c");}
    while(!feof(fp1))
   {fscanf(fp1,"%d%d%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8);
    if(n4==c4&&(n5>=c5&&n5<c5+10)&&(n6>=c6&&n6<c6+10)&&n8==0)
   {if(flag==0)
   {printf("���������ķ�����Ϣ����:\n");
    printf("***************************************************\n");
    printf("n��¥n��Ԫn�� �������� ���(ƽ��)�۸�(��)\n");
    printf("(����:����������1����Ԣ,2������ͨסլ,3�������)\n");
    flag=1;}
    printf("%d    %d    %d\t%d\t%d\t%d\n",n1,n2,n3,n4,n5,n6);}}
    fclose(fp1);
    FILE *fp2;
    if((fp2=fopen("������Ϣ.txt","r+"))==NULL)
   {printf("����ʧ��,���ȴ���������Ϣ\n");
    exit(1);}
    if(flag==1)
   {printf("***************************************************\n");
    printf("��ѡ���Ա��Ҫ����ķ���\n");
    printf("(����:�÷���Ϊ1��¥1��Ԫ101��,��������������1 1 101)\n");
    scanf("%d",&c1);
    scanf("%d",&c2);
    scanf("%d",&c3);
    printf("�������Ա���\n");
    scanf("%d",&c7);
    for(i=0;i<2;i++)
   {fscanf(fp2,"%*[^\n]%*c");}
    while(!feof(fp2))
   {fscanf(fp2,"%d%d%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8);
    if(c1==n1&&c2==n2&&c3==n3&&n8==0)
   {fseek(fp2,-4,SEEK_CUR);
    fprintf(fp2," %d 1",c7);
    printf("���ݹ���ɹ�\n");
    flag=1;
    break;}}}
    if(flag==0)
    printf("���޷��������ķ���\n");
    printf("..����������һ��,�밴���������..");
    getch();
    fclose(fp2);
}

void House_Search()
{
    printf(">>>������Ϣ��ѯ<<<\n\n");
    FILE *fp;
    if((fp=fopen("������Ϣ.txt","r+"))==NULL)
   {printf("����ʧ��,���ȴ���������Ϣ\n");
    exit(1);}
    int i,c1,c2,c3,n1,n2,n3,n4,n5,n6,n7,n8,flag=0;
    printf("��������Ҫ��ѯ�ķ��ݵ�λ����Ϣ\n");
    printf("(����:�÷���Ϊ1��¥1��Ԫ101��,��������������1 1 101)\n");
    scanf("%d",&c1);
    scanf("%d",&c2);
    scanf("%d",&c3);
    for(i=0;i<2;i++)
   {fscanf(fp,"%*[^\n]%*c");}
    while(!feof(fp))
   {fscanf(fp,"%d%d%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8);
    if(n1==c1&&n2==c2&&n3==c3)
   {if(flag==0)
   {printf("��ѯ�������:\n");
    printf("***************************************************\n");
    printf("n��¥n��Ԫn�� �������� ���(ƽ��)�۸�(��)��Ա��� �������\n");
    printf("(����:����������1����Ԣ,2������ͨסլ,3�������)\n");
    flag=1;}
    printf("%d    %d    %d\t%d\t%d\t%d\t%d\t%d\n",n1,n2,n3,n4,n5,n6,n7,n8);}}
    if(flag==1)
    printf("***************************************************\n");
    if(flag==0)
    printf("���ݲ�����\n");
    printf("..����������һ��,�밴���������..");
    getch();
    fclose(fp);
}

void House_Management_menu()
{
     printf("********************************************\n");
    printf("********************************************\n");
    printf("**                                        **\n");
    printf("**          ��ӭʹ�÷��ݹ���ϵͳ          **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
    printf("1.�½�����\n");
    printf("2.������Ϣ��ѯ\n");
    printf("3.������\n");
    printf("4.������һ��\n");
}

void House_Management()
{
    int choose;
    while(1)
    {
       system("cls");
       House_Management_menu();
       printf("��ѡ��\n");
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
    printf("**          ��ӭʹ����ס����ϵͳ          **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
   printf("��������Ҫ��ѯ�Ļ�Ա���\n");
   int i=0;
   scanf("%d",&i);
   return i;
}
void checkin(int num)
{
    //��ӡ���û������з���
    FILE *fp1=fopen("������Ϣ.txt","a+");
    fscanf(fp1,"%*[^\n]%*c");
    fscanf(fp1,"%*[^\n]%*c");
    int a,b,c,d,e,f,g,h;
    printf(">>>ѡ����ס<<<\n\n");
    printf("����Ϊ���ķ�����Ϣ\n");
    printf("n��¥      n��Ԫ        n��    ��������   ���(m2) �۸�(w)��Ա��� �������\n");
     while(!feof(fp1)){
            fscanf(fp1,"%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
            if(g==num)
   printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a,b,c,d,e,f,g,h);
   }
  printf("�����������в����ķ��ݵı��\n");
  int i,t,r;
  printf("����:�÷���Ϊ1��¥1��Ԫ101��,��������������1 1 101\n");
  scanf("%d %d %d",&i,&t,&r);
  fclose(fp1);
  printf("��������Ҫ���еĲ���\n");
  printf("1.��ס\n");
  printf("2.����\n");
  printf("3.����\n");
  int v;
  scanf("%d",&v);
   FILE *fp2=fopen("������Ϣ.txt","r+");
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
    case 1:printf("��ס�����ѳɹ�\n");
    break;
    case 2:printf("��������ѳɹ�\n");
        break;
    case 3:printf("���ð����ѳɹ�\n");
    break;
}
   printf("����������һ�����밴���������..\n");
   getch();
   system("cls");
}
 void apply()
 {
    char b[20];
    int a,c,d;
    printf(">>>����������ʩ<<<\n\n");
    FILE *fp;
    fp=fopen("������ʩ��Ϣ.txt","r");
    printf("����Ϊȫ��������ʩ��Ϣ\n");
    printf("���\t����\t���������\tʹ�����(0��ʾδʹ�ã�1��������)\n");
    fscanf(fp,"%*[^\n]%*c");
    while(!feof(fp))
   {fscanf(fp,"%d%s%d%d",&a,b,&c,&d);
    printf("%d\t%s\t%d\t%d\n",a,b,c,d);}
    fclose(fp);
    FILE *fp2;
    fp2=fopen("������ʩ��Ϣ.txt","r+");
    printf("��������Ҫ�����������ʩ�ı��\n");
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
           printf("����ɹ�,�����ڿ���ʹ�ø���ʩ\n");
           flag=1;
           break;
       }

   }
   fclose(fp2);
   if(flag==0)
    printf("����ʩ������ʹ��\n");
   printf("����������һ�����밴���������..");
   getch();
   system("cls");
 }
void result()
{
    printf("����ɹ�.\n");
}
void choice(int num)
{
        int i=0;
       while(i!=3)
      {printf("1.ѡ����ס\n");
       printf("2.����������ʩ\n");
       printf("3.����\n");
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
    printf("*************   **************                ��ѡ����\n");
    printf("************     *************\n");
    printf("***********       ************              >>>>>1.��Ա����\n");
    printf("**                         ***\n");
    printf("***       ��ӭʹ��        ****              >>>>>2.���ݹ���\n");
    printf("****                     *****\n");
    printf("*****   ������������    ******              >>>>>3.��ס����\n");
    printf("******                 *******\n");
    printf("*****     ����ϵͳ       *****              >>>>>4.������ʩ�Ŷӹ���\n");
    printf("****                     *****\n");
    printf("***                       ****              >>>>>5.�û�����\n");
    printf("**                         ***\n");
    printf("***********       ************              >>>>>6.�˳�\n");
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
    printf("**       ��ӭʹ�÷�����Ա����ϵͳ         **\n");
    printf("**                                        **\n");
    printf("********************************************\n");
    printf("********************************************\n\n\n");
	printf("1.����������Ա\n");
	printf("2.�޸ķ�����Ա\n");
	printf("3.ɾ��������Ա\n");
	printf("4.���÷������\n");
	printf("5.�鿴������Ա\n");
	printf("6.�˳�ϵͳ\n");
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
			printf("��ӭ�´�ʹ��\n");
			return;
	}
}

void add_Serve(){
	printf("**********  ����������Ա  **********\n\n");
	FILE *fp=fopen("Serve.txt","ab");
	SERVE p;
	printf("����������������Ա���\n");
	scanf("%d",&(p).serve_ID);
	printf("\n\n");
	printf("����������������Ա����\n");
	scanf("%s",(p).serve_name);
	p.customer_Mark=0;
	p.total_Mark=0;
	p.serve_State=0;
	p.customer_ID=0;

	fwrite(&p,sizeof(SERVE),1,fp);
	fclose(fp);
	system("cls");
	printf("�����ɹ���\n��1�����û�����ϵͳ.\n");
	serve_Num++;
	int n;
	scanf("%d",&n);
	while(n!=1){
		printf("\a����������ٴ����룡\n");
		scanf("%d",&n);
	}
	system("cls");
	Serve_Menu();
}

void amend_Serve(){
	printf("**********  �޸ķ�����Ա  **********\n\n");
	printf("��������Ա���\n");

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
		printf("******* %d�ŷ�����Ա��Ϣ *******\n\n");
		printf("������Ա��ţ�%d\n\n",p[i].serve_ID);
	    printf("������Ա������%s\n\n",p[i].serve_name);
	    printf("������Ա���飺%d\n\n",p[i].serve_State);
	    printf("������Ա����%d\n\n",p[i].customer_ID);
	    printf("������Ա���֣�%d\n\n",p[i].customer_Mark);
	    k=i;
	    break;
		}
	}
	if(flag==0){
	  printf("\aû�и÷�����Ա��\n");
	  printf("��1���˻��û�����ϵͳ��\n");
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a����������ٴ����룡\n");
		scanf("%d",&n);
	  }
	     system("cls");
     Serve_Menu();
    }
	printf("�����������޸ĵ���Ϣ\n");
	printf(">>> 1��������\n\n");
	printf(">>> 2��������\n\n");
	scanf("%d",&n2);
	printf("�������޸�\n") ;
	if(n2==1){
		scanf("%d",&p[k].serve_State);
	}
	else{
		scanf("%d",&p[k].customer_Mark);
	}
	fp=fopen("Serve.txt","wb");
	fwrite(p,sizeof(SERVE),serve_Num,fp);
	fclose(fp);
	printf("�޸ĳɹ�����1���˻��û�����ϵͳ\n");
	scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a����������ٴ�����\n");
		scanf("%d",&n);
	  }
	     system("cls");
    Serve_Menu();
}

void delete_Serve(){

	printf("**********  ɾ��������Ա  **********\n\n\n");

	printf("����������ɾ������Ա��ţ�\n");

	FILE *fp=fopen("Serve.txt","rb+");

	if(fp==NULL)
	  printf("��ʧ��\n");
	int m,n,k,n2,flag;
	SERVE p[10];
	scanf("%d",&m);
	system("cls");
	fread(p,sizeof(SERVE),serve_Num,fp);
	fclose(fp);
	for(i=0;i<serve_Num;i++){
		if(p[i].serve_ID==m){
			flag=1;
		printf("******* %d��*******\n\n");
		printf("������Ա��ţ�%d\n\n",p[i].serve_ID);
	    printf("������Ա������%s\n\n",p[i].serve_name);
	    printf("������Ա���飺%d\n\n",p[i].serve_State);
	    printf("������Ա����%d\n\n",p[i].customer_ID);
	    printf("������Ա���֣�%d\n\n",p[i].customer_Mark);
	    k=i;
	    break;
		}
	}
	if(flag==0){
	  printf("\aû�и÷�����Ա\n");
	  printf("��1���˻��û�����ϵͳ��\n");
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a����������ٴ�����\n");
		scanf("%d",&n);
	  }
	     system("cls");
   Serve_Menu();
    }
    printf("�Ƿ�ɾ������Ա��Ϣ��\n");
    printf("1.ȷ��\n");
    printf("2.ȡ��\n");
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
	printf("ɾ����Ա��Ϣ�ɹ���\n");
	printf("��1���˻��û�����ϵͳ��\n");
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("����������ٴ����룡\n");
		scanf("%d",&n);
	  }
	     system("cls");
   Serve_Menu();
}

void set_Serve(){
	int k;
	printf("********** �����������  **********\n\n\n");
	printf("�����������Ա���.\n");
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
	  	printf("\n\n**********  ������Ա��Ϣ  **********\n\n\n");
	    printf("������Ա��ţ�%d\n\n",p[i].serve_ID);
	    printf("������Ա������%s\n\n",p[i].serve_name);
	    printf("������Ա���飺%d\n\n",p[i].serve_State);
	    printf("������Ա����%d\n\n",p[i].customer_ID);
	    printf("������Ա���֣�%d\n\n",p[i].customer_Mark);
	    k=i;
       }
      }
      if(flag==0)
        printf("\a����Ա��Ų�����\n");
      else{
		printf("������Ҫ���õĶ�����:\n");
      	scanf("%d",&p[k].customer_ID);
      	fp=fopen("serve.txt","wb");
      	fwrite(p,sizeof(SERVE),serve_Num,fp);
      	fclose(fp);
      	system("cls");
      	printf("���÷������ɹ�\n");
	  }

      printf("��1���˻��û�����ϵͳ\n");
	  int n;
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a����������ٴ�����\n");
		scanf("%d",&n);
	  }
	     system("cls");
    Serve_Menu();

  }


void check_Serve(){
	printf("**********  ������Ա��ѯ  **********\n\n\n");
	printf("�����������Ա�ı��\n");
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
	  	printf("\n\n**********  ������Ա��Ϣ  **********\n\n\n");
	    printf("������Ա��ţ�%d\n\n",p[i].serve_ID);
	    printf("������Ա������%s\n\n",p[i].serve_name);
	    printf("������Ա���飺%d\n\n",p[i].serve_State);
	    printf("������Ա����%d\n\n",p[i].customer_ID);
	    printf("������Ա���֣�%d\n\n",p[i].customer_Mark);
       }
      }
      if(flag==0)
        printf("\a���Ϊ�գ�\n");
      printf("��1���˻��û�����ϵͳ��\n");
	  int n;
	  scanf("%d",&n);
	  system("cls");
	  while(n!=1){
		printf("\a����������ٴ����룡\n");
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
