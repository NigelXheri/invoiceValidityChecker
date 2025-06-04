#include <string.h>
#include "invoice.h"

int checkInvoiceValidity(Invoice inv){
	
	Invoice i1,i2,i3,i4,i5;
	
	Invoice listinv[] = {i1,i2,i3,i4,i5};
	
	if(!checkDateValidity(inv)){
		return 0;
	}
	
	for(int i = 0; i < 5; i++){
		sprintf(listinv[i].timeref, "0%d%d0", i, i);
	}
	
	for(int i = 0; i < 5; i++){
		printf("Valid invoice timeref: %s\n", listinv[i].timeref);
	}
	
	// check if they are all numbers ascii 48(0) - 57(9)
	// check if the timeref is earlier than 0625;
	
	
	char month[3] = {0};
	char year[3] = {0};
	prtcpy(inv.timeref, month, M_START, M_END);
	printf("Month: %s\n",month);
	
	prtcpy(inv.timeref, year, Y_START, Y_END);
	printf("Timeref: %s, Month: %s and Year: 20%s\n", inv.timeref, month, year);
	
	
	for(int i = 0; i < 5; i++){
		if(strcmp(listinv[i].timeref, inv.timeref) == 0){
			return 1;
		}
	}
	
	return 0;
}

int checkDateValidity(Invoice inv){
	char month[3] = {0};
	char year[3] = {0};
	
	prtcpy(inv.timeref, month, M_START, M_END);
	printf("Month: %s\n",month);
	
	prtcpy(inv.timeref, year, Y_START, Y_END);
	printf("Year: %s\n", year);
	printf("Decoded Timeref: %s, to Month: %s and Year: %s\n", inv.timeref, month, year);
	
	if ((decimal(year, 2)==25) && (decimal(month, 2) < 6)){
		printf("done 1\n");
		return 1;
	}
	else if (decimal(year, 2) < 25 && (decimal(month, 2) <= 12)){
		printf("done 2\n");
		return 1;
	}
	else {
		printf("returning 0 from checkdateval\n");
		printf("This date is in the future\n");
		return 0;
	}
}

void prtcpy(char src[], char dst[], int start, int end){
	int index = 0;
	printf("Func prtcpy called\n");
	for(int i = start; i <= end; i++){
		printf("Index value: %d ", index);
		dst[index] = src[i];
		printf("value: %c\n", dst[index]);
		index++;
	}
//	dst[index] = '\0';
}

int decimal(char str[], int len){
	int decimal = 0;
	
	for(int i = 0; i < len; i++){
		decimal += (str[i] - '0') * pow(10, (len - i - 1));
		printf("decimal %d: %d\n", i, decimal);
	}
	printf("RETURNED %s: %d\n", str, decimal);
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


