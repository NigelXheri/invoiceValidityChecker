#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "invoice.h"

Invoice *generateInvoices(int num){
	Invoice *generated_list = malloc(sizeof(Invoice)*num);
	

	for(int i = 0; i < num; i++){
		sprintf(generated_list[i].customerid, CUSTOMERID_ALGORITHM, i%2, i%3,i%5, i%1);
	}
	for(int i = 0; i < num; i++){
		sprintf(generated_list[i].timeref, TIMEREF_ALGORITHM, i, i);
		generated_list[i].timeref[4] = '\0';
	}
	for(int i = 0; i < num; i++){
		generated_list[i].price =  PRICE_ALGORITHM;
	}
	
	return generated_list;
}

void printInv(Invoice *inv_list, int num){
	for(int i = 0; i < num; i++){
		printf("==== INVOICEGEN INVOICE NR %d ====\n", i);
		printf("INVOICEGEN customerid %s\n", inv_list[i].customerid);
		printf("INVOICEGEN timeref %s\n", inv_list[i].timeref);
		printf("INVOICEGEN price %.2f\n\n", inv_list[i].price);
	}

}

void printInvAtr(Invoice *inv_list, int num){
	for(int i = 0; i < num; i++){
		printf("INVOICEGEN customerid %s\n", inv_list[i].customerid);
	}
	for(int i = 0; i < num; i++){
		printf("INVOICEGEN timeref %s\n", inv_list[i].timeref);
	}
	for(int i = 0; i < num; i++){
		printf("INVOICEGEN price %.2f\n", inv_list[i].price);
	}
}

int checkInvoiceValidity(Invoice inv, Invoice *invoiceList){
	

	if(!checkDateValidity(inv)){
		return 0;
	}
	
	char month[3] = {0};
	char year[3] = {0};
	
	prtcpy(inv.timeref, month, M_START, M_END);
	prtcpy(inv.timeref, year, Y_START, Y_END);
	
	printf("Timeref: %s, Month: %s and Year: 20%s\n", inv.timeref, month, year);
	
	
	for(int i = 0; i < 5; i++){
		if(strcmp(invoiceList[i].timeref, inv.timeref) == 0){
			return 1;
		}
	}
	
	return 0;
}

int checkDateValidity(Invoice inv){
	char month[3] = {0};
	char year[3] = {0};
	
	prtcpy(inv.timeref, month, M_START, M_END);
	prtcpy(inv.timeref, year, Y_START, Y_END);
	
//	printf("Decoded Timeref: %s, to Month: %s and Year: %s\n", inv.timeref, month, year);
	
	if ((decimal(year, 2)==C_YEAR) && (decimal(month, 2) <= C_MONTH)){
		return 1;
	}
	else if (decimal(year, 2) < C_YEAR && (decimal(month, 2) <= 12)){
		return 1;
	}
	else {
//		printf("returning 0 from checkdateval\n");
		printf("This date is in the future\n");
		return 0;
	}
}

int storeOnFile(Invoice inv[], char filename[]){
	FILE *pf = fopen(filename,"r");
	char buffer[255];
	if(fgets(buffer, 255, pf) == NULL){
		printf("Storing the data...\n");
		fclose(pf);
		pf = fopen(filename, "w");
		for(int i = 0; i < 5; i++){
			fprintf(pf, "=== INVOICE NR %d ====\n", i);
			fprintf(filename, "%s#%s#%f\n", inv[i].customerid, inv[i].timeref, inv[i].price);
		}
		fclose(pf);
		return 1; // data was stored successfully
	}
	else{
		printf("Stored data will be overriden!!!\n");
		printf("Storing the data...\n");
		fclose(pf);
		pf = fopen(filename, "w");
		for(int i = 0; i < 5; i++){
			fprintf(pf, "=== INVOICE NR %d ====\n", i);
			fprintf(pf, "%s#%s#%f\n", inv[i].customerid, inv[i].timeref, inv[i].price);
		}
		fclose(pf);
		return 2; // data was stored successfully but the previous data was overriden
	}
	
	return 0; // program failed
}

int printFileContents(char filename[]){
	FILE *pf = fopen(filename, "r");
	char buffer[255];
	if(pf!=NULL){
		while(fgets(buffer, 255, pf) != NULL){
		printf("%s", buffer);
		}
		fclose(pf);
		return 1;
	}
	else{
		printf("File was not opened");
		return 0;
	}
}

void prtcpy(char src[], char dst[], int start, int end){
	int index = 0;
//	printf("Func prtcpy called\n");
	for(int i = start; i <= end; i++){
//		printf("Index value: %d ", index);
		dst[index] = src[i];
//		printf("value: %c\n", dst[index]);
		index++;
	}
//	dst[index] = '\0'; Use this if you need to make sure that the dst string gets printed correctly
}

int decimal(char str[], int len){
	int decimal = 0;
	
	for(int i = 0; i < len; i++){
		decimal += (str[i] - '0') * pow(10, (len - i - 1));
//		printf("decimal %d: %d\n", i, decimal);
	}
//	printf("RETURNED %s: %d\n", str, decimal);
	return decimal;
}

int pow(int base, int exp) {
    int result = 1;

    if (exp < 0) {
        return 0;
    }

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}


