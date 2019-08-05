#ifndef _FORWARD_LIST_H_
#define _FORWARD_LIST_H_
#include <stdbool.h>

/*һ�����Ͷ���*/

struct node;                     //�ڵ�
typedef struct node Node;
typedef Node *PtrToNode;  //�ڵ�ָ��
typedef PtrToNode Forward_List;  //���������ͷ
typedef PtrToNode Position;      //λ��
typedef int ElementType;         //Ԫ������

/*����ԭ��*/

/*����:     ��������
  ��������: ���س�ʼ����������ͷ */
Forward_List Make_Forward_List(void);

/*����:     ��ʼ������
  ǰ������: Lָ��һ������
  ��������: �����ʼ��Ϊ�� */
void Forward_List_Initialize(Forward_List L);

/*����:     �ж������Ƿ�Ϊ��
  ǰ������: Lָ��һ����ʼ��֮�������
  ��������: ���Ϊ��, ����true; ���򷵻�false */
bool Forward_List_Empty(const Forward_List L);

/*����:     �ж������Ƿ�����
  ǰ������: Lָ��һ����ʼ��֮�������
  ��������: �����������, ����true; ���򷵻�false */
bool Forward_List_Full(const Forward_List L);

/*����:     �жϵ�ǰ�ڵ��Ƿ��������ĩβ
  ǰ������: Pָ�������һ���ڵ�, Lָ��һ����ʼ��֮�������
  ��������: ���Pָ������ĩβ, ����true; ���򷵻�false */
bool Forward_List_Last(Position P, const Forward_List L);

/*����:     �������������
  ǰ������: Lָ��һ����ʼ��֮�������
  ��������: ���������е����� */
unsigned Forward_List_Size(const Forward_List L);

/*����:     ȷ�������е�n��Ԫ�ص�ֵ
  ǰ������: Lָ��һ����ʼ��֮�������, nΪ������Ԫ�ص�λ��
  ��������: ���������n��Ԫ�ص�ָ��, ����������Ԫ�ظ���,
            ���ؿ�ָ�� */
Position Forward_List_At(const Forward_List L, unsigned n);

/*����:     ȷ��Ԫ�����ڵ�����Ľڵ�
  ǰ������: XΪһ��ElementType���͵Ķ���, Lָ��һ����ʼ��֮�������
  ��������: ����ҵ�, ����ָ��ýڵ��ָ��; ����, ���ؿ�ָ�� */
Position Forward_List_Find(ElementType X, const Forward_List L);

/*����:     ȷ�������ĩβ
  ǰ������: Lָ��һ����ʼ��֮�������
  ��������: ����ָ�������ĩβ��ָ�� */
Position Forward_List_Back(const Forward_List L);

/*����:     ȷ������ĵ�һ���ڵ�
  ǰ������: Lָ��һ����ʼ��֮�������
  ��������: ����ָ��������׽ڵ��ָ�� */
Position Forward_List_Front(const Forward_List L);

/*����:     ȷ��Ԫ��X���ڽڵ��ǰһ���ڵ�
  ǰ������: XΪһ��ElementType���͵Ķ���, Lָ��һ����ʼ��֮�������
  ��������: ���ҵ��ýڵ�,���ظýڵ�ָ��; ���򷵻������β */
Position Forward_List_Find_Previous(ElementType X, const Forward_List L);

/*����:     ��Ԫ�ز����β
  ǰ������: XΪһ��ElementType���͵Ķ���, Lָ��һ����ʼ��֮�������
  ��������: ���ɹ�����ڵ�,����true; ���򷵻�false */
bool Forward_List_Push_Back(ElementType X, const Forward_List L);

/*����:     ��Ԫ�ز����ͷ
  ǰ������: XΪһ��ElementType���͵Ķ���, Lָ��һ����ʼ��֮�������
  ��������: ���ɹ�����ڵ�,����true; ���򷵻�false */
bool Forward_List_Push_Front(ElementType X, Forward_List L);

/*����:     ��Ԫ�ز���P֮��
  ǰ������: XΪһ��ElementType���͵Ķ���, Lָ��һ����ʼ��֮�������
            PΪָ������һ���ڵ��ָ��
  ��������: ���ɹ�����ڵ�,����true; ���򷵻�false */
bool Forward_List_Insert(ElementType X, const Forward_List L, Position P);

/*����:     ɾ������
  ǰ������: Lָ��һ����ʼ��֮�������
  ��������: �ͷ�Ϊ�������������ڴ�,����ָ����Ϊ�� */
void Forward_List_Clear(Forward_List L);

/*����:     ɾ�������е�Ԫ��
  ǰ������: XΪһ��ElementType���͵Ķ���, Lָ��һ����ʼ��֮�������
  ��������: ���ҵ������һ�γ��ֵĽڵ�,ɾ���ýڵ� */
void Forward_List_Erase(ElementType X, const Forward_List L);

/*����:     ɾ������βԪ��
  ǰ������: Lָ��һ����ʼ��֮��ķǿ�����
  ��������: ɾ�������βԪ�� */
void Forward_List_Pop_Back(const Forward_List L);

/*����:     ɾ��������Ԫ��
  ǰ������: Lָ��һ����ʼ��֮��ķǿ�����
  ��������: ɾ���������Ԫ�� */
void Forward_List_Pop_Front(const Forward_List L);

/*����:     ȷ���ڵ������Ԫ��
  ǰ������: PΪָ������һ���ڵ��ָ��
  ��������: ����Pָ��ڵ������Ԫ�� */
ElementType Forward_List_Retrieve(const Position P);

/*����:     �������ÿһ�����ú���
  ǰ������: Lָ��һ����ʼ��֮�������, pָ��һ������ElementType���Ͳ����ĺ���,
            ���޷���ֵ
  ��������: pָ��ĺ���������������ÿһ��һ�� */
void Forward_List_Traverse(const Forward_List L, void (*p)(ElementType X));

#endif  // ! _List_H_
