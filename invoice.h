#define MAX_LENGTH 20
#define M_START 0
#define M_END 1
#define Y_START 2
#define Y_END 3
#define END_OF_LINE "\n"
#define C_MONTH 06
#define C_YEAR 25
#define CUSTOMERID_ALGORITHM "1230000%d%d%d%d"
#define TIMEREF_ALGORITHM "0%d%d0"
#define PRICE_ALGORITHM ((i+1)*12+i%2)-6.2319*i

typedef struct {
	char customerid[MAX_LENGTH];
	char timeref[5];
	float price;
} Invoice;

Invoice *generateInvoices(int num);
void printInv(Invoice *inv, int num);
void printInvAtr(Invoice *inv, int num);

int checkInvoiceValidity(Invoice inv, Invoice *invoiceList);
int checkDateValidity(Invoice inv);
int storeOnFile(Invoice inv[], char filename[]);
int printFileContents(char filename[]);

void prtcpy(char src[], char dst[], int start, int end);
int decimal(char str[], int len);
int pow(int base, int exp);