#ifndef FUNCTION_H
#define FUNCTION_H
#include "type.h"
#include "statementList.h"
typedef struct _function{
	Symbol 	*symbol;
	Type	*returnType;
	StatementList *list;
	Node	*params;
}Function;
void initializeFunction(int, Type *, StatementList *, Node *);
Symbol *callFunction(int, Node *);
#endif
