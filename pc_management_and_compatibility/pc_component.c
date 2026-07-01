#include <stdio.h>
#include "pc_component_function.h"

// ==================== CRUD OPERATIONS ====================
void component_add(componentManager *cM)
{
    // Implementation here
}

// ==================== DISPLAY MODULE ====================

void component_showAll(componentManager *cM)
{
    // Implementation here
}
void component_show(pcComponent *component)
{
    // Implementation here
}
// ==================== SEARCH AND RETRIEVAL ====================
void component_searchMenu()
{
    // Implementation here
}

int component_searchById(componentManager *cM)
{
    // Implementation here
    return -1;
}

void component_searchByName(componentManager *cM)
{
    // Implementation here
}

pcComponent *component_get(componentManager *cM, int index)
{
    // Implementation here
    return NULL;
}

// ==================== STOCK MANAGEMENT ====================
void component_updateStock(componentManager *cM)
{
    // Implementation here
}
// ==================== STOCK MANAGEMENT ====================
void component_updateStock(componentManager *cM)
{
    // Implementation here
}

// ==================== SORTING ALGORITHMS ====================
void component_sortMenu()
{
    // Implementation here
}

void component_sortByStock(componentManager *cM)
{
    // Implementation here
}

void component_sortByPeriod(componentManager *cM)
{
    // Implementation here
}

void component_sort(componentManager *cM, int sortValue[])
{
    // Implementation here
}

// ==================== COMPATIBILITY CHECKING ====================
int component_isSocketCompatible(pcComponent *cpu, pcComponent *mainboard)
{
    // Implementation here
    return 0;
}

int component_isDdrCompatible(pcComponent *ram, pcComponent *mainboard)
{
    // Implementation here
    return 0;
}