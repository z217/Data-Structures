#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

/*一般类型定义*/
struct node;   //节点
struct queue;  //队列
typedef struct node Node;
typedef struct queue *Queue;
typedef Node *PtrToNode;  //节点指针
typedef int ElementType;  //数据类型

/*函数原型*/

/*操作:     生成队列
  后置条件: 返回一个初始化后的队列 */
Queue Make_Queue(void);

/*操作:     初始化队列
  前提条件: Q指向一个队列
  后置条件: 队列初始化为空 */
void Queue_Initialize(Queue Q);

/*操作:     检查队列是否为空
  前提条件: Q指向一个队列
  后置条件: 若队列为空, 返回true; 否则返回false */
bool Queue_Empty(const Queue Q);

/*操作:     确定队列项数
  前提条件: Q指向一个队列
  后置条件: 返回队列的项数 */
unsigned Queue_Size(const Queue Q);

/*操作:     在队列末尾添加项
  前提条件: X是要被添加至末尾的项, Q指向一个队列
  后置条件: 若添加成功, 返回true; 否则返回false */
bool Queue_EnQueue(const ElementType X, Queue Q);

/*操作:     在队列末尾添加项
  前提条件: X是要被添加至末尾的项, Q指向一个队列
  后置条件: 若添加成功, 返回true; 否则返回false */
bool Queue_Push(const ElementType X, Queue Q);

/*操作:     在队列开头删除项
  前提条件: *i储存队列首段Element, Q指向一个初始化之后的队列
  后置条件: 若Element拷贝成功, 项被删除, 返回true; 否则返回false
            若删除后队列为空, 则将队列初始化 */
bool Queue_DeQueue(ElementType *i, Queue Q);

/*操作:     删除队列首项
  前提条件: Q指向一个初始化之后的队列
  后置条件: 若成功删除, 返回true; 否则返回false */
bool Queue_Pop(Queue Q);

/*操作:     返回队列首项元素
  前提条件: Q指向一个初始化之后的队列
  后置条件: 返回队列首项元素 */
ElementType Queue_Front(const Queue Q);

/*操作:     返回队列尾项元素
  前提条件: Q指向一个初始化之后的队列
  后置条件: 返回队列尾项元素 */
ElementType Queue_Back(const Queue Q);

/*操作:     清空队列
  前提条件: Q指向一个初始化之后的队列
  后置条件: 清空队列 */
void Queue_Clear(Queue Q);

#endif  // !_QUEUE_H_
