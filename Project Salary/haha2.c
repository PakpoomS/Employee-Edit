#include<stdio.h>
int main()
{
FILE *fp = fopen("employee.dat", "w");
int number;
int i;
int n=1;
int manu;
struct staff{
int id,age,numberofworkingday;
char pre,name[60],bd,address,sex,position,status;
float salary,emoluments,overtimepay,bonus,totalsummary,result,totalsalary,tax;
}staffs[99];
do{
	printf("Employee Database\n");	
	printf("1.Fill in information\n");
	printf("2.Searching\n");
	printf("3.End\n");
	printf("Input Number : ");
	scanf("%d",&manu);
		if (manu==1)
			{
			printf("Enter Number :");
			scanf("%d",&number);
			for (i=0;i<number;i++)
			{
				printf("ID :");
				scanf("%d",&staffs[i].id);
				fprintf(fp,"\n%d",staffs[i].id);
				
				/*printf("Pre :");
				scanf("%s",&staffs[i].pre);
				fprintf(fp,"\n%s",staffs[i].pre);*/
				
				printf("Name :");
				scanf("%s",&staffs[i].name);
				fprintf(fp,"\n%s",staffs[i].name);
				
				printf("BD :");
				scanf("%s",&staffs[i].bd);
				fprintf(fp,"\n%s",staffs[i].bd);
				
				printf("Address :");
				scanf("%s",staffs[i].address);
				fprintf(fp,"\n%s",staffs[i].address);
				printf("Age :");
				scanf("%d",&staffs[i].age);
				fprintf(fp,"\n%d",staffs[i].age);
				printf("Sex :");
				scanf("%s",staffs[i].sex);
				fprintf(fp,"\n%s",staffs[i].sex);
				printf("Position :");
				scanf("%s",staffs[i].position);
				fprintf(fp,"\n%s",staffs[i].position);
				printf("Status :");
				scanf("%s",staffs[i].status);
				fprintf(fp,"\n%s",staffs[i].status);
				printf("Salary :");
				scanf("%f",&staffs[i].salary);
				fprintf(fp,"\n%f",staffs[i].salary);
				printf("Bonus :");
				scanf("%f",&staffs[i].bonus);
				fprintf(fp,"\n%f",staffs[i].bonus);
				printf("Emoluments :");
				scanf("%f",&staffs[i].emoluments);
				fprintf(fp,"\n%f",staffs[i].emoluments);
				printf("Overtime pay :");
				scanf("%f",&staffs[i].overtimepay);
				fprintf(fp,"\n%f",staffs[i].overtimepay);
				printf("Number of working days :");
				scanf("%d",&staffs[i].numberofworkingday);
				fprintf(fp,"\n%d",staffs[i].numberofworkingday);
				printf("Tax :");
				scanf("%f",&staffs[i].tax);
				fprintf(fp,"\n%f",staffs[i].tax);
				printf("Total Salary :");
				scanf("%f",&staffs[i].totalsalary);
				fprintf(fp,"\n%f",staffs[i].totalsalary);
				printf("Result :"); 
				scanf("%f",&staffs[i].result);
				fprintf(fp,"\n%f",staffs[i].result);
				printf("Total Summary :");
				scanf("%f",&staffs[i].totalsummary);
				fprintf(fp,"\n%f",staffs[i].totalsummary);	
				getch();
			}
			}
			else if (manu==3)
				{
					n=0;
				}
			
}while(n!=0);
}
