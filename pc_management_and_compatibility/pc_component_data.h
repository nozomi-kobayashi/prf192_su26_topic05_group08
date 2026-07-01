#ifndef PC_COMPONENT_DATA_H
#define PC_COMPONENT_DATA_H

#define MAX_COMPONENT 1000
//enum
typedef enum
{
	CPU,
	MAINBOARD,
	RAM, 
	SSD,
	GPU,
	PSU,
	CASE
} ComponentCategory;

typedef enum
{
	COMPATIBLE,
	SOCKET_NOT_MATCH,
	DDR_NOT_MATCH,
	COMPONENT_MISSING
	
}CompatibleStatus;

//struct
typedef struct
{
	int id;
	ComponentCategory category;
	char name[40];
	
	char socket[20];
	char ddr[10];
	
	int stock; //stock quantity
	int warrantyPeriod; 
}pcComponent;

typedef struct
{
	pcComponent components[MAX_COMPONENT];
	int count;
}componentManager;

#endif

