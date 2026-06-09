#include "LinkedListQueue.h"

using namespace std;

int main(){
    LinkedListQueue q;

    int choice;

    do{
        cout << "===============LIST===============" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Init Capacity" << endl;
        cout << "2. Enqueue Element" << endl;
        cout << "3. Dequeue Element" << endl;
        cout << "4. Peek of Queue" << endl;
        cout << "5. Check queue is empty?" << endl;
        cout << "6. Check queue is full?" << endl;
        cout << "7. Clear the queue" << endl;
        cout << "==================================" << endl;

        cout << "Input the choice (from 0 to 7): ";
        cin >> choice;

        if(choice == 0) break;
        else if(choice == 1){
            cout << "Enter Capacity of the Queue: ";
            int capacity; 
            cin >> capacity;
            q.init(capacity);
        }
        else if(choice == 2){
            int val;
            if(q.isFull()){
                cout << "The Queue is Full" << endl;
            }
            else{
                cout << "Enqueue Element of the Queue: ";
                cin >> val;
                q.enqueue(val);
            }
        }
        else if(choice == 3){
            int ans = q.dequeue();
            cout << "Dequeue Element of the Queue: " << ans << endl;
        }
        else if(choice == 4){
            int ans = q.peek();
            cout << "Peek the Queue: " << ans << endl;
        }
        else if(choice == 5){
            if(q.isEmpty()) cout << "The Queue is Empty" << endl;
            else cout << "The Queue is not Empty" << endl;
        }
        else if(choice == 6){
            if(q.isFull()) cout << "The Queue is Full" << endl;
            else cout << "The Queue is not Full" << endl;
        }
        else if(choice == 7){
            q.clear();
        }
    }while(choice != 0);

    return 0;
}