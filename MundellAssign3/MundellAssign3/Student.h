#pragma once
#include <string>
using namespace std; 

//Class object for student
class Student {
private:
	int id;
	string name;
	double gpa;


public:
	//Constructor with default values
	Student(int newId = 901819149, string newName = "Bob", double newGpa = 4.0) {
		id = newId;
		name = newName;
		gpa = newGpa;
	}
	//Default Constructor
	Student() {
		id = 901819149;
		name = "Isaac";
		gpa = 4.0;
	}
	
	//Overloaded operator, this was hard
	bool operator<(Student &s2) const {
		return id < s2.GetId();
	}
	bool operator>(Student &s2) const {
		return id > s2.GetId();
	}


	const int GetId(){
		return id;
	}
	string GetName() {
		return name;
	}
	double GetGPA() {
		return gpa;
	}

	void SetId(int newId) {
		id = newId;
	}
	void SetName(string newName) {
		name = newName;
	}
	void SetGPA(double newGpa) {
		gpa = newGpa;
	}
};

//Put here for simplicity, displays a vector of students
void DisplayVectorStudent(vector<Student> &vec) {

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].GetName() << ", ";
	}
	cout << endl;

}
