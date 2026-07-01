#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pc_file.h"

#define COMPONENT_FILE "components_data.csv"

// Helper function: Convert CSV string to Enum
ComponentCategory parseCategory(const char *str)
{
    if (strcmp(str, "CPU") == 0)
        return CPU;
    if (strcmp(str, "MAINBOARD") == 0)
        return MAINBOARD;
    if (strcmp(str, "RAM") == 0)
        return RAM;
    if (strcmp(str, "SSD") == 0)
        return SSD;
    if (strcmp(str, "GPU") == 0)
        return GPU;
    if (strcmp(str, "PSU") == 0)
        return PSU;
    return CASE; // Default fallback
}

// Helper function: Convert Enum to CSV string
const char *categoryToString(ComponentCategory cat)
{
    switch (cat)
    {
    case CPU:
        return "CPU";
    case MAINBOARD:
        return "MAINBOARD";
    case RAM:
        return "RAM";
    case SSD:
        return "SSD";
    case GPU:
        return "GPU";
    case PSU:
        return "PSU";
    case CASE:
        return "CASE";
    default:
        return "UNKNOWN";
    }
}

// ==================== COMPONENT FILE I/O ====================

void file_loadComponents(componentManager *cM)
{
    cM->count = 0;

    FILE *file = fopen(COMPONENT_FILE, "r");
    if (file == NULL)
    {
        printf("Error: Cannot open file %s!\n", COMPONENT_FILE);
        return;
    }

    char buffer[256];
    char catStr[20];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        pcComponent *curr = &cM->components[cM->count];

        int parsed = sscanf(buffer, "%d,%19[^,],%39[^,],%19[^,],%9[^,],%d,%d",
                            &curr->id,
                            catStr,
                            curr->name,
                            curr->socket,
                            curr->ddr,
                            &curr->stock,
                            &curr->warrantyPeriod);

        if (parsed == 7)
        {
            curr->category = parseCategory(catStr);
            cM->count++;
        }
    }

    fclose(file);
    printf("Successfully loaded %d components from database!\n", cM->count);
}


void file_saveComponents(componentManager *cM)
{
    FILE *file = fopen(COMPONENT_FILE, "w");
    if (file == NULL)
    {
        printf("Error: Cannot write to file %s!\n", COMPONENT_FILE);
        return;
    }

    for (int i = 0; i < cM->count; i++)
    {
        pcComponent *curr = &cM->components[i];

        fprintf(file, "%d,%s,%s,%s,%s,%d,%d\n",
                curr->id,
                categoryToString(curr->category),
                curr->name,
                curr->socket,
                curr->ddr,
                curr->stock,
                curr->warrantyPeriod);
    }

    fclose(file);
    printf("Successfully saved %d components to database!\n", cM->count);
}