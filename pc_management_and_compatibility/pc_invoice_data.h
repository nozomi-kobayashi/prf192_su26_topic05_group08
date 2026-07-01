#ifndef PC_INVOICE_DATA_H
#define PC_INVOICE_DATA_H

#define MAX_INVOICE 1000

typedef enum
{
	PENDING,
	ASSEMBLING,
	COMPLETED
} AssemblyStatus;

typedef struct
{
	int invoiceId;
	
	int componentId[10];
	
	int componentCount;
	
	AssemblyStatus status;
}pcInvoice;

typedef struct
{
	pcInvoice invoices[MAX_INVOICE];
	int count;
}invoiceManager;

#endif