
#ifndef QUEUE_H_
#define QUEUE_H_

#include <string>
#include <iostream>
using namespace std;
namespace ubcse{

#include "node.h"


    template <typename T>
    class queue {

    private:
        Node<T>* head;
        Node<T>* tail;
        size_t num_items;

    public:

        /**
         *  Default constructor.
         *  this constructor initializes the following:
         *         head to nullptr,
         *         tail to nullptr,
         *         num_items to zero.
         */
        queue<T>(){
            head = nullptr;
            tail = nullptr;
            num_items = 0;
        }



        /**
         *  TO DO: Step9.1
         *  Implement copy constructor.
         *
         *  This constructor performs deep copy of the queue.
         *  Input argument for this constructor is a constant
         *      reference of another queue.
         *  The input Queue is not allowed to change.
         *
         *  Copy all the data members from the given queue to
         *      this queue. That means you have to copy the whole queue,
         *      update the head and tail pointer, and the num_items.tai
         *
         *  Also consider any edge/boundary cases that can arise.
         *
         */
        queue<T>(queue<T>& other){
            head=other.head;
            tail=other.tail;
            num_items=other.num_items;

            // put your code here
        }



        /*
         *  TO DO: 10.1
         *  Implement destructor.
         *  Write a destructor to release all heap memory without any memory leak.
         */

        // Write the destructor here.
            ~queue()
            {
				   while(head!=NULL){
                    Node<T>* del = head;
                    head=head->next;
                    delete del;
                }
                delete tail;
                num_items=0;
            }

        /******* getter function declarations  *******************/

        /* returns the head pointer   */
        Node<T>* get_head() const;

        /* returns the tail pointer.  */
        Node<T>* get_tail() const;

        /* returns the size of the queue.   */
        int size() const;

        /* checks whether queue is empty or not.   */
        bool is_empty() const;




        /******** setter/ modifier function declarations  *************/

        /*  assign the given pointer val to head pointer   */
        void set_head(Node<T>* ptr);

        /*  assign the given pointer val to tail pointer   */
        void set_tail(Node<T>* ptr);

        /* update the current number of items in the queue   */
        void set_size(int n_items);


        /********************* Core queue operations  **********/

        /* pushes an item onto the tail.   */
        void push(const T& val);

        /* removes the front item from the queue   */
        void pop();

        /*   return the front element, however, it is not going
         to delete the front element.       */
        T& front();
        //const dtype& front() const;




        /******** For portability **********************/

        /* performs swap between two queues  */
        void swap(queue<T>& other);



        /********* operations for unfair queue **************/


        /* deletes the whole queue without memory leak  */
        void delete_all();

        /* delete data from any position   */
        void delete_from_anywhere(int position);

        /* insert data in the any position   */
        void insert_anywhere(const T& val, const int position);


        /******* printing *******************************/


        /*  prints the whole queue   */
        void print();

    }; // end of Stack class



    /* **************  Accessor FUNCTIONS *************************/

    /**
     *  TO DO: Step1.1
     *
     *  Implement get_head function.
     *  This function returns the head pointer.
     */
    template <typename T>
    Node<T>* queue<T>::get_head() const{
        return head;
        // put your code here
    } // End of get_head function.


    /**
     *  TO DO: Step1.2
     *
     *  Implement get_tail function.
     *  This function returns the tail pointer.
     */
    template <typename T>
    Node<T>* queue<T>::get_tail() const{
        return tail;
        // put your code here
    } // End of get_tail function.



    /**
     *  TO DO: Step1.3
     *
     *  Implement  size function.
     *  This function returns the size of the queue.
     *  return type is 'int'.
     */
    template <typename T>
    int queue<T>::size() const{
        return num_items;
        // put your code here
    } // End of size method



    /**
     *  TO DO : Step1.4
     *
     *  Implement is_empty function.
     *  This function returns whether the queue is empty
     *      or not.
     *  If empty it returns true, otherwise returns
     *      false.
     */
    template <typename T>
    bool queue<T>::is_empty() const {
        return head==NULL;
        // put your code here
    } // End of is_empty function.



    /************   Modifier FUNCTIONS ***********************/


    /**
     *  TO DO : Step1.5
     *
     *  Implement set_head function.
     *  This function updates the head pointer
     *      using input pointer.
     */
    template <typename T>
    void queue<T>::set_head(Node<T>* ptr){
        // put your code here
        head=ptr;
    } // End of set_head function.

    /**
     *  TO DO : Step1.6
     *
     *  Implement set_tail function.
     *  This function updates the tail pointer
     *      using input pointer.
     */
    template <typename T>
    void queue<T>::set_tail(Node<T>* ptr){
        // put your code here
        tail=ptr;
    }; // End of set_tail function.


    /**
     *  TO DO: Step1.7
     *
     *  implement set_size function.
     *  This function update the num_items using the input
     *      size.
     */
    template <typename T>
    void queue<T>::set_size(int n_items){
        // put your code here
        num_items=n_items;
    } // End of set_size function.




    /************   CORE QUEUE OPERATIONS   **********************/



    /**
     *  TO DO: Step2.1
     *
     *  Implement the push function.
     *  This function adds item at the back
     *      of the queue.
     *  It also updates the tail pointer accordingly.
     *  and also increase 'num_items' by 1.
     *
     *  Push function should work for both empty and nonempty queue.
     *
     */
    template <typename T>
    void queue<T>::push(const T& val){
        if(head==NULL){
            tail= new Node<T>(val, NULL);
            head=tail;
        }
        else{
            tail->next =new Node<T>(val, NULL);
            tail=tail->next;
        }
        num_items++;
        // put your code here
    } // end of push function




    /**
     *  TO DO: Step3.1
     *
     *  Implement pop function.
     *  This function removes an item from the front of the queue.
     *  It returns nothing.
     *
     *  If queue is empty it will print a message "Queue is empty"
     *  and DO NOT exit the program. You can return.
     *
     *  Don't forget to reduce the 'num_items' by 1.
     *
     *  After performing pop, if the queue becomes empty,
     *      set the head and tail pointer to nullptr.
     *
     */
    template <typename T>
    void queue<T>::pop(){
        if(num_items==0){
            cout<<"Queue is empty";
            return;
        }

        Node<T> *del = head;
        head = head->next;

        delete del;
        if(head==NULL) tail=head;
        num_items--;
    } // end of pop function




    /**
     *  TO DO: Step 4.1
     *
     *  Implement front function.
     *
     *  This function returns the front data of the queue.
     *  if the queue is empty is prints a message
     *      "Queue is empty" and exit the program.
     *
     */
    template <typename T>
    T& queue<T>::front(){
        if(num_items==0)
        {
            cout<< "Queue is empty";
            exit(0);
        }

        return head->data;

        // put your code here
    } // End of front function.




    /************ FOR PORTABILITY **********************************/

    /**
     * TO DO : Step5.1
     *
     *  Implement swap method.
     *  Input argument:
     *  @param other - reference to a queue.
     *  This function swaps contents between current queue
     *      and in input queue, other .
     *  It also swaps the 'num_items' values.
     *
     */
    template <typename T>
    void queue<T>::swap(queue<T>& other){
        // put your code here
        int  newNUM=num_items;
        Node<T>* oldhead= head;
        Node<T>* oldtail= tail;

        head = other.head;
        tail=other.tail;
        other.head = oldhead;
        other.tail=oldtail;
        num_items=other.num_items;
        other.num_items=newNUM;



    } // End of swap function.



    /******* UNFAIR QUEUE OPERATIONS **********************************/



    /**
     * TO DO: Step6.1
     *
     *  Implement inset_anywhere function.
     *  This method enables the queue to become unfair. Using this function
     *      you can push an item anywhere in the queue.
     *
     *  This function takes two arguments -
     *      (1) the value that you want to push, and
     *      (2) the position where user wants to push.
     *  The position argument is similar to index,
     *      it starts from 0. That means, the front of
     *      the queue has position 0.
     *  For example, a single linked list - [z]->[k]->[c]->[g],
     *      you can think, z is in position 0, k is in position 1,
     *      c is in position 2, and g is in position 3.
     *  When user performs an insert_anywhere(e,2) the new list should look like -
     *      [z]->[k]->[e]->[c]->[g].
     *  Now, 'z' is in position 0, 'k' is in position 1, 'e' is in position 2,
     *      'c' is in position 3, and 'g' is in position 4.
     *  If you perform another insert_anywhere(d,1) the new list should look like -
     *      [z]->[d]->[k]->[e]->[c]->[g].
     *  Now, 'z' is in position 0, 'd' is in position 1, 'k' is in position 2,
     *      and 'e' is in position 3, 'c' is in position 4, and 'g' is in position 5.
     *
     *  You can use a for loop and next pointer to reach appropriate position.
     *
     *  Don't forget to update num_items.
     *  Also keep in mind your function should work even when queue is empty.
     *
     *  Also take care of invalid positions. (position < 0 or position > list size)
     *  In such case, print "Position is not valid" and DO NOT exit the program.
     *      You can return.
     *
     */

    template <typename T>
    void queue<T>::insert_anywhere(const T& val, const int position){
        // put your code here
        if(position<0||position>num_items)
        {
            cout<< "Position is not valid\n";
        }
        if(num_items==0) {
            head=new Node<T>(val, NULL);
            tail=head;
            num_items++;
            return;
        }
        if(num_items>0){
            Node<T>* old= head;

            for(int i=0; old!=NULL;i++){

                if(i==position){
                    Node<T> * current = new Node<T>(old->data,old->next);
                    old->data=val;
                    old->next=current;
                    num_items++;
                    break;
                }
                old=old->next;
            }
        }
    }
    // End of insert_anywhere function.



    /**
     *  TO DO: Step7.1
     *
     *  Implement delete_from_anywhere
     *
     *  This method also enables the queue to become unfair.
     *  User can remove something from the middle of the queue.
     *  The input argument -
     *      the position that you want to delete.
     *  The position argument is similar to index, it starts from 0.
     *  That means, the front of the queue has position 0.
     *
     *  For example, a single linked list - [z]->[k]->[c]->[g],
     *      you can think, z is in position 0, k is in position 1,
     *      c is in position 2, and g is in position 3.
     *  If you perform deleter_from_anywhere(2) the new list should look like -
     *      [z]->[k]->[g].
     *  Now, 'z' is in position 0, 'k' is in position 1,
     *      and 'g' is in position 2.
     *  If you perform another deleter_from_anywhere(2) the new list should look like -
     *      [z]->[k].
     *  Now, 'z' is in position 0 'k' is in position 2,
     *  You can use a for loop and next pointer to reach appropriate position.
     *
     *  Don't forget to update num_items.
     *  Also take cake of the edge cases - empty queue.
     *  IF your queue becomes empty after deletion, update head and tail pointers.
     *
     *  Also take care of invalid positions. (position < 0 or position > list size)
     *  In such case, print "Position is not valid" and DO NOT exit the program.
     *
     */
    template <typename T>
    void queue<T>::delete_from_anywhere(int position){
        // put your code here
        if(position<0||position>num_items)
        {
            cout<< "Position is not valid\n";
        }

        if(num_items>0){
            if(num_items==1){
                head=NULL;
                tail=head;
                delete head;
                num_items--;
                return;
            }

            Node<T>* ptr= head;
            Node<T>* preptr= head;
            Node<T>* oldtail= tail;

            // require a pre pointer;
            for(int i=0;ptr!=NULL;i++){
                if(i==position){
                    if(i==0){
                        head=head->next;
                        delete ptr;
                        num_items--;
                        break;
                    }
                    if(i==num_items-1){
                        tail=preptr;
                        delete oldtail;
                        num_items--;
                        break;
                    }

                    Node<T>* del =ptr;
                    preptr->next= preptr->next->next;
                    delete del;
                    num_items--;
                    break;
                }
                preptr=ptr;
                ptr=ptr->next;
            }
        }
    } // End of delete_from_anywhere function.


    /**
     *  TO DO: Step8.1
     *
     *  Implement delete_all function.
     *
     *  This function deletes all the elements in the queue
     *      without any memory leak.
     *  If the queue is empty, print "Nothing to delete!" and DO NOT exit
     *      the program. You can return.
     *
     */
    template <typename T>
    void queue<T>::delete_all(){
        // put your code here
        if(num_items==0){
            head=NULL;
            tail=head;
            cout<<"Nothing to delete!"<<endl;
            return;
        }

        while(head!=NULL){
            delete head;
            num_items--;
            head=head->next;
            if(head==NULL)tail=NULL;

        }
    } // End of delete_all function







    /******************** PRINT *************************************/

    /**
     * This method prints the queue.
     */
    template <typename T>
    void queue<T>::print(){
        if (num_items == 0 ){
            std::cout << "Queue is empty"<< std::endl;
        }
        else{
            Node<T>* iter = head;
            while( iter != nullptr ){
                std::cout << iter->data << " ";
                iter = iter->next;
            }
            std::cout << std::endl;
        }
        if (head == nullptr)
            std::cout << "Head Points to: Null " << std::endl;
        else
            std::cout << "Head Points to: "<< head->data << std::endl;
        if (tail == nullptr)
            std::cout << "Tail Points to: Null " << std::endl;
        else
            std::cout << "Tail Points to: "<< tail->data << std::endl;
        std::cout << "Number of items in the queue: "<< num_items << std::endl;

    } /*  end of print method    */

} // end of namespace ubcse


#endif
