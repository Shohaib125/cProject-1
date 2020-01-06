#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct emp
{
	int id;
	char name[20];
	int salary;
};
void append();
void display();
void displayAll();
void modify();
void del();
void search();
void rname();
void rremove();
char mygetch();
char fname[]={"new_mydb.dat"};
int main()
{
	int ch;
	while(1)
	{
		system("cls");
	printf("---------Employee Management System------------\n \n");
	printf("1.Append \n \n");
	printf("2.Modify \n \n");
	printf("3.Delete \n \n");
	printf("4.Search \n \n");
	printf("5.Display \n \n");
	printf("6.DisplayAll \n \n");
	printf("7.Rename \n \n");
	printf("8.Delete file\n \n");
	printf("0.Exit \n \n");
	printf("----------------------------------------\n \n");
	printf("\n Please enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:append();
		break;
		case 2:modify();
		break;
		case 3:del();
		break;
		case 4:search();
		break;
		case 5:display();
		break;
		case 6:displayAll();
		break;
		case 7:rname();
		break;
		case 8:rremove();
		break;
		case 0:exit(0);
	}
	mygetch();
}
return 0;
}
void append()
{
	FILE *fp;
	struct emp t1;
	fp=fopen(fname,"ab");
	printf("\nEnter ID:");
	scanf("%d",&t1.id);
	printf("\nEnter name:");
	scanf("%d",&t1.name);
	printf("\nEnter salary:");
	scanf("%d",&t1.salary);
	fwrite(&t1,sizeof(t1),1,fp);
	fclose(fp);	
}
void rname()
{
	char name[20];
	printf("Enter the new file name-");
	fflush(stdin);
	scanf("%[^\n]",name);
	rename(fname,name);
	strcpy(fname,name);
}
void rremove()
{
	FILE *fp,*fp1;
	struct emp t;
	char name[20];
	char val[20];
	printf("\n Do you  want to make copy of it(Y / N):");
	scanf("%s",&val);
	if(strcmp(val,"Y")==0)
	{
		printf("\n Entetr the new file name-");
		fflush(stdin);
		scanf("%[^\n]",name);
		fp=fopen(name,"wb");
		fp1=fopen(name,"rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
		    {
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		remove(fname);
		strcpy(fname,name);
		}
		else
		{
			remove(fname);
		}
}
void modify()
{
	FILE *fp,*fp1;
	struct emp t,t1;
	int id,found=0,count=0;
	fp=fopen(fname,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\n Enter the emp id you want to modify-");
	scanf("%d",&id);
	while(1)
	{
		fread(&t,sizeof(t),1,fp1);
		if(feof(fp1))
		{
			break;
		}
		if(t.id==id)
		{
			found=1;
			printf("Enter the employee id-");
			scanf("%d",&t.id);
			fflush(stdin);
			printf("Enter the employee name-");
			scanf("%s",&t.name);
			printf("Enter the employee salary-");
			scanf("%d",&t.salary);
		fwrite(&t,sizeof(t),1,fp1);
    	}
		else
		{
			fwrite(&t,sizeof(t),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);	
    if(found==0)
    {
    	printf("Sorry no record found");
	}
	else 
	{
		fp=fopen(fname,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
    fclose(fp1);
}

void display()
{
	FILE *fp;
	struct emp t;
	int id,found=0;
	fp=fopen(fname,"rb");
	printf("\nEnter the emp ID:");
	scanf("%d",&id);
	while(1)
	{
		fread(&t,sizeof(t),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(t.id==id)
		{
			found=1;
			printf("----------------------------------------\n \n");
			printf("\t\t Employee details %d\n\n",t.id);
			printf("----------------------------------------\n \n");
			printf("Name\tSalary\n\n");
			printf("%s \t",t.name);
			printf("%d\t\n\n",t.salary);
			printf("----------------------------------------\n \n");
		}
	}
	if(found==0)
	{
		printf("\n Sorry No Record Found");
	}
	fclose(fp);
}
void search()
{
	FILE *fp;
	struct emp t;
	int id,found=0;
	char name[20];
	fp=fopen(fname,"rb");
	printf("\n Enter the employee name");
	scanf("%s",&name);
	while(1)
	{
		fread(&t,sizeof(t),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(strcmp(name,t.name))
		{
			printf("\n=======================================================================\n\n");
			printf("\t\t Employee Details of %d \n\n",t.id);
			printf("\n=======================================================================\n\n");
			printf("Name\tSalary\t\n\n");
			printf("%s\t",t.name);
			printf("%d\t\t",t.salary);
			printf("\n=======================================================================\n\n");
		}
	}
	if(found==0)
	{
		printf("\n Sorry No Record Found");
	}
	fclose(fp);
}
void displayAll()
{
	FILE *fp;
	struct emp t;
	fp=fopen(fname,"rb");
    printf("\n=======================================================================\n\n");
    printf("\t\t All Employee Details\n\n");
    printf("\n=======================================================================\n\n");
	printf("Name\tSalary\t\n\n");
    while(1)
	{
		fread(&t,sizeof(t),1,fp);
		if(feof(fp))
		{
			break;
    	}
    	printf("%d\t",t.id);
    	printf("%s\t",t.name);
    	printf("%d\t\n\n",t.salary);
	}
	printf("\n=======================================================================\n\n");
    fclose(fp);
}
void del()
{
}
char mygetch()
{
	char val;
	char rel;
	scanf("%c",&val);
	scanf("%c",&rel);
	return(val);
}
