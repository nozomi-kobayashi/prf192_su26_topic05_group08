#ifndef PC_MENU_H
#define PC_MENU_H

#include "pc_component_data.h"
#include "pc_invoice_data.h"

void mainMenu(componentManager *cM, invoiceManager *iM);

void componentMenu(componentManager *cM);

void invoiceMenu(invoiceManager *iM, componentManager *cM);

#endif