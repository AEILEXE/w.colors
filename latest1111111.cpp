#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define BLANK " "
char blank[] = BLANK;

#include <time.h> //RANDOM COLOR 
#include <windows.h> //TEXT COLOR

void setRandomTextColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int textColor = rand() % 15 + 1;    // Random text color (1-15)
    SetConsoleTextAttribute(hConsole, textColor);
}

struct Student{
	struct Personal{
		char id[12];
		char first_Name[30];
		char middle_Name[30];
		char last_Name[30];
		
		char address[50];
		char birthdate[11];
		int age;
		char gender[5]; //m/f
		
		char phone_Number[12];
		char email_Address[30];
		
		char mother_First_Name[30];
		char mother_Middle_Name[30];
		char mother_Last_Name[30];
		char mother_Occupation[30];
	
		char father_First_Name[30];
		char father_Middle_Name[30];
		char father_Last_Name[30];
		char father_Occupation[30];
		
		char guardian_Number[12];
	}per;
	
	struct Documents{
		char has_BirthCertificate;
		char has_MarriageContract;
		char has_Diploma;
		char has_Form137;
		char has_ReportCard;
	}doc;
	
	struct Enrollment{
		int strand;  // 0.STEM 1.HUMSS 2.ABM 3.GAS
		int yearlvl; // 11 = 11, 12=12
		int semester; // 1 = first sem, 2 = second sem.
		int section; // 1 , 2
	}enr;
	
	struct Payment{
		float outstandingbal;
	}pay;
	
	struct flags{
		int isEnrolled;
	}flg;
};
struct Student stu;
char choice;

void pause(){
	printf("\n");
	system("pause");
	
}
void continue_Choice(char cntChoice){
	choice = cntChoice;
	return;
}
void clear_Screen(){
	system("cls");
	return;
}
void call_Error(int mode){
	  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	  srand(time(NULL));//kaya nagiiba yung color
	switch (mode){
		case 1:
			 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			 printf("\nError Cannot write to file.");
			break;
		case 6:
			 SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			 printf("This student is already enrolled");
			break;
		default:
			break;
	}
}
char print_Modal(char header[], int type){
	int c, i;
	switch(type) {
		case 1:
			setRandomTextColor();
			for(i = 0; i <95 ; i++ )printf("=");printf("\n");
			setRandomTextColor();
			for(i = 0; i <95 ; i++ ){if(i < 2)printf("|");else if( i > 92)printf("|");else printf("%s", blank);} printf("\n");
			setRandomTextColor();
			c = ceil(45  - (strlen(header) / 2)); printf("||");for(i = 0; i < c ; i++ )printf(" "); printf(header);  for(i = 0; i < c ; i++ )printf("%s", blank);printf("||\n");
			setRandomTextColor();
			for(i = 0; i <95 ; i++ ){if(i < 2)printf("|");else if( i > 92)printf("|");else printf("%s", blank);} printf("\n");
			setRandomTextColor();
			for(i = 0; i <95 ; i++ )printf("=");printf("\n");
		break;
		
		case 2: 
			setRandomTextColor();
			c = ceil(45  - (strlen(header) / 2)); printf("==");for(i = 0; i < c ; i++ )printf(" "); printf(header);  for(i = 0; i < c ; i++ )printf("%s", blank);printf("==\n\t\t\t\t\t>");
		break;
	}
}

// no more issues 
void menu_Registration(){
	 srand(time(NULL));//kaya nagiiba yung color
	system("cls");
	setRandomTextColor();
	print_Modal("Registration ", 1);
	
	char gender;
	char menu_Choice;
	
	FILE *fpointer;
	fpointer = fopen("record.txt", "ab+");
	
	if(fpointer == NULL){
		call_Error(1);
	}else{
		setRandomTextColor();
		print_Modal("Student ID ex.[123456789000]:", 2);gets(stu.per.id);
		setRandomTextColor();
		print_Modal("Students First Name:", 2);gets(stu.per.first_Name);
		setRandomTextColor();
		print_Modal("Students Middle Name:", 2);gets(stu.per.middle_Name);
		setRandomTextColor();
		print_Modal("Students Last Name:", 2);gets(stu.per.last_Name);
		setRandomTextColor();
		print_Modal("Address:", 2);gets(stu.per.address);
		setRandomTextColor();
		print_Modal("Birthdate ex.[MM/DD/YYYY]:", 2);gets(stu.per.birthdate);
		setRandomTextColor();
		print_Modal("Age:", 2);scanf("%i", &stu.per.age);getchar(); // ??? gumagana to idk why
		setRandomTextColor();
		print_Modal("Gender [male/female]:", 2);gets(stu.per.gender);
		setRandomTextColor();
		print_Modal("Phone Number ex.[09123456789]:", 2);gets(stu.per.phone_Number);
		setRandomTextColor();
		print_Modal("Email Address:", 2);gets(stu.per.email_Address);
		setRandomTextColor();
		print_Modal("Mother's First Name:", 2);gets(stu.per.mother_First_Name);
		setRandomTextColor();
		setRandomTextColor();
		print_Modal("Mother's Middle Name:", 2);gets(stu.per.mother_Middle_Name);
		setRandomTextColor();
		print_Modal("Mother's Last Name:", 2);gets(stu.per.mother_Last_Name);
		setRandomTextColor();
		print_Modal("Fathers's First Name:", 2);gets(stu.per.father_First_Name);
		setRandomTextColor();
		print_Modal("Fathers's Middle Name:", 2);gets(stu.per.father_Middle_Name);
		setRandomTextColor();
		print_Modal("Mother's Last Name:", 2);gets(stu.per.mother_Last_Name);
		setRandomTextColor();
		print_Modal("Guardians' Phone Number ex.[09123456789]:", 2);gets(stu.per.guardian_Number);
		setRandomTextColor();
		print_Modal("Do you want to save this student to the database? [y/n]", 2);menu_Choice = getche();

		if(menu_Choice != 'n'){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				if(fwrite(&stu, sizeof(stu), 1, fpointer) == 1){printf("\nStudent successfuly added to database.\n");
				
		setRandomTextColor();
				print_Modal("Do you want to continue to Enrollment? [y/n]", 2);menu_Choice = getch();
					if(menu_Choice == 'y'){continue_Choice('2');}
				}else{call_Error(1);}
		}else{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		 printf("\nStudent not added to database.");
		continue_Choice('0');;
		}
	}
	
	fclose(fpointer);
	fflush(fpointer);
	system("pause");
	return;
}

// no error checking come back to this
void menu_Enrollment(){
	 srand(time(NULL));//kaya nagiiba yung color
	system("cls");
	setRandomTextColor();
	print_Modal("Enrollment ", 1);
	
	char search_Student_Id[12];
	int bolis_Found = 0;
	char menu_Choice;
	char strands[][10] = {"STEM", "HUMSS", "ABM", "GAS"};
	char semester[3] = {'X', 'A', 'B'};
	
	if(choice != '2' && choice != '2'){
		setRandomTextColor();
		print_Modal("Enter the ID of Student: ", 2);gets(search_Student_Id);
	}else{strcpy(search_Student_Id, stu.per.id);};

	FILE *fpointer;
	fpointer = fopen("record.txt", "rb+");
	while(fread(&stu, sizeof(stu), 1, fpointer) == 1){
		if(strcmp(search_Student_Id, stu.per.id) == 0){
			bolis_Found = 1;break;}}
	
	if(bolis_Found == 1){
	setRandomTextColor();
		print_Modal("Student Name:", 2);printf("%s, %s %s\n", stu.per.last_Name, stu.per.first_Name, stu.per.middle_Name);
	setRandomTextColor();
		print_Modal("Address: ", 2);printf("%s\n", stu.per.address);
	setRandomTextColor();
		print_Modal("Birthdate: ", 2);printf("%s\n", stu.per.birthdate);
	setRandomTextColor();
		print_Modal("Age: ", 2);printf("%i\n", stu.per.age);
		
		if(stu.flg.isEnrolled == 1){
	setRandomTextColor();	
		print_Modal("STRAND:", 2);printf("%s\n", strands[stu.enr.strand]);
	setRandomTextColor();	
		print_Modal("SEMESTER:", 2);printf("%c\n", semester[stu.enr.semester]);
	setRandomTextColor();	
		print_Modal("YEAR:" , 2);printf("%i\n", stu.enr.yearlvl);
	setRandomTextColor();	
		print_Modal("SECTION: ", 2);printf("%i\n", stu.enr.section);
		call_Error(6);
		continue_Choice('0');
		
		}else{
			
	setRandomTextColor();
			print_Modal("Enter strand: [0 = STEM / 1 = HUMSS / 2 = ABM / 3 = GAS]:", 2);scanf("%i", &stu.enr.strand);
	setRandomTextColor();	
			print_Modal("Enter year level: [11 / 12]",2);scanf("%i", &stu.enr.yearlvl);
	setRandomTextColor();	
			print_Modal("Enter semester: [1 / 2]",2);scanf("%i", &stu.enr.semester);
	setRandomTextColor();	
			print_Modal("Enter Section: [1 / 2]",2);scanf("%i", &stu.enr.section);
	setRandomTextColor();	
			print_Modal("Do you want to enroll now? [y/n]",2);menu_Choice = getche();
			if(menu_Choice == 'y'){
				 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				continue_Choice('3');
				stu.pay.outstandingbal = 26731;
				stu.flg.isEnrolled = 1;
				fseek(fpointer, -sizeof(stu), SEEK_CUR);
				fwrite(&stu, sizeof(stu), 1, fpointer);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("\nStudent enrolled successfully");
			}else{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("\nStudent not enrolled.");continue_Choice('0');}
		}
	}else{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	 printf("No records found!");continue_Choice('0');}
	
	
	fclose(fpointer);
	fflush(fpointer);
	pause();
	return;
}





void menu_Payment(){
	clear_Screen();
	
	char search_Student_Id[12];
	int bolis_Found = 0;
	char menu_Choice = 0;
	float receiveAmnt;
	
	char strands[][10] = {"STEM", "HUMSS", "ABM", "GAS"};
	char semester[3] = {'X', 'A', 'B'};
	
	printf("Enter the ID of Student: ");gets(search_Student_Id);
	
	FILE *fpointer;
	fpointer = fopen("record.txt", "rb+");
	while(fread(&stu, sizeof(stu), 1, fpointer) == 1){
		if(strcmp(search_Student_Id, stu.per.id) == 0){
			bolis_Found = 1;
			break;
		}
	}
	
	if(bolis_Found == 1){
		printf("Student is found");
		printf("\nStudent Name: %s, %s %s", stu.per.last_Name, stu.per.first_Name, stu.per.middle_Name);
		printf("\nAddress: %s", stu.per.address);
		printf("\nBirthdate: %s", stu.per.birthdate);
		printf("\nAge: %i", stu.per.age);
		
		printf("\nSTRAND: %s", strands[stu.enr.strand] );
		printf("\nSEMESTER: %c", semester[stu.enr.semester]);
		printf("\nYEAR: %i", stu.enr.yearlvl);
		printf("\nSECTION: %i", stu.enr.section);
		
		
	}
	
	
	printf("\n*Miscellaneous Fees*\nLearning Management Fee             = PHP 850\nMedical Services Fee                = PHP 557\nRegistration Fee                    = PHP 749\nGuidance and Counseling Fee         = PHP 642\nManangement Information System Fee  = PHP 1,079\nLibrary Fee                         = PHP 350\n*Tuition Fee*\nLaboratory Fee                      = PHP 3,342\nSemester Fee (Gened)                = PHP 11,323\nSemester Fee (Specialized)          = PHP 7,839");
	printf("\n\nGRAND TOTAL = PHP 26,731\n");
	print_Modal("Outstanding Balance: ", 2);
	printf("%.2f\n", stu.pay.outstandingbal);
	print_Modal("Receive Amount:  ", 2);scanf("%f", &receiveAmnt);
	print_Modal("Change: ", 2);
	if(receiveAmnt > stu.pay.outstandingbal){
		printf("%.2f\n", receiveAmnt-stu.pay.outstandingbal);
		stu.pay.outstandingbal = 0;
	}else{
		printf("No change [%.2f Credited to account]\n", receiveAmnt);
		stu.pay.outstandingbal -= receiveAmnt;
		print_Modal("Outstanding Balance: ", 2);
		printf("%.2f", stu.pay.outstandingbal);}
	
	fseek(fpointer, -sizeof(stu), SEEK_CUR);
	fwrite(&stu, sizeof(stu), 1, fpointer);
	
	fclose(fpointer);
	fflush(fpointer);
	pause();
	return;
}

void debug_menu_Search(){
	clear_Screen();
	char student_Id[12];
	int bolis_Found = 0;
	printf("Enter the ID of student: ");
	gets(student_Id);
	
	FILE *fpointer;
	fpointer = fopen("record.txt", "rb");
	while(fread(&stu,sizeof(stu),1,fpointer) == 1){
		if(strcmp(student_Id, stu.per.id) == 0 ){
			bolis_Found = 1;
			break;
		}
	}
	
	if(bolis_Found == 1){
		printf("\nThe student is found!");
		printf("\nID: %s", stu.per.id);
		printf("\nName; %s", stu.per.first_Name);
		printf("\nSTRAND: %c", stu.enr.strand);
		printf("\nSEMESTER: %c", stu.enr.semester);
		printf("\nYEAR: %c", stu.enr.yearlvl);
		printf("\nSECTION: %c", stu.enr.section);
			getch();
	}else{
		printf("No records found!");
		getch();
	}
	

	
	
	fclose(fpointer);
	return;
}

void debug_Flex(){
	clear_Screen();
			printf("\n*Miscellaneous Fees*\nLearning Management Fee             = PHP 850\nMedical Services Fee                = PHP 557\nRegistration Fee                    = PHP 749\nGuidance and Counseling Fee         = PHP 642\nManangement Information System Fee  = PHP 1,079\nLibrary Fee                         = PHP 350\n*Tuition Fee*\nLaboratory Fee                      = PHP 3,342\nSemester Fee (Gened)                = PHP 11,323\nSemester Fee (Specialized)          = PHP 7,839");
	printf("\n\nGRAND TOTAL = PHP 26,731");
	
		system("pause");
		return;
}

int main(){
	 srand(time(NULL));//kaya nagiiba yung color
	do{
		if(choice != '2' && choice != '3'){
		system("cls");
	setRandomTextColor();	
		printf("test%c", choice);
	setRandomTextColor();	
		printf("\nA.Registration");
	setRandomTextColor();	
		printf("\nB.Enrollment");
	setRandomTextColor();	
		printf("\nC.Payment");
	setRandomTextColor();	
		printf("\nD.Reports");
	setRandomTextColor();	
		printf("\nE.Exit");
	setRandomTextColor();	
		printf("\nEnter your choice: ");choice = getche();
		}

		switch (choice){
		case 'a':
		case 'A':
			menu_Registration();
			break;
		case 'b':
		case 'B':
		case '2':
			menu_Enrollment();
			break;
		case 'c':
		case 'C':
		case '3':
			menu_Payment();
			break;
		case 'x': //debug
		case 'X':
			debug_menu_Search();
			break;
		case 'y': //debug
		case 'Y':
			debug_Flex();
			break;
		default: 
			 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("Invalid option");
			break;
		}
	}while(choice != 'e' );
	return 0;
}
