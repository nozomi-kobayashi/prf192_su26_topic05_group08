#ifndef PC_FILE_H
#define PC_FILE_H

#include "pc_component_data.h"
#include "pc_invoice_data.h"

// Component File 
void file_loadComponents(componentManager *cM);
void file_saveComponents(componentManager *cM);

// Invoice File 
void file_loadInvoices(invoiceManager *iM);
void file_saveInvoices(invoiceManager *iM);

#endif