#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          //Complete this method
          Node *temp1;
          temp1->data=data;
          temp1->next=NULL;
          if (head==NULL)
          {
              //temp1->data=data;
              //temp1->next=NULL;
              head=temp1;
              return temp1;
          }
          else
          {
              Node *temp=head;
              while(temp)
              {
                  //temp1->data=data;
                  //temp1->next=NULL;
                  temp->next=temp1;
              }
              return temp1;
          }
      }

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
		
}