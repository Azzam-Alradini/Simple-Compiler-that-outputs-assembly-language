#include "global.h"

void emit(int t, int tval)
{
	switch(t) {
	case '+':
		fprintf(OUTPUT,"Pop r1\nPop r2\nADD r2 r1\nPush r2\n"); 
		break;
	case '-':
		fprintf(OUTPUT,"Pop r1\nPop r2\nSUB r2 r1\nPush r2\n"); 
		break;
	case '*':
		fprintf(OUTPUT,"Pop r1\nPop r2\nMUL r2 r1\nPush r2\n"); 
		break;
	case '/':
		fprintf(OUTPUT,"Pop r1\nPop r2\nRDIV r2 r1\nPush r2\n"); 
		break;
	case DIV:
		fprintf(OUTPUT,"Pop r1\nPop r2\nDIV r2 r1\nPush r2\n" );
		break;
	case MOD:
		fprintf(OUTPUT,"Pop r1\nPop r2\nMOD r2 r1\nPush r2\n"); 
		break;
	case NUM:
		fprintf(OUTPUT,"Push %d\n", tval);
		break;
	case ID:
		fprintf(OUTPUT,"Pop %s\n", symtable[tval].lexptr); 
		break;
	case IF:
		fprintf(OUTPUT, "Pop r2\nCmp r2,0\nBe else\n");
		break;	
	case THEN:
		fprintf(OUTPUT, "else:\n");
		break;	
	case WHILE:
		fprintf(OUTPUT, "Pop r2\nCmp r2,0\nbe Endwhile\n");
		break;
	case DO:
		fprintf(OUTPUT, "B while\nEndwhile:\n");
		break;
		
	default:
		fprintf(OUTPUT,"token %d, tokenval %d\n", t, tval);
	}
}

