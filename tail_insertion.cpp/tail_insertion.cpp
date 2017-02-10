```
.cpp
/**
* @ProgramName: Homework-1
* @Author: Alejandra Brambila
* @Description: 
*     This program uses FrontSert and Endsert method to link a List. The FrontSert method
* insert the value as the head and moves it to the right when a new value is added.
* The Endsert method will insert at the end of the list as the Tail.
* @Semester: Spring 2017
* @Date: 09/02/2017
*/
#include <iostream>

struct Node{
  int Data;
  Node *Next;
};

using namespace std;

class List{
private:
    Node *Head;
    Node *Tail;
public:
    List(){
      Head = NULL;
    }
    
     /**
    * FrontSert
    * @params:
    *    int x : value to be placed in the list
    * @returns:
    *    void
    */
    
    void FrontSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(Head){
        Temp->Next = Head;
      }

      Head = Temp;
      
    }
   
     /**
    * EndSert
    * @params:
    *    int e : value to be placed in the list
    * @returns:
    *    void
    */
    
    void EndSert(int e){
      Node *Temp = new Node;
      Temp->Data = e;
      Temp->Next = NULL;
      
      if(!Tail){
        Head = Temp;
        Tail = Temp;
        
      }else{
          Tail->Next = Temp;
          Tail = Temp;
        }
  
    }
       
    void PrintList(){
      if(!Head){
        cout<<"Empty"<<endl;
        return;
      }else{
        Node *Temp = Head;
        while(Temp != NULL){
          cout<<Temp->Data<<"->";
          Temp = Temp->Next;
        }
      }
    }

};


int main() {
    srand(97097807);
    List L;
    for(int i=0;i<10;i++){
      L.FrontSert(rand()%100);
    }
    L.PrintList();
    
    cout << endl;
    for(int i=0; i<10; i++){
      L.EndSert(rand()%100);
    }
    L.PrintList();
    
    return 0;
}
```
