#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

/*一般类型定义*/

struct node;                     //节点
typedef struct node Node;
typedef Node *PtrToNode;  //节点指针
typedef PtrToNode Stack;         //栈
typedef char *ElementType;

/*函数原型*/

/*操作:     生成一个栈
  后置条件: 返回一个空栈 */
Stack Make_Stack(void);

/*操作:     初始化栈
  前提条件: L指向一个栈
  后置条件: 将栈设为空栈 */
void Stack_Initialize(Stack S);

/*操作:     判断空栈
  前提条件: L指向一个栈
  后置条件: 若为空栈, 返回true; 否则返回false */
bool Stack_Empty(const Stack S);

/*操作:     检查栈已满
  前提条件: S指向一个初始化之后的栈
  后置条件: 若栈已满, 返回true; 否则返回false */
bool Stack_Full(const Stack S);

/*操作:     计算栈中元素个数
  前提条件: S指向一个初始化之后的栈
  后置条件: 返回栈中元素个数 */
unsigned Stack_Size(const Stack S);

/*操作:     插入项
  前提条件: X为一个ElementType类型的项, S指向一个初始化之后的栈
  后置条件: 将X插入栈的末尾, 若成功, 返回true, 否则返回false */
bool Stack_Push(ElementType X, const Stack S);

/*操作:     获得栈顶的值
  前提条件: S指向一个初始化之后的栈
  后置条件: 返回栈顶元素中储存的值, 若为空栈, 则未定义 */
ElementType Stack_Top(const Stack S);

/*操作:     弹出元素
  前提条件: S指向一个非空栈
  后置条件: 删除栈首元素, 若为空栈, 则未定义 */
void Stack_Pop(const Stack S);

#endif  // !_STACK_H_
