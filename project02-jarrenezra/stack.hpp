#ifndef STACK_HPP
#define STACK_HPP

#include <string>

class Node
{
private:
    int value;
    Node *next;

public:
    Node(int val) : value(val), next(nullptr) {}

    int getValue() const
    {
        return this->value;
    }
    Node *getNext() const
    {
        return this->next;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
};

class Stack
{
private:
    Node *head;

public:
    Stack();
    bool empty() const;
    int peek();
    void push(int);
    int pop();
};

class SNode
{
private:
    std::string value;
    SNode *next;

public:
    SNode(std::string val) : value(val), next(nullptr) {}

    std::string getValue() const
    {
        return this->value;
    }
    SNode *getNext() const
    {
        return this->next;
    }
    void setNext(SNode *next)
    {
        this->next = next;
    }
};

class SStack
{
private:
    SNode *head;

public:
    SStack();
    bool empty() const;
    std::string peek();
    void push(std::string);
    std::string pop();
};

#endif