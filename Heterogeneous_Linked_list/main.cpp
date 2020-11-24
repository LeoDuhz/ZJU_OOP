//
//  main.cpp
//  Heterogeneous_Linked_List
//
//  Created by Leo on 2020/6/30.
//  Copyright © 2020 Leo. All rights reserved.
//

#include"HeteroLinkedList.h"

int main()
{
    Hetero_List list1;
    Hetero_List list2;
    
    //test began
    cout<<"下面开始测试！"<<endl;
    cout<<endl;
    
    cout<<"首先对list1、list2进行初始化"<<endl;
    cout<<"在list1中输入：1 303 22.1 'hello' 231.8"<<endl;
    list1.tail_insert(1);
    list1.tail_insert(303);
    list1.tail_insert(22.1);
    list1.tail_insert("hello");
    list1.tail_insert(231.8);
    cout<<"在list2中输入：'halo' 8987 231.321 'la vita'"<<endl;
    list2.tail_insert("halo");
    list2.tail_insert(8987);
    list2.tail_insert(231.321);
    list2.tail_insert("la vita");
    
    cout<<"对list1、list2进行遍历输出："<<endl;
    cout<<"list1:"<<endl;
    list1.print_list();
    cout<<"list2:"<<endl;
    list2.print_list();
    cout<<endl;
    
    cout<<"对list2进行逆置："<<endl;
    list2.reverse();
    cout<<"list2:"<<endl;
    list2.print_list();
    cout<<endl;
    
    cout<<"在list2头部插入：‘amore',尾部插入：34.3212"<<endl;
    list2.head_insert("amore");
    list2.tail_insert(34.3212);
    cout<<"list2:"<<endl;
    list2.print_list();
    cout<<endl;
    
    cout<<"在list1第3个位置后面插入‘oh'"<<endl;
    list1.sequence_insert("oh", 3);
    cout<<"list1:"<<endl;
    list1.print_list();
    cout<<endl;
    
    cout<<"将list1头部、尾部都删除一个，将第2个位置删除"<<endl;
    list1.head_delete();
    list1.tail_delete();
    list1.sequence_delete(2);
    cout<<"list1:"<<endl;
    list1.print_list();
    cout<<endl;
    
    cout<<"下面测试两个链表合并，将list1和list2合并："<<endl;
    list1.unite(list2);
    list1.print_list();
    cout<<endl;

    cout<<"下面测试异常处理的一些机制："<<endl;
    cout<<"1.创建一个空链表，进行打印操作"<<endl;
    Hetero_List list3;
    try
    {
        list3.print_list();
    }
    catch(ERROR e)
    {
        switch(e)
        {
            case EMPTYLIST:
            cout<<"Exit because of EMPTYLIST!"<<endl;
            break;
            case OVERFLOW:
            cout<<"Exit because of OVERFLOW!"<<endl;
            break;
            case UNDERFLOW:
            cout<<"Exit because of UNDERFLOW!"<<endl;
            break;
        }
    }
    cout<<endl;

    cout<<"2.对空链表就行逆置操作"<<endl;
    try
    {
        list3.reverse();
    }
    catch(ERROR e)
    {
        switch(e)
        {
            case EMPTYLIST:
            cout<<"Exit because of EMPTYLIST!"<<endl;
            break;
            case OVERFLOW:
            cout<<"Exit because of OVERFLOW!"<<endl;
            break;
            case UNDERFLOW:
            cout<<"Exit because of UNDERFLOW!"<<endl;
            break;
        }
    }
    cout<<endl;

    cout<<"3.顺序插入中输入大于长度的数"<<endl;
    try
    {
        list3.sequence_insert(1,100);
    }
    catch(ERROR e)
    {
        switch(e)
        {
            case EMPTYLIST:
            cout<<"Exit because of EMPTYLIST!"<<endl;
            break;
            case OVERFLOW:
            cout<<"Exit because of OVERFLOW!"<<endl;
            break;
            case UNDERFLOW:
            cout<<"Exit because of UNDERFLOW!"<<endl;
            break;
        }
    }
    cout<<endl;

    cout<<"4.顺序删除中输入小于0的数"<<endl;
    try
    {
        list3.sequence_delete(-100);
    }
    catch(ERROR e)
    {
        switch(e)
        {
            case EMPTYLIST:
            cout<<"Exit because of EMPTYLIST!"<<endl;
            break;
            case OVERFLOW:
            cout<<"Exit because of OVERFLOW!"<<endl;
            break;
            case UNDERFLOW:
            cout<<"Exit because of UNDERFLOW!"<<endl;
            break;
        }
    }
    cout<<endl;

    cout<<"最后，调用析构函数销毁链表"<<endl;

}
