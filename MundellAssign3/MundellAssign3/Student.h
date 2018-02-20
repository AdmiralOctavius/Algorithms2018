#pragma once
#include <string>
using namespace std; 

class Student {
private:
	int id;
	string name;
	double gpa;


public:
	Student(int newId = 901819149, string newName = "Bob", double newGpa = 4.0) {
		id = newId;
		name = newName;
		gpa = newGpa;
	}
	Student() {
		id = 901819149;
		name = "Isaac";
		gpa = 4.0;
	}
	//Can't get const Student &s2 to work
	/*bool operator<(Student &s2) const{
		if (id < s2.GetId()) {
			return true;
		}
		else {
			return false;
		}
	}*/
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