#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct linked_list{
    int data;
    struct linked_list *prev;
    struct linked_list *next;
} linked_list_t;

typedef struct ctrl_list{
    int size;
    linked_list_t *first;
} ctrl_list_t;

int my_getnbr(char const *str);
int get_nbr_bit(int nbits, int data);
int get_nbr_of_negs(int ac, char * const *av);
linked_list_t *create_list(int first);
linked_list_t *put_in_list(int ac, char * const*av, ctrl_list_t *ctrl);
int radix_sort(int negs, int nbits, ctrl_list_t *ctrl_a, ctrl_list_t *ctrl_b);
void swap_list(ctrl_list_t *list);
void rotate_list(ctrl_list_t *list);
void rev_rotate_list(ctrl_list_t *list);
void kick_first_of_list(ctrl_list_t *ctrl_a, linked_list_t *tmp);
void add_new_first_list(ctrl_list_t *ctrl_b, linked_list_t *tmp);
void push_list(ctrl_list_t *ctrl_a, ctrl_list_t *ctrl_b);

void test_neg(char const *str, int *neg, int *i, int *signe)
{
    while (str[*i] == '-' || str[*i] == '+') {
        if (str[*i] == '-') {
            *neg = *neg + 1;
        }
        *i = *i + 1;
    }
    *neg = *neg % 2;
    if (*neg == 1) {
        *signe = 1;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 0;
    int signe = -1;
    int to_return = 0;
    int inter = 0;

    test_neg(str, &neg, &i, &signe);
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        inter = str[i] - 48;
        to_return = to_return * 10;
        to_return = to_return - inter;
        if (to_return == -2147483648 && signe == -1 || to_return > 0) {
            return (0);
        }
        i = i + 1;
    }
    to_return = to_return * signe;
    return (to_return);
}

void rotate_list(ctrl_list_t *list)
{
    list->first = list->first->next;
}

void rev_rotate_list(ctrl_list_t *list)
{
    list->first = list->first->prev;
}

void kick_first_of_list(ctrl_list_t *ctrl_a, linked_list_t *tmp)
{
    ctrl_a->first = ctrl_a->first->prev;
    ctrl_a->first->next = tmp->next;
    ctrl_a->first = ctrl_a->first->next;
    ctrl_a->first->prev = tmp->prev;
}

void add_new_first_list(ctrl_list_t *ctrl_b, linked_list_t *tmp)
{
    tmp->next = ctrl_b->first;
    tmp->prev = ctrl_b->first->prev;
    ctrl_b->first = ctrl_b->first->prev;
    ctrl_b->first->next = tmp;
    ctrl_b->first = ctrl_b->first->next;
    ctrl_b->first = ctrl_b->first->next;
    ctrl_b->first->prev = tmp;
    ctrl_b->first = ctrl_b->first->prev;
}

void push_list(ctrl_list_t *ctrl_a, ctrl_list_t *ctrl_b)
{
    linked_list_t *tmp = ctrl_a->first;

    ctrl_a->size = (ctrl_a->size <= 0) ? 0 : ctrl_a->size - 1;
    ctrl_b->size += 1;
    if (ctrl_a->first == NULL)
        return;
    if (ctrl_a->size >= 1){
        kick_first_of_list(ctrl_a, tmp);
    }else
        ctrl_a->first = NULL;
    if (ctrl_b->first == NULL){
        tmp->prev = tmp;
        tmp->next = tmp;
        ctrl_b->first = tmp;
    } else {
        add_new_first_list(ctrl_b, tmp);
    }
}

linked_list_t *create_list(int first)
{
    linked_list_t *list_init = malloc(sizeof(linked_list_t));

    list_init->data = first;
    list_init->prev = list_init;
    list_init->next = list_init;
    return(list_init);
}

int get_nbr_bit(int nbits, int data)
{
    nbits = 0;
    for (; data != 0; data >>= 1, nbits += 1);
    return (nbits);
}

int get_nbr_of_negs(int ac, char * const *av)
{
    int compt = 0;

    if (ac < 2)
        return (0);
    for (int i = 1; i < ac; i += 1){
        compt = (my_getnbr(av[i]) < 0) ? compt += 1 : compt;
    }
    return (compt);
}

linked_list_t *put_in_list(int ac, char * const*av, ctrl_list_t *ctrl)
{
    int i = 2;
    linked_list_t *elem;
    linked_list_t *last = ctrl->first;

    while (i < ac){
        elem = malloc(sizeof(linked_list_t));
        elem->data = my_getnbr(av[i]);
        elem->next = ctrl->first;
        elem->prev = last;
        last->next = elem;
        ctrl->first->prev = elem;
        last = elem;
        i = i + 1;
    }
    return(ctrl->first);
}

void swap_list(ctrl_list_t *list)
{
    linked_list_t *tmp = list->first;
    linked_list_t *tmp2 = list->first->next;

    list->first = tmp2;
    list->first->prev = tmp2->prev;
    tmp = tmp2->next;
    list->first->next = tmp;
}

void put_negs_first(ctrl_list_t *ctrl_a, ctrl_list_t *ctrl_b, int negs)
{
    while (ctrl_b->first != NULL){
        push_list(ctrl_b, ctrl_a);
    }
    for (int i = 0; i < negs; i += 1){
        rev_rotate_list(ctrl_a);
    }
}

int radix_sort(int negs, int nbits, ctrl_list_t *ctrl_a, ctrl_list_t *ctrl_b)
{
    for (int i = 0; i != 32; i += 1){
        for (int size_a = ctrl_a->size; size_a > 0; size_a -= 1){
            if (((ctrl_a->first->data  >> i) & 1) == 0){
                push_list(ctrl_a, ctrl_b);
            } else if (ctrl_a->first != NULL){
                rotate_list(ctrl_a);
            }
        }
        for (int size_b = ctrl_b->size; size_b > 0; size_b -= 1){
            if (((ctrl_b->first->data  >> i) & 1) == 1){
                push_list(ctrl_b, ctrl_a);
            } else if (ctrl_b->first != NULL){
                rotate_list(ctrl_b);
            }
        }
    }
    put_negs_first(ctrl_a, ctrl_b, negs);
}

int check_sorted(int ac, char *const *av)
{
    for (int i = 1; i < ac; i += 1){
        if (i > 1 && my_getnbr(av[i - 1]) > my_getnbr(av[i]))
            return (1);
    }
    return (0);
}

int main(int ac, char * const *av)
{
    linked_list_t *list_a = NULL;
    linked_list_t *list_b = NULL;
    ctrl_list_t ctrl_a = {ac - 1, list_a};
    ctrl_list_t ctrl_b = {0, list_b};
    int nbits = 0;
    int nb_neg = get_nbr_of_negs(ac, av);

    if (ac < 2)
        return (84);
    list_a = create_list(my_getnbr(av[1]));
    ctrl_a.first = list_a;
    list_a = put_in_list(ac, av, &ctrl_a);
    if (check_sorted(ac, av) == 1){
        radix_sort(nb_neg, nbits, &ctrl_a, &ctrl_b);
    }
    for (int i = 0; i < ctrl_a.size ; i++, ctrl_a.first=ctrl_a.first->next)
        printf("%d ", ctrl_a.first->data);
    return (0);
}