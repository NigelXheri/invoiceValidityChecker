#define MAX_LENGTH 20
#define M_START 0
#define M_END 1
#define Y_START 2
#define Y_END 3
#define END_OF_LINE "\n"
#define C_MONTH 06
#define C_YEAR 25


typedef struct {
	char customerid[MAX_LENGTH];
	char timeref[4];
	float price;
} Invoice;

int checkInvoiceValidity(Invoice inv);
void prtcpy(char src[], char dst[], int start, int end);

int decimal(char str[], int len);

int pow(int base, int exp);