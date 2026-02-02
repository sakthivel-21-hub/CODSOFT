#include<iostream>
#include<vector>
#include<string>    
using namespace std;
struct Task{
    string task_name;
    bool isCompleted;
};
vector<Task> tasklist;

void addTask(){
    cout<<"\n---Add New Task---\n";
    cout <<"Enter task name :";
    string task;
    getline(cin, task);
     Task newTask = {task ,false};
     tasklist.push_back(newTask);
     cout <<"Task added successfully...!";
}

void viewTask(){
    cout<<"\n--- your To-Do List ---\n";
    if(tasklist.empty()){
        cout<<"TaskList is empty.some task...!"<< endl ;
    }
    cout<<"ID---taskname---status:\n";
    for (int i =0;i < tasklist.size();i++){
        string status = tasklist[i].isCompleted ? "[COMPLETED]":"[PENDING]";
        //
        cout <<i+1<<"."<<tasklist[i].task_name<<status<< endl;
    }

}

void markTaskcompleted(){
    if (tasklist.empty()) {
        cout << "\nNo tasks to mark.\n";
        return;
    }
    viewTask();
    cout <<"Enter ID of the task to mark completed:";
    int x;
    cin>>x;
    if(x>0 and x<= tasklist.size()){
        tasklist[x-1].isCompleted=true;
        cout << "Task is "<<tasklist[x-1].task_name<<"successfully marked completed"<<endl;
        viewTask();
    }else{
        cout <<"invalid id"<< endl;
    }
}

void removeTask(){
    if(tasklist.empty()){
        cout<<"TaskList is empty.some task...!"<< endl ;
    }
    viewTask();
    int x ;
    cout <<"Enter Task ID to remove :";
    cin>>x;
    if(x>0 and x<= tasklist.size()){
        tasklist.erase(tasklist.begin() + (x-1));    
    cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid ID!\n";
    }
}
int main(){
    int choice=0;
    while (choice != 5) {
        cout << "\n=========================";
        cout << "\n   TO-DO LIST MANAGER";
        cout << "\n=========================\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cin.ignore();
                addTask();
                break;
            case 2: 
                viewTask(); 
                break;
            case 3: 
                markTaskcompleted(); 
                break;
            case 4: 
                removeTask(); 
                break;
            case 5: 
                cout << "Exiting program. Goodbye....!\n"; 
                break;
            default:  
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}