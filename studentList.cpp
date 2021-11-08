#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
  char name[20];
  char lastName[20];
  int id;
  float gpa;
};

void parseTheCommandAndDoStuff(char input[], vector<Student*> *studentList);
void addCommand(vector<Student*> *studentList);
void printCommand(vector<Student*> *studentList);
void deleteCommand(vector<Student*> *studentList);

int main() {
  bool isRunning = true;
  vector<Student*> studentList;

  //Main loop
  while(isRunning) {
    char input[20];
    cout << "Enter command: ";
    cin.getline(input, 20);
    //If command is QUIT...
    if(!strcmp(input, "QUIT")) {
      //End the main loop.
      isRunning = false;
    }
    //Otherwise, parse the command.
    else {
      parseTheCommandAndDoStuff(input, &studentList);
    }
  }
  return 0;
}
//Parses commands that aren't QUIT.
void parseTheCommandAndDoStuff(char input[], vector<Student*> *studentList) {
  if(!strcmp(input, "ADD")) {
    addCommand(studentList);
  }
  else if(!strcmp(input, "PRINT")) {
    printCommand(studentList);
  }
  else if(!strcmp(input, "DELETE")) {
    deleteCommand(studentList);
  }
  else {
    cout << "Command not recognized" << endl;
  }
}
//Adds a member to studentList with prompted attributes.
void addCommand(vector<Student*> *studentList) {
  Student* newStudent = new Student();
  cout << "Student first name: ";
  cin.getline(newStudent->name, 20);
  cout << "Student last name: ";
  cin.getline(newStudent->lastName, 20);
  cout << "Student ID number: ";
  cin >> newStudent->id;
  cout << "Student GPA: ";
  cin >> newStudent->gpa;

  cout << "Student added." << endl;
  studentList->push_back(newStudent);
  cin.ignore();
}
//Iterates through studentList and prints the members.
void printCommand(vector<Student*> *studentList) {
  cout << endl;
  for(int index = 0; index < studentList->size(); index++) {
    cout << "--" << studentList->at(index)->name << " ";
    cout << studentList->at(index)->lastName << "--" << endl;
    cout << "Student ID: " << studentList->at(index)->id << endl;
    cout << "GPA: " << studentList->at(index)->gpa << endl << endl;
  }
}
//Deletes the prompted Student from studentList using vector::erase.
void deleteCommand(vector<Student*> *studentList) {
  int input;
  bool successful = false;
  cout << "Student ID: ";
  cin >> input;
  //Iterate through studentList...
  for(int index = 0; index < studentList->size(); index++) {
    //checking for prompted ID
    if(studentList->at(index)->id == input) {
      studentList->erase(studentList->begin() + index);
      successful = true;
    }
  }
  if(successful) {
    cout << "Student deleted." << endl;
  }
  else {
    cout << "Couldn't find student with ID: " << input << endl;
  }
  cin.ignore();
}
