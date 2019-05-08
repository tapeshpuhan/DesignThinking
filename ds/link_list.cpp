#include <iostream>
#include <initializer_list>
#include <memory>

template<typename TYPE>
class LinkList
{
    private:
    struct Node
    {
        std::shared_ptr<Node> next{nullptr};
        TYPE data;
    };
    
    public:
    using NodePtr = std::shared_ptr<Node>;
    
    LinkList()=default;
 
    LinkList(const std::initializer_list<TYPE>& list)
    {
        for(const TYPE& value : list)
        {
          InsertNode(value);  
        }
    }
    void push_back(const TYPE& value)
    {
        InsertNode(value);
    }
    void insert(const TYPE& value, const size_t pos)
    {
        InsertNode(value,pos);
    }
    size_t size()const
    {
        return count_;
    }
    void print()
    {
        NodePtr temp = first;
        
        while(temp != nullptr)
        {
            std::cout<<temp->data<<std::endl;
            temp = temp->next;
        }
    }
    private:
 
    void InsertNode(const TYPE& value)
    {
        if(first == nullptr)
        {
            first = CreateNode(value);
            last = first;
            
        }
        else
        {
           NodePtr temp =  CreateNode(value);
           last->next = temp;
           last = temp;
        }
    }
    
    void InsertNode(const TYPE& value, const size_t pos)
    {
        size_t size = count_;
        NodePtr new_node =  CreateNode(value);
        
        if(pos == 0)
        {
            new_node->next = first;
            first =  new_node;
        }
        else if(pos < size)
        {
            NodePtr temp  = first;
            NodePtr temp_next;
            for(size_t index = 0; index < pos-1; ++index)
            {
                temp = temp->next;
            }
            temp_next = temp->next;
            temp->next = new_node;
            new_node->next = temp_next;
        }
        else
        {
           last->next = new_node;
           last = new_node;
        }
            
    }
    
    NodePtr CreateNode(const TYPE& value)
    {
       NodePtr node = std::make_shared<Node>();
       node->next=nullptr;
       node->data=value;
       count_++;
       return node;
    }
    
    NodePtr first{nullptr};
    NodePtr last{nullptr};
    size_t count_{0};
};
int main()
{
    LinkList<int> v{1,2,3,4,5};
    //v.print();
    v.push_back(100);
    
    v.insert(400,6);    
    v.insert(200,0);
    v.insert(300,3);
    v.print();
    
    
    return 0;
}
