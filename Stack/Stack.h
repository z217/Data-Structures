#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

/*һ�����Ͷ���*/

struct node;                     //�ڵ�
typedef struct node Node;
typedef Node *PtrToNode;  //�ڵ�ָ��
typedef PtrToNode Stack;         //ջ
typedef char *ElementType;

/*����ԭ��*/

/*����:     ����һ��ջ
  ��������: ����һ����ջ */
Stack Make_Stack(void);

/*����:     ��ʼ��ջ
  ǰ������: Lָ��һ��ջ
  ��������: ��ջ��Ϊ��ջ */
void Stack_Initialize(Stack S);

/*����:     �жϿ�ջ
  ǰ������: Lָ��һ��ջ
  ��������: ��Ϊ��ջ, ����true; ���򷵻�false */
bool Stack_Empty(const Stack S);

/*����:     ���ջ����
  ǰ������: Sָ��һ����ʼ��֮���ջ
  ��������: ��ջ����, ����true; ���򷵻�false */
bool Stack_Full(const Stack S);

/*����:     ����ջ��Ԫ�ظ���
  ǰ������: Sָ��һ����ʼ��֮���ջ
  ��������: ����ջ��Ԫ�ظ��� */
unsigned Stack_Size(const Stack S);

/*����:     ������
  ǰ������: XΪһ��ElementType���͵���, Sָ��һ����ʼ��֮���ջ
  ��������: ��X����ջ��ĩβ, ���ɹ�, ����true, ���򷵻�false */
bool Stack_Push(ElementType X, const Stack S);

/*����:     ���ջ����ֵ
  ǰ������: Sָ��һ����ʼ��֮���ջ
  ��������: ����ջ��Ԫ���д����ֵ, ��Ϊ��ջ, ��δ���� */
ElementType Stack_Top(const Stack S);

/*����:     ����Ԫ��
  ǰ������: Sָ��һ���ǿ�ջ
  ��������: ɾ��ջ��Ԫ��, ��Ϊ��ջ, ��δ���� */
void Stack_Pop(const Stack S);

#endif  // !_STACK_H_
