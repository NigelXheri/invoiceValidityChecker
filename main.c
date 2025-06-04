#include <stdio.h>
#include <string.h>
#include "invoice.h"

#define FILENAME "invoices.txt"

int main(){
	
	Invoice *invoiceList = generateInvoices(5);
	printInv(invoiceList, 5);
	 
	Invoice i1 = {.timeref = "0250"};
	if(checkInvoiceValidity(i1, invoiceList))
	printf("INVOICE IS VALID\n");
	else
	printf("INVOICE NOT VALID\n");
	
	storeOnFile(invoiceList, FILENAME);
	
	printFileContents(FILENAME);
	
}