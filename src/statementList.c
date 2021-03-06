
#include <stdlib.h>
#include <stdio.h>
#include "statementList.h"
//#define DEBUG_STATEMENT_LIST
struct _statementList *mkStatementList(){
	struct _statementList *list = malloc(sizeof(struct _statementList));
	list->maxElement = 10;
	list->numberElement = 0;
	list->elements = malloc(sizeof(struct _node *)*10);
	#ifdef DEBUG_STATEMENT_LIST
	printf("malloc StatementList %d (%d/%d) \n", list, list->numberElement, list->maxElement);
	#endif
	return list;
}
struct _statementList *mkStatementListWithVal(struct _node *val){
	struct _statementList *list = mkStatementList();
	#ifdef DEBUG_STATEMENT_LIST
	printf("mkStatementListWithVal to %d (%d/%d) \n", list, list->numberElement, list->maxElement);
	#endif
	insertStatementList(list, val);
	return list;
}
void			freeStatementList(struct _statementList *list){
	int i;
	#ifdef DEBUG_STATEMENT_LIST
	printf("free StatementList %d\n", list);
	#endif
	free(list->elements);
	free(list);
}
void 			insertStatementList(struct _statementList *list, struct _node *val){
	#ifdef DEBUG_STATEMENT_LIST
	printf("insertStatementList to %d (%d/%d) \n", list, list->numberElement, list->maxElement);
	#endif
	if(list->numberElement == list->maxElement){
		printf("exceed number of elements in StatementList\n");
		exit(-1);
	}
	list->elements[list->numberElement] = val;
	list->numberElement++;
}
void	 		mergeStatementList(struct _statementList *l1,struct _statementList *l2)
{
	int i;
	#ifdef DEBUG_STATEMENT_LIST
	printf("mergeStatementList %d, %d\n", l1, l2);
	#endif
	for(i=0;i<l2->numberElement;i++)
		insertStatementList(l1,l2->elements[i]);
}
void			printStatementList(struct _statementList *list){
	int i;
	printf("list:%d, now:%d, max:%d\n", list, list->numberElement, list->maxElement);
	for(i=0;i<list->numberElement;i++){
		printf("\n%d>",i);
		printnode(list->elements[i],1,0);
	}
	printf("\n");
}
