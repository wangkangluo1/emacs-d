#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct stu_listme stu_list;
/*定义结构体*/

struct stu_listme
{
    char* p_ch_data;
    stu_list* p_stu_next;
};

char* getform_list(stu_list* pHead, int nLim)
/*取第k位数据*/    
{
    char* p_ch_lim = NULL;
    int n_count = 1;   
    stu_list* p_stu_point = pHead;
    while (n_count <= nLim)
    {
        if (p_stu_point == NULL)
            return NULL;
        p_stu_point = p_stu_point->p_stu_next;
        n_count++;
    }
    if (p_stu_point != NULL)
    {
        p_ch_lim = p_stu_point->p_ch_data;
    }
    return p_ch_lim;
}

int calu_list(stu_list* pHead)
/*计算链表长度*/
{
    int n_back = 0;
    stu_list* p_stu_point = pHead;
    while (p_stu_point->p_stu_next != NULL)
    {
        p_stu_point = p_stu_point->p_stu_next;
        n_back++;
    }
    return n_back;
}

void insert_node(char* pNow, stu_list** pHead)
/*插入链表*/
{
    stu_list* p_stu_me = (stu_list*)malloc(sizeof(stu_list));
    p_stu_me->p_ch_data =(char*)malloc(strlen(pNow)+1);
    memcpy(p_stu_me->p_ch_data, pNow, strlen(pNow));
    p_stu_me->p_ch_data[strlen(pNow)] = '\0';
    if (*pHead == NULL)
    {
        p_stu_me->p_stu_next = NULL;
    }
    else
    {
        p_stu_me->p_stu_next = *pHead;
    }
    *pHead = p_stu_me;
}

void list_free(stu_list* pHead)
/*释放链表*/
{
    stu_list* p_stu_me = pHead;
    while (p_stu_me != NULL)
    {
        stu_list* p_stu_point = p_stu_me->p_stu_next;
        free(p_stu_me->p_ch_data);
        free(p_stu_me);
        p_stu_me = p_stu_point;
    }
}

int main()
{
    stu_list* p_stu_head = NULL;
    insert_node("fuck", &p_stu_head);
    insert_node("ffsf", &p_stu_head);
    printf("%s\n",getform_list(p_stu_head, 0));
    printf("%d\n",calu_list(p_stu_head));
    list_free(p_stu_head);
    return 0;
}
