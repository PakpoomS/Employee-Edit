#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#define tax 7
#define daywork 26.00000
#define hours_of_ot 40
	 
	static const char FILE_NAME[] = "employee.csv";
	
	typedef struct emp{
		char id[30];
		char first_name[100];
		char last_name[30];
		char bd[30];
		char address[100];
		char age[20];
		char sex[20];
		char position[10];
		char status[20];
		char salary[15];	
	}EmpData;
	
	EmpData getData(char data[]);
	void showEmp(EmpData pdata);
	void writeDataEdit (EmpData wdata[]);
	EmpData AddData(char data[]);
	EmpData EditData(char data[]);
	void writeDataAdd(EmpData wdata, FILE *pw);
	
int main(){
	
	FILE *fp;
	int i=0,ans=0,rec=0,erec;
	int daytotal,deducttotalm,salary_i,ot,salary_ot;
	float  dayofmoney,total_tax,total_income,net_income;
	char buffer[250],edit[50],salary_c[20];	
	char sea[50];
	char conti;
do{	
	rec=0;
	i=0;
	system("cls");
	EmpData data[20]; 
	
	fp=fopen(FILE_NAME,"r");
	
	if(fp == NULL){
		printf("Cannot open file %s",FILE_NAME);
	}
	
	printf("\t\t************ Base Information Employee ***************");
	printf("\n");
	do{
		if(fgets(buffer, 250, fp) != NULL){
			data[i] = getData(buffer);
			printf(" [%d] ",i+1);
			showEmp(data[i]);
			i++;
		} else 
			break;
		
	}while(1);

	fclose(fp);
	
	printf(" ----------------------------------------------------------------------------\n");
	printf("\n\t\t\t\t<< List Select >>\n");
	printf(" \t[1] Add \n");
	printf(" \t[2] Edit\n");
	printf(" \t[3] Delete\n");
	printf(" \t[4] Calculator Employee\n");
	printf(" \t[5] Search Employee\n\n");
	printf(" ---------------------------------------------------------------------------\n");
	do{
	printf(" \t\t\t Enter Number : ");
	scanf("%d",&ans);
	}while(ans<1 || ans>5);
	
	if(ans==1){	
	printf("\n\t");
	FILE *fp;
		fp=fopen(FILE_NAME,"a+");
		
		data[i] = AddData(buffer);
		writeDataAdd(data[i],fp);
		rewind(fp);
				
		i=0;
		printf("\n");
	do{
		if(fgets(buffer, 250, fp) != NULL){
			data[i] = getData(buffer);
			printf(" [%d]",i+1);
			showEmp(data[i]);
			i++;
		} else
			break;
		
	}while(1);
	
	} else if(ans==2){
	do{
			printf(" Choose record (1-%d): ",i);
			scanf("%d", &rec);
		} while(rec < 1 || rec > i);
		printf("\n -------------------------------\n");

	rec = rec - 1;	
	
	printf(" [%d] ",rec+1);
	showEmp(data[rec]);
		
	printf(" -------------------------------\n");	
	printf("\n\t** Edit Record **\n\n");
	printf(" FILL [1]  ID EMP\n");
	printf(" FILL [2]  Firstname\n");
	printf(" FILL [3]  Lastname\n");
	printf(" FILL [4]  Birthday\n");
	printf(" FILL [5]  Address\n");
	printf(" FILL [6]  Age\n");
	printf(" FILL [7]  Gender\n");
	printf(" FILL [8]  Position\n");
	printf(" FILL [9]  Status\n");
	printf(" FILL [10] Salary\n");
	do{
		printf("\n Choose fill for Edit [ Exit : 0 ]: ");
		scanf("%d",&erec);

		if(erec == 1){
			printf("\n ID Emp: %s", data[rec].id);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].id, edit);
		} else if(erec == 2){
			printf("\n Firstname: %s", data[rec].first_name);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].first_name, edit);
		} else if(erec == 3){
			printf("\n Lastname : %s", data[rec].last_name);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].last_name, edit);
		} else if (erec == 4){
			printf("\n Birthday: %s", data[rec].bd);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].bd, edit);
		} else if (erec == 5){
			printf("\n Address: %s", data[rec].address);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].address, edit);
		} else if (erec == 6){
			printf("\n Age: %s", data[rec].age);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].age, edit);
		} else if (erec == 7){
			printf("\n Gender : %s", data[rec].sex);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].sex, edit);
		} else if (erec == 8){
			printf("\n Position: %s", data[rec].position);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].position, edit);
		} else if (erec == 9){
			printf("\n Status: %s", data[rec].status);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].status , edit);
		} else if (erec == 10){
			printf("\n Salary: %s", data[rec].salary);
			printf("\n Edit: ");
			scanf("%s", edit);
			strcpy(data[rec].salary, edit);
		} else if (erec == 0) {
			writeDataEdit(data);
			printf("\n [%d] ",rec+1);
			showEmp(data[rec]);
			break;
		}
			
	} while(1);
	//fclose(fp);
   }else if (ans == 3){
		do{
			printf(" Choose record (1-%d): ",i);
			scanf("%d", &rec);
		} while(rec < 1 || rec > i);
		printf("\n -------------------------------\n");

		//strcpy(data[rec], "Delete");
			rec = rec - 1;
			strcpy(data[rec].id, "-");
			strcpy(data[rec].first_name, "-");
			strcpy(data[rec].last_name, "-");
			strcpy(data[rec].bd, "-");
			strcpy(data[rec].address, "-");
			strcpy(data[rec].age, "-");
			strcpy(data[rec].sex, "-");
			strcpy(data[rec].position, "-");
			strcpy(data[rec].status , "-");
			strcpy(data[rec].salary, "-");			
			writeDataEdit(data);
			printf("\n [%d] ",rec+1);
			showEmp(data[rec]);	
	} 
	else if (ans == 4){
	printf("------------Calcurator Employee -----------------");
		do{
			printf(" \nChoose record (1-%d): ",i);
			scanf("%d", &rec);
		} while(rec < 1 || rec > i);
		rec = rec - 1;	
		printf("\n -------------------------------\n");
		strcpy(salary_c,data[rec].salary);
		salary_i=atoi(salary_c);
		printf("Monney_Max : %d",salary_i);
		printf("\n\tDay Of Work : ");
		scanf("%d",&daytotal);
		printf("\n\tWork of OT (Hours) : ");
		scanf("%d",&ot);
		salary_ot = hours_of_ot*ot;
		dayofmoney = salary_i/daywork;
		total_income = daytotal*dayofmoney;
		total_income = total_income+salary_ot;
		printf("\tTotal Income = %f",total_income);
		
		total_tax = total_income*tax;
		total_tax = total_tax/100;
		
		printf("\n\tChang Tax 7 per  : %f ",total_tax);
		net_income = total_income-total_tax;
		
		printf("\n\tNet Income = %.2f",net_income);
		
}else if (ans == 5){
	printf("\n\t\t----------------------------------------");
	printf("\n\t                     Search Employee             ");
	printf("\n\t\t----------------------------------------");
		do{
		i=0;
		printf("\n\n \t Enter Firstname,Lastname or ID Employee To Search : ",sea);
		scanf("%s",&sea);	
		if(strcmp(sea,data[i].first_name) && strcmp(sea,data[i].last_name) && strcmp(sea,data[i].id) != 0 ){
			printf("\n \t Not found please try agian >>> ");
			i++;
		}
		}while(strcmp(sea,data[i].first_name) && strcmp(sea,data[i].last_name) && strcmp(sea,data[i].id) != 0 );
		printf("\n ------ Found -------- ");
		printf("\n");
		showEmp(data[i]);

}	
	conti=getchar();
	printf("\n\n Do you want Continue ? [ Yes : Y / No : Anykey] : ");
	conti=getchar();
	}while(conti == 'Y' || conti == 'y');

return 0;
}
void showEmp(EmpData pdata){
	printf(":: Emp ::\n");
	printf("\n     ID EMP    : %s",pdata.id);
	printf("\n     Firstname : %s",pdata.first_name);
	printf("\n     Lastname  : %s",pdata.last_name);
	printf("\n     Birtday   : %s",pdata.bd);
	printf("\n     Address  : %s",pdata.address);
	printf("\n     Age       : %s",pdata.age);
	printf("\n     Gender     : %s",pdata.sex);
	printf("\n     Position  : %s",pdata.position);
	printf("\n     Status     : %s",pdata.status);
	printf("\n     Salary     : %s",pdata.salary);
	printf("\n");
	
}
EmpData getData(char data[]){
	EmpData pdata;
	
	char *p;
	
	p = strtok(data,",");
	strcpy(pdata.id, (p != NULL) ? p : "-");
	
	p = strtok(NULL,",");		
	strcpy(pdata.first_name, (p != NULL) ? p : "-");
		
	p = strtok(NULL, ",");	
	strcpy(pdata.last_name, (p != NULL) ? p : "-");
		
	p = strtok(NULL,",");
	strcpy(pdata.bd, (p != NULL) ? p : "-");	
	
	p = strtok(NULL,",");
	strcpy(pdata.address, (p != NULL) ? p : "-");	
		
	p = strtok(NULL,",");
	strcpy(pdata.age, (p != NULL) ? p : "-");
	
	p = strtok(NULL,",");
	strcpy(pdata.sex, (p != NULL) ? p : "-");
	
	p = strtok(NULL,",");
	strcpy(pdata.position, (p != NULL) ? p : "-");
	
	p = strtok(NULL,",");
	strcpy(pdata.status, (p != NULL) ? p : "-");
	
	p = strtok(NULL,",");
	strcpy(pdata.salary, (p != NULL) ? p : "-");
	
	return pdata;
}

EmpData AddData(char data[]){
	
	FILE *fp;
	fp=fopen(FILE_NAME,"a+");
	
	EmpData Adata;
	
	fseek(fp, 0, 2);
	
	printf("\n -------------------------------\n");	
	printf("\n\t*** Add New Record ***\n\n");
	printf(" ID Emp : ");
	scanf("%s",Adata.id);
	printf(" Firstname: ");
	scanf("%s",Adata.first_name);
	printf(" Lastname: ");
	scanf("%s",Adata.last_name);
	printf(" Birtday: ");
	scanf("%s",Adata.bd);
	printf(" Address: ");
	scanf("%s",Adata.address);
	printf(" Age : ");
	scanf("%s",Adata.age);
	printf(" Gender: ");
	scanf("%s",Adata.sex);
	printf(" Position: ");
	scanf("%s",Adata.position);
	printf(" Status: ");
	scanf("%s",Adata.status);
	printf(" Salary: ");
	scanf("%s",Adata.salary);
	printf("\n -------------------------------\n");

	return Adata;
}

void writeDataEdit (EmpData wdata[]){
	
	int i = 0, close;
	FILE *fw;
	
	fw = fopen(FILE_NAME, "w");
	
	for (i = 0; i < 9; i++) {
		fprintf(fw, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", wdata[i].id,wdata[i].first_name,wdata[i].last_name,wdata[i].bd,wdata[i].address,wdata[i].age,wdata[i].sex,wdata[i].position,wdata[i].status,wdata[i].salary);
	}
	close = fclose(fw);
	
}

void writeDataAdd (EmpData wdata, FILE *pw){
	fprintf(pw, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", wdata.id,wdata.first_name,wdata.last_name,wdata.bd,wdata.address,wdata.age,wdata.sex,wdata.position,wdata.status,wdata.salary);
}

