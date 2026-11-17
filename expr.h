/* -------- expr.h -------- */
#ifndef EXPR_H
#define EXPR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXSIZE 128

/* 两套栈结构体 */
typedef struct { char data[MAXSIZE]; int top; } OpStack;    /* 运算符栈 */
typedef struct { double data[MAXSIZE]; int top; } NumStack; /* 操作数栈 */

/* ====== 运算符栈基本操作 ====== */
void InitOp (OpStack *s);
int  OpEmpty(OpStack *s);
int  OpPush (OpStack *s, char c);
int  OpPop  (OpStack *s, char *c);
int  OpTop  (OpStack *s, char *c);

/* ====== 操作数栈基本操作 (老师要求：两套栈各写一遍) ====== */
void InitNum(NumStack *s);
int  NumEmpty(NumStack *s);
int  NumPush (NumStack *s, double val);
int  NumPop  (NumStack *s, double *val);
int  NumTop  (NumStack *s, double *val);

/* ====== 核心业务逻辑 ====== */

/* 优先级比较：返回 '>' '<' '=' (查表用) */
char Precede(char op1, char op2);

/* 词法+括号预检 */
int CheckExpr(const char *in, int *errpos, char *errmsg); 

/* 中缀转后缀 (trace=1 打印过程) */
int InfixToPostfix(const char *in, char *out, int trace);

/* 后缀表达式求值 */
int EvalPostfix(const char *post, double *result);

/* 中缀表达式直接求值 (双栈法) */
int EvalInfix(const char *in, double *result);

/* 批处理 */
int BatchProcess(const char *infile, const char *outfile);

/* 多位数与小数扫描脚手架 (老师图纸3直接搬过来声明) */
int ReadNumber(const char *in, int *i, double *val);

#endif
