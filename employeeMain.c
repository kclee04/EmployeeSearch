//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 
 
//gcc employeeMain.c employeeTable.c employeeTwo.c 
 
#include <string.h> 
#include <stdlib.h> 
#include "employee.h" 
int main(void){ 
	//defined in employeeSearchOne.c 
	PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
	PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind); 
	PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
	PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind); 
	 
	//defined in employeeTable.c 
	extern Employee EmployeeTable[]; 
	extern const int EmployeeTableEntries; 
 
	PtrToEmployee matchPtr;//Declaration 
	matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 
 
	//Example not found 
	if(matchPtr != NULL) 
		printf("Employee ID 1045 is in record %d\n",matchPtr - EmployeeTable); 
	else 
		printf("Employee ID is NOT found in the record\n"); 
 
	//Example found 
	matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 
	if(matchPtr != NULL) 
		printf("Employee Tony Bobcat is in record %d\n",matchPtr - EmployeeTable); 
	else 
		printf("Employee Tony Bobcat is NOT found in the record\n"); 

	//example of phone found
	matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134"); 
	if(matchPtr != NULL) 
		printf("Phone number 909-555-2134 is in record %d\n",matchPtr - EmployeeTable); 
	else 
		printf("Phone number 909-555-2134 is NOT found in the record\n"); 
	//example of phone not found
	matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "626-555-2134"); 
	if(matchPtr != NULL) 
		printf("Phone number 626-555-2134 is in record %d\n",matchPtr - EmployeeTable); 
	else 
		printf("Phone number 626-555-2134 is NOT found in the record\n"); 
	//example of salary found
	matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32); 
	if(matchPtr != NULL) 
		printf("Salary 8.32 is in record %d\n",matchPtr - EmployeeTable); 
	else 
		printf("Salary 8.32 is NOT found in the record\n");
	//example of salary not found
	matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.20); 
	if(matchPtr != NULL) 
		printf("Salary 4.20 is in record %d\n",matchPtr - EmployeeTable); 
	else 
		printf("Salary 4.20 is NOT found in the record\n");
 
return EXIT_SUCCESS;
}