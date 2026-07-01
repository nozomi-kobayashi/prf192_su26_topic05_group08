#ifndef PC_COMPONENT_FUNCTION_H
#define PC_COMPONENT_FUNCTION_H

#include "pc_component_data.h"

//Crud
void component_add(componentManager *cM);

//Display
void component_showAll(componentManager *cM);
void component_show(pcComponent *component);

//Search and Get
void component_searchMenu();
int component_searchById(componentManager *cM);
void component_searchByName(componentManager *cM);
pcComponent *component_get(componentManager *cM, int index);

//Stock
void component_updateStock(componentManager *cM);
void component_trackStock(componentManager *cM);

//Sort
void component_sort(componentManager *cM, int sortValue[]);
void component_sortByStock(componentManager *cM);
void component_sortByPeriod(componentManager *cM);
void component_sortMenu();

//Compatible checking
int component_isSocketCompatible(pcComponent *cpu, pcComponent *mainboard);
int component_isDdrCompatible(pcComponent *ram, pcComponent *mainboard);

#endif

