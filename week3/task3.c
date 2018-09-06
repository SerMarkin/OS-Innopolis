#include <stdio.h>
struct ar_list{
	struct ar_list *next;
	int val;
};
void print_list(struct ar_list *head) {
    struct ar_list *t = head;

    while (t != NULL) {
        printf("%d ", t->val);
        t = t->next;
    }
}
void insert_node(struct ar_list *head,int index,int val){
    struct ar_list *t = head;
	if(index <0){return;}
	if (index == 0){
		struct ar_list *new = malloc(sizeof(struct ar_list));
		new->next = t->next;
		new->val = t->val;
		t->val = val;
		t->next = new;
		return;
	}

    int i = 0;

    while(t->next != 0 && i<index-1){
	t = t->next;
	i++;
    }
	
	struct ar_list *new = malloc(sizeof(struct ar_list));
	new->next = t->next;
	new->val = val;
	t->next = new;
}
void delete_node(struct ar_list *head,int index){
	struct ar_list *t = &head,*p;
	if(index <0){return;}
	if (index == 0){
		struct ar_list *new = malloc(sizeof(struct ar_list));
		t = t->next;
		return;
	}
	int i = 0;

    while(t->next != 0 && i<index){
	t = t->next;
	i++;
    }
	printf("%d \n",t->val);
	t->next = t->next->next;
	return;
}
int main(){
struct ar_list ar1 = {NULL,0};
struct ar_list *p = &ar1;
for (int i=1; i < 10; i++){
	p->next=malloc(sizeof(struct ar_list));

	p->next->val = i*2;
	p->next->next = NULL;
	printf("%d ",p->val);
	p = p->next;
}
	printf("\n");
print_list(&ar1);
	printf("\n");
insert_node(&ar1,0,100);
delete_node(&ar1,2);
print_list(&ar1);
	printf("\n");
 return 0;
}
