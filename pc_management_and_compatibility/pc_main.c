#include<stdio.h>
#include<stdlib.h>

#include "pc_file.h"
#include "pc_menu.h"

int main(){
	
	componentManager cM;
	invoiceManager iM;
	
	file_loadComponents(&cM);
	file_loadInvoices(&iM);
	
	mainMenu(&cM, &iM);
	
	file_saveComponents(&cM);
	file_saveInvoices(&iM);
	return 0;
}