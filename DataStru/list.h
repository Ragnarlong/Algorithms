#ifndef LIST_H_ 
#define LIST_H_


#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
/*
 * The C language struct can contain the pointer to 
 * it's own struct
 * */
struct list_head {
	struct list_head *prev, *next;
};

#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr->prev) = (ptr); } \
	while (0)


static inline void list_add_node(struct list_head *new_node, struct list_head *prev, struct list_head *next)
{
	next->prev = new_node;
	new_node->next = next;
	prev->next = new_node;
	new_node->prev = prev;
}

static inline void list_add(struct list_head *new_node, struct list_head *head)
{
	list_add_node(new_node, head, head->next);
}


static inline void list_add_tail(struct list_head *new_node, struct list_head *head)
{
	list_add_node(new_node, head->prev, head);
}

static inline void list_del_node(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next =next;
}

static inline void list_del
