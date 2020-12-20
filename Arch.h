#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
//-----------------------------------------------------------------------
class Node{
    private:
        int island;
        Node * next;

    public:
        //Constructor
        Node(int val){ 
            island = val;
            next = NULL;
        }
    
        Node(int val, Node* nxt){   
            island = val;
            next = nxt;
        }
  
        int getIsland(){
            return island;
        }

    
        Node * getNext(){
            return next;
        }

        void setIsland(int val){
            island = val;
        }

        void setNext(Node* nxt){
            next = nxt;
        }

};
//-----------------------------------------------------------------------
class MyList{
    private:
        Node* head;

    public:

        MyList(){
            head = NULL;
        }

        void insert(int val){
           
            Node* temp = new Node(val, NULL);
            Node* curr = head;
            Node* prev = NULL; 

            while(curr!= NULL){
                if(curr->getIsland() == val){
                    printf("Ferry ride already added!\n");
                    return;
                }
                prev = curr; 
                curr = curr->getNext();
            }
            if(prev == NULL){
                head = temp; 
            }
            else{
                prev->setNext(temp) ; 
            }
         
        }

        void remove(int v1){
  
            Node * curr = head;
            Node * prev = NULL;
            while(curr != NULL && curr->getIsland() != v1){
                prev = curr;
                curr = curr->getNext();
            }
            if(curr == NULL){
                printf("Ferry ride does not exist\n");
                return;
            }
            //if node to delete is at head of list
            if(prev == NULL){
                prev = curr->getNext();
                delete curr;
                head = prev;
            }
       
            else{
                prev->setNext(curr->getNext());
                delete curr;
            }
        }

        int getListLength(){
            int total = 0;
            Node* tmp = head;

            while(tmp != NULL){
                total++;
                tmp = tmp->getNext();
            }

            return total;
        }

        int getNthElem(int n){
            int curr = 0;
            Node * temp = head;
            while(temp != NULL && curr != n){
                curr++;
                temp = temp->getNext();
            }

            if(temp == NULL)
                return -999;

            else{
                return temp->getIsland();
            }
        }

        void printList(){
            Node* temp = head;
            while(temp != NULL){
                printf("%d  ", temp->getIsland());
                temp = temp->getNext();
            }
        }


};
//-----------------------------------------------------------------------
class MyQueue : public Node
{   private:
        Node* front;
        Node* rear;
    public:
   // Declaration of the methods.
	void enqueue(int x) {
        Node *tmp = new Node(x,NULL);
        tmp -> setIsland(x);
        tmp -> setNext(nullptr);
        if (front == nullptr) {
            front = rear = tmp;
        }
        else {
            rear -> setNext(tmp);
            rear = tmp;
        }
    }
    void printqueue(){
        if(front == nullptr) {
            return;
        }
        Node* tmp = front;
        while (tmp) {
            printf("%d ",tmp ->getIsland());
            tmp = tmp ->getNext();
        }
        printf("\n");
    }
    void dequeue() {
        if(front == rear) {
            front = rear = nullptr;
        }
        else {
            front = front -> getNext();
        }
    }
    int peek() {
        return front->getIsland();
    }
    int isEmpty() {
        if (front != nullptr) {
            return 1;
        }
        return 0;
    }
    ~MyQueue() {
        while (front != NULL) {
            Node *tmp = front;
            front = front -> getNext();
            delete tmp;
        }
        rear = NULL;
    }
};
//-----------------------------------------------------------------------
class Island{
    private:
        MyList *adjacent;
        bool visited;

    public:
        Island(){
            adjacent = new MyList;
            visited = false;
        }

        MyList* getAdjacent(){
            return adjacent;
        }

        bool getVisited(){
            return visited;
        }

   

        void setVisited(bool status){
            visited = status;
        }
};
