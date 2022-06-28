#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface {
public:
  vector <string> tasks;
  TodoList() {
    ifstream infile ("TODOList.txt");
    string line;
      if (infile.is_open()) {
        while ( getline (infile,line)) {
        tasks.push_back(line);
        }
      } 
      infile.close();
  }

  virtual ~TodoList() {
    ofstream outfile;
    outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
    for(int i = 0; i < tasks.size(); i++) {
      outfile << tasks[i] << endl;
    }
    outfile.close();
  }    

  virtual void add(string _duedate, string _task) {
    cout <<"Added: " << _duedate << " " << _task << endl;
    tasks.push_back(_duedate);
    tasks.push_back(_task);
  }

  virtual int remove(string _task) {
    for (int i = 0; i < tasks.size(); i++) {
      if (tasks[i] == _task) {
        tasks.erase(tasks.begin() + i);
        tasks.erase(tasks.begin() + i-1);
        cout << "Removed: " << _task << endl;
      }
    }
  }     

  virtual void printTodoList() {
    ofstream outfile;
    outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
    for (int i = 0; i < tasks.size(); i++) {
      cout << tasks[i] << endl;
      outfile << tasks[i] << endl;
    }
    outfile.close(); 
  }      
    
  virtual void printDaysTasks(string _date) {
    cout << _date << endl;
    for (int i = 0; i < tasks.size(); i++) {
      if (tasks[i] == _date) {
        cout << tasks[i+1] << endl;;
      }
    }
  }
};

#endif