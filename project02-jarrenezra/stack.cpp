#include "stack.hpp"

void Stack::push(int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->setNext(head);
    head = new_node;
}

int Stack::peek()
{
    if (head != nullptr)
    {
        return head->getValue();
    }
    else
    {
        return -1; // Return an appropriate value indicating empty stack
    }
}

Stack::Stack()
{
    head = nullptr;
}

bool Stack::empty() const
{
    return head == nullptr;
}

int Stack::pop()
{
    if (head != nullptr)
    {
        int value = head->getValue();
        Node *temp = head;
        head = head->getNext();
        delete temp;
        return value;
    }
    return -1; // there's nothing to pop
}

void SStack::push(std::string new_data)
{
    SNode *new_node = new SNode(new_data);
    new_node->setNext(head);
    head = new_node;
}

std::string SStack::peek()
{
    if (!(head == nullptr))
        return head->getValue();
    return ""; // stack is empty
}

SStack::SStack()
{
    head = nullptr;
}

bool SStack::empty() const
{
    return head == nullptr;
}

std::string SStack::pop()
{
    if (head != nullptr)
    {
        std::string value = head->getValue();
        SNode *temp = head;
        head = head->getNext();
        delete temp;
        return value;
    }
    return ""; // there's nothing to pop
}