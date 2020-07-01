#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include "HeteroLinkedList.h"

int_node::int_node(int a):data(a){}

void int_node::print_node() const
{
    cout<<data<<" ";
}

void int_node::unite(node *a) const
{
    node *tmp = new int_node(data);//create a new node of int data
    
    //unite the new int data node with node *a
    a->next_node = tmp;
    a->next()->next_node = NULL;
}

string_node::string_node(string a):data(a){}

void string_node::print_node() const
{
    cout<<data<<" ";
}

void string_node::unite(node *a) const
{
    node *tmp = new string_node(data);//create a new node of string data

    //unite the new string data node with node *a
    a->next_node = tmp;
    a->next_node->next_node = NULL;
}

double_node::double_node(double a):data(a){}

void double_node::print_node() const
{
    cout<<data<<" ";
}

void double_node::unite(node *a) const
{
    node *tmp = new double_node(data);//create a new node of double data

    //unite the new double data node with node *a
    a->next_node = tmp;
    a->next()->next_node = NULL;
}

Hetero_List::Hetero_List()
{
    //empty list initialization
    phead = NULL;
    ptail = NULL;
    length = 0;
}


Hetero_List::~Hetero_List()
{
    node *tmp1 = phead;
    node *tmp2;
    while(tmp1)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next();
        delete tmp2;
    }
    cout<<"List have been destroyed!"<<endl;
}

void Hetero_List::print_list() const
{
    node *tmp = phead;
    if(tmp == NULL)//empty list case
    {
        cout<<"PRINT ERROR:EMPTY LIST!"<<endl;
        throw EMPTYLIST;
    }
    while(tmp){
        tmp->print_node();
        tmp = tmp->next_node;
    }
    cout<<endl;
}

void Hetero_List::reverse()
{
    if(length == 1)//just one node,no need to reverse
    {
        return;
    }else if(length == 0)//empty list case
    {
        cout<<"REVERSE ERROR:EMPTY LIST!"<<endl;
        throw EMPTYLIST;
    }
    
    node *tmp = phead;
    node *tmp2 = phead->next();
    while(tmp2)
    {
        tmp->next_node = tmp2->next();
        tmp2->next_node = phead;
        phead = tmp2;
        tmp2 = tmp->next();
    }
    ptail = tmp;
    ptail->next_node = NULL;
}

void Hetero_List::head_insert(int a)
{
    length++;
    node *newhead = new int_node(a);
    if(ptail == NULL) //empty list situation
    {
        ptail = newhead;
    }
    newhead->next_node = phead;
    phead = newhead;//set the new phead
}

void Hetero_List::head_insert(string a)
{
    length++;
    node *newhead = new string_node(a);
    if(ptail == NULL) //empty list situation
    {
        ptail = newhead;
    }
    newhead->next_node = phead;
    phead = newhead;//set the new phead
}

void Hetero_List::head_insert(double a)
{
    length++;
    node *newhead = new double_node(a);
    if(ptail == NULL) //empty list situation
    {
        ptail = newhead;
    }
    newhead->next_node = phead;
    phead = newhead;//set the new phead
}

void Hetero_List::tail_insert(int a)
{
    length++;
    node* newtail = new int_node(a);
    if(phead == NULL)//empty list situation
    {
        phead = newtail;
    }
    if(ptail)
    {
        ptail->next_node = newtail;
    }
    ptail = newtail;//set the new ptail
}

void Hetero_List::tail_insert(string a)
{
    length++;
    node* newtail = new string_node(a);
    if(phead == NULL)//empty list situation
    {
        phead = newtail;
    }
    if(ptail)
    {
        ptail->next_node = newtail;
    }
    ptail = newtail;//set the new ptail
}

void Hetero_List::tail_insert(double a)
{
    length++;
    node* newtail = new double_node(a);
    if(phead == NULL)//empty list situation
    {
        phead = newtail;
    }
    if(ptail)
    {
        ptail->next_node = newtail;
    }
    ptail = newtail;//set the new ptail
}

void Hetero_List::sequence_insert(int a, int index)
{
    if(index > length)//index is out of range
    {
        cout<<"index is out of range!"<<endl;
        throw OVERFLOW;
    }else if(index <= 0)//index is a not positive number
    {
        cout<<"index is not positive!"<<endl;
        throw UNDERFLOW;
    }else
    {
        node* tmp = phead;
        if(index == length)//insert at the end of the list
        {
            tail_insert(a);
            return;
        }

        for(int i=1;i<index;i++)//find the NO.index node
        {
            tmp = tmp->next();
        }
        node *tmp2 = tmp->next();
        tmp->next_node = new int_node(a);
        tmp->next_node->next_node = tmp2;//insert behind the NO.index node
        length++;
    }
}

void Hetero_List::sequence_insert(string a, int index)
{
    if(index > length)//index is out of range
    {
        cout<<"index is out of range!"<<endl;
        throw OVERFLOW;
    }else if(index <= 0)//index is not a positive number
    {
        cout<<"index is not positive!"<<endl;
        throw UNDERFLOW;
    }else
    {
        node* tmp = phead;
        if(index == length)//insert at the end of the list
        {
            tail_insert(a);
            return;
        }

        for(int i=1;i<index;i++)//find the NO.index node
        {
            tmp = tmp->next();
        }
        node *tmp2 = tmp->next();
        tmp->next_node = new string_node(a);
        tmp->next_node->next_node = tmp2;//insert behind the NO.index node
        length++;
    }
}

void Hetero_List::sequence_insert(double a, int index)
{
    if(index > length)//index is out of range
    {
        cout<<"index is out of range!"<<endl;
        throw OVERFLOW;
    }else if(index <= 0)//index is not a positive number
    {
        cout<<"index is not positive!"<<endl;
        throw UNDERFLOW;
    }else
    {
        node* tmp = phead;
        if(index == length)//insert at the end of the list
        {
            tail_insert(a);
            return;
        }
        for(int i=1;i<index;i++)//find the NO.index node
        {
            tmp = tmp->next();
        }
        node *tmp2 = tmp->next();
        tmp->next_node = new double_node(a);
        tmp->next_node->next_node = tmp2;//insert behind the NO.index node
        length++;
    }
}

void Hetero_List::head_delete()
{
    if(phead == NULL)//empty list situation
    {
        cout<<"EMPTY LIST!"<<endl;
        throw EMPTYLIST;
    }
    node *tmp = phead;
    phead = phead->next();
    delete tmp;
    length--;
}

void Hetero_List::tail_delete()
{
    if(ptail == NULL)//empty list situation
    {
        cout<<"EMPTY LIST!"<<endl;
        throw EMPTYLIST;
    }
    
    if(length == 1)//just one node case
    {
        delete ptail;
        phead = NULL;
        ptail = NULL;
        length--;
        return;
    }
    
    node *tmp = phead;
    
    for(int i=1;i<length-1;i++)//find the node before the tail
    {
        tmp = tmp->next();
    }
    
    delete tmp->next();
    tmp->next_node = NULL;
    ptail = tmp;
    
    length--;
}

void Hetero_List::sequence_delete(int index)
{
    if(index > length)//index is out of range
    {
        cout<<"index is out of range!"<<endl;
        throw OVERFLOW;
    }else if(index <= 0)//index is not a positive number
    {
        cout<<"index is not positive!"<<endl;
        throw UNDERFLOW;
    }else
    {
        if(index == length)//delete the tail
        {
            tail_delete();
            return;
        }else if(index == 1)//delete the head
        {
            head_delete();
            return;
        }
        
        node *tmp = phead;
        node *tmp2;
        for(int i=1;i<index-1;i++)//find the NO.index-1 node
        {
            tmp = tmp->next();
        }
        tmp2 = tmp->next();
        tmp->next_node = tmp->next()->next();
        delete tmp2;//delete the NO.index node
        length--;
    }
}

node* Hetero_List::get_phead() const
{
    return phead;
}

node* Hetero_List::get_ptail() const
{
    return ptail;
}

void Hetero_List::unite(const Hetero_List& list)
{
    if(list.get_phead() == NULL)//if the second list is an empty list,do nothing
    {
        return;
    }

    if(phead == NULL)//if the first list is an empty list,copy the second list and edit the phead
    {
        node *tmp = ptail;
        node *tmp2 = list.get_phead();

        //use traverse to copy and unite
        while(tmp2)
        {
            tmp2->unite(tmp);
            tmp = tmp->next();
            tmp2 = tmp2->next();
        }
        ptail = tmp;
        head_delete();
    }
    
    node *tmp = ptail;
    node *tmp2 = list.get_phead();

    //use traverse to copy and unite
    while(tmp2)
    {
        tmp2->unite(tmp);
        tmp = tmp->next();
        tmp2 = tmp2->next();
    }
    ptail = tmp;
}




