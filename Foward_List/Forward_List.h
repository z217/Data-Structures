#ifndef _FORWARD_LIST_H_
#define _FORWARD_LIST_H_
#include <stdbool.h>

/*一般类型定义*/

struct node;                     //节点
typedef struct node Node;
typedef Node *PtrToNode;  //节点指针
typedef PtrToNode Forward_List;  //单向链表表头
typedef PtrToNode Position;      //位置
typedef int ElementType;         //元素类型

/*函数原型*/

/*操作:     生成链表
  后置条件: 返回初始化后的链表表头 */
Forward_List Make_Forward_List(void);

/*操作:     初始化链表
  前提条件: L指向一个链表
  后置条件: 链表初始化为空 */
void Forward_List_Initialize(Forward_List L);

/*操作:     判断链表是否为空
  前提条件: L指向一个初始化之后的链表
  后置条件: 如果为空, 返回true; 否则返回false */
bool Forward_List_Empty(const Forward_List L);

/*操作:     判断链表是否已满
  前提条件: L指向一个初始化之后的链表
  后置条件: 如果链表已满, 返回true; 否则返回false */
bool Forward_List_Full(const Forward_List L);

/*操作:     判断当前节点是否是链表的末尾
  前提条件: P指向链表的一个节点, L指向一个初始化之后的链表
  后置条件: 如果P指向链表末尾, 返回true; 否则返回false */
bool Forward_List_Last(Position P, const Forward_List L);

/*操作:     计算链表的项数
  前提条件: L指向一个初始化之后的链表
  后置条件: 返回链表中的项数 */
unsigned Forward_List_Size(const Forward_List L);

/*操作:     确定链表中第n个元素的值
  前提条件: L指向一个初始化之后的链表, n为链表中元素的位次
  后置条件: 返回链表第n个元素的指针, 若超过链表元素个数,
            返回空指针 */
Position Forward_List_At(const Forward_List L, unsigned n);

/*操作:     确定元素所在的链表的节点
  前提条件: X为一个ElementType类型的对象, L指向一个初始化之后的链表
  后置条件: 如果找到, 返回指向该节点的指针; 否则, 返回空指针 */
Position Forward_List_Find(ElementType X, const Forward_List L);

/*操作:     确定链表的末尾
  前提条件: L指向一个初始化之后的链表
  后置条件: 返回指向链表的末尾的指针 */
Position Forward_List_Back(const Forward_List L);

/*操作:     确定链表的第一个节点
  前提条件: L指向一个初始化之后的链表
  后置条件: 返回指向链表的首节点的指针 */
Position Forward_List_Front(const Forward_List L);

/*操作:     确定元素X所在节点的前一个节点
  前提条件: X为一个ElementType类型的对象, L指向一个初始化之后的链表
  后置条件: 若找到该节点,返回该节点指针; 否则返回链表表尾 */
Position Forward_List_Find_Previous(ElementType X, const Forward_List L);

/*操作:     将元素插入表尾
  前提条件: X为一个ElementType类型的对象, L指向一个初始化之后的链表
  后置条件: 若成功插入节点,返回true; 否则返回false */
bool Forward_List_Push_Back(ElementType X, const Forward_List L);

/*操作:     将元素插入表头
  前提条件: X为一个ElementType类型的对象, L指向一个初始化之后的链表
  后置条件: 若成功插入节点,返回true; 否则返回false */
bool Forward_List_Push_Front(ElementType X, Forward_List L);

/*操作:     将元素插入P之后
  前提条件: X为一个ElementType类型的对象, L指向一个初始化之后的链表
            P为指向链表一个节点的指针
  后置条件: 若成功插入节点,返回true; 否则返回false */
bool Forward_List_Insert(ElementType X, const Forward_List L, Position P);

/*操作:     删除链表
  前提条件: L指向一个初始化之后的链表
  后置条件: 释放为链表分配的所有内存,并将指针设为空 */
void Forward_List_Clear(Forward_List L);

/*操作:     删除链表中的元素
  前提条件: X为一个ElementType类型的对象, L指向一个初始化之后的链表
  后置条件: 若找到该项第一次出现的节点,删除该节点 */
void Forward_List_Erase(ElementType X, const Forward_List L);

/*操作:     删除链表尾元素
  前提条件: L指向一个初始化之后的非空链表
  后置条件: 删除链表的尾元素 */
void Forward_List_Pop_Back(const Forward_List L);

/*操作:     删除链表首元素
  前提条件: L指向一个初始化之后的非空链表
  后置条件: 删除链表的首元素 */
void Forward_List_Pop_Front(const Forward_List L);

/*操作:     确定节点包含的元素
  前提条件: P为指向链表一个节点的指针
  后置条件: 返回P指向节点包含的元素 */
ElementType Forward_List_Retrieve(const Position P);

/*操作:     对链表的每一项作用函数
  前提条件: L指向一个初始化之后的链表, p指向一个接受ElementType类型参数的函数,
            且无返回值
  后置条件: p指向的函数作用于链表中每一项一次 */
void Forward_List_Traverse(const Forward_List L, void (*p)(ElementType X));

#endif  // ! _List_H_
