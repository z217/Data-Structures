#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

/*һ�����Ͷ���*/
struct node;   //�ڵ�
struct queue;  //����
typedef struct node Node;
typedef struct queue *Queue;
typedef Node *PtrToNode;  //�ڵ�ָ��
typedef int ElementType;  //��������

/*����ԭ��*/

/*����:     ���ɶ���
  ��������: ����һ����ʼ����Ķ��� */
Queue Make_Queue(void);

/*����:     ��ʼ������
  ǰ������: Qָ��һ������
  ��������: ���г�ʼ��Ϊ�� */
void Queue_Initialize(Queue Q);

/*����:     �������Ƿ�Ϊ��
  ǰ������: Qָ��һ������
  ��������: ������Ϊ��, ����true; ���򷵻�false */
bool Queue_Empty(const Queue Q);

/*����:     ȷ����������
  ǰ������: Qָ��һ������
  ��������: ���ض��е����� */
unsigned Queue_Size(const Queue Q);

/*����:     �ڶ���ĩβ�����
  ǰ������: X��Ҫ�������ĩβ����, Qָ��һ������
  ��������: ����ӳɹ�, ����true; ���򷵻�false */
bool Queue_EnQueue(const ElementType X, Queue Q);

/*����:     �ڶ���ĩβ�����
  ǰ������: X��Ҫ�������ĩβ����, Qָ��һ������
  ��������: ����ӳɹ�, ����true; ���򷵻�false */
bool Queue_Push(const ElementType X, Queue Q);

/*����:     �ڶ��п�ͷɾ����
  ǰ������: *i��������׶�Element, Qָ��һ����ʼ��֮��Ķ���
  ��������: ��Element�����ɹ�, �ɾ��, ����true; ���򷵻�false
            ��ɾ�������Ϊ��, �򽫶��г�ʼ�� */
bool Queue_DeQueue(ElementType *i, Queue Q);

/*����:     ɾ����������
  ǰ������: Qָ��һ����ʼ��֮��Ķ���
  ��������: ���ɹ�ɾ��, ����true; ���򷵻�false */
bool Queue_Pop(Queue Q);

/*����:     ���ض�������Ԫ��
  ǰ������: Qָ��һ����ʼ��֮��Ķ���
  ��������: ���ض�������Ԫ�� */
ElementType Queue_Front(const Queue Q);

/*����:     ���ض���β��Ԫ��
  ǰ������: Qָ��һ����ʼ��֮��Ķ���
  ��������: ���ض���β��Ԫ�� */
ElementType Queue_Back(const Queue Q);

/*����:     ��ն���
  ǰ������: Qָ��һ����ʼ��֮��Ķ���
  ��������: ��ն��� */
void Queue_Clear(Queue Q);

#endif  // !_QUEUE_H_
