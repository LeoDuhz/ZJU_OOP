#pragma once

#include<iostream>
#include<string>
using namespace std;

enum ERROR{EMPTYLIST,OVERFLOW,UNDERFLOW};//define ERROR type


class node
{
public:
    node(){}
    virtual ~node(){}                       //virtual destructor
    virtual void print_node() const = 0;    //pure virtual function
    node *next(){return next_node;};
    virtual void unite(node *a) const = 0;  //pure virtual function
protected:
    node *next_node;
    friend class Hetero_List;//Hetero_List class can get access to node class's next_node
    friend class int_node;   //int_node class can get access to node class's next_node
    friend class string_node;//string_node class can get access to node class's next_node
    friend class double_node;//string_node class can get access to node class's next_node
};

class int_node:public node
{
public:
    int_node(int a);
    ~int_node(){}
    virtual void print_node() const;

    //function:void int_node::unite(node *a) const
    //description:unite this int node behind node a
    virtual void unite(node *a) const;
private:
    int data;//private int member variable
};

class string_node:public node
{
public:
    string_node(string a);
    ~string_node(){}
    virtual void print_node() const;

    //function:void string_node::unite(node *a) const
    //description:unite this string node behind node a
    virtual void unite(node *a) const;
private:
    string data;//private string member variable
};

class double_node:public node
{
public:
    double_node(double a);
    ~double_node(){}
    virtual void print_node() const;

    //function:void double_node::unite(node *a) const
    //description:unite this double node behind node a
    virtual void unite(node *a) const;
private:
    double data;//private double member variable
};

class Hetero_List
{
private:
    node *phead;//head pointer of the heterogeneous linked list
    node *ptail;//tail pointer of the heterogeneous linked list
    int length; //length of the list
public:
    Hetero_List();
    ~Hetero_List();
    void print_list() const;
    void reverse();
    void head_insert(int a);
    void head_insert(string a);
    void head_insert(double a);
    void tail_insert(int a);
    void tail_insert(string a);
    void tail_insert(double a);

    //function:void Hetero_List::sequence_insert(int a, int index)
    //description:insert a whose type is int behind the NO.index node
    void sequence_insert(int a, int index);

    //function:void Hetero_List::sequence_insert(string a, int index)
    //description:insert a whose type is string behind the NO.index node
    void sequence_insert(string a, int index);

    //function:void Hetero_List::sequence_insert(double a, int index)
    //description:insert a whose type is double behind the NO.index node
    void sequence_insert(double a, int index);

    void head_delete();
    void tail_delete();

    //function:void Hetero_List::sequence_delete(int index)
    //description:delete NO.index node
    void sequence_delete(int index);

    node* get_phead() const;
    node* get_ptail() const;
    void unite(const Hetero_List& list);
    
};


