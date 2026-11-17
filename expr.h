#ifndef EXPR_H
#define EXPR_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// 1. 定义Token结构（B扫描输出，A和C输入）
struct Token {
    int type;        // 0:数字, 1:运算符, 2:左括号, 3:右括号, 4:一元负号
    double numVal;   // 如果是数字，存这里
    char opVal;      // 如果是运算符，存这里
};

// 2. B负责实现：中缀字符串 -> Token数组
vector<Token> scanExpression(string input); 

// 3. A负责实现：Token数组 -> 后缀RPN数组
vector<Token> infixToRPN(vector<Token> tokens);

// 4. C负责实现：后缀RPN数组 -> 计算结果
double evaluateRPN(vector<Token> rpnTokens);

// 5. D负责实现：括号检查、Trace追踪、批处理
bool checkBrackets(vector<Token> tokens); 
void printTraceInfo(const string& step, double val); // 示例追踪
void processBatchFile(string filename); 

#endif
