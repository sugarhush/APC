#include "add.h"
#include "types.h"
#include <stdlib.h>

void addition_op(List *head1, List *tail1, List *head2, List *tail2, List **res_head, List **res_tail) {
    List *t1 = head1, *t2 = head2;
    int l1_size = 0, l2_size = 0;
    while (t1!=NULL) {
        l1_size++;
        t1=t1->next;
    }
    while (t2!=NULL) {
        l2_size++;
        t2=t2->next;
    }

    // printf("%d", MAX(l1_size, l2_size));

    t1=head1;
    t2=head2;
    if (l1_size > l2_size) {
        int diff = l1_size - l2_size;
        for (int i=0; i<diff; i++) {
            if (t2->prev == NULL) {
                List* temp = malloc(sizeof(List));

                temp->data=0;
                temp->prev=NULL;
                temp->next=head2;

                head2->prev=temp;
                head2=temp;
            }
            t2=t2->prev;
        }
    } else {
        int diff = l2_size - l1_size;
        for (int i=0; i<diff; i++) {
            if (t1->prev == NULL) {
                List* temp = malloc(sizeof(List));

                temp->data=0;
                temp->prev=NULL;
                temp->next=head1;

                head1->prev=temp;
                head1=temp;
            }
            t1=t1->prev;
        }
    }
}
