#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Convert grade into gradepoint
float gradePoints(char grade, vector<char>& listOfGrades);

// display courses, grade, credithours and gpa and cgpa
void display(vector<string>& listOfCourses, vector<int>& listOfCredits, vector<char>& listOfGrades);

// display GPA and CGPA
static void displayCGPA(float totalGradePoints, int totalCreditHours);


int main() {
	vector<string> listOfCourses;
	vector<char> listOfGrades;
	vector<int> listOfCredits;
	string courseName;
	char grade;
	int numberOfCourses = 0;
	int creditHours = 0;
	float totalGradePoints = 0;
	int totalCreditHours = 0;

	cout << "Enter total number of courses: ";
	cin >> numberOfCourses; // get the total number of courses
	cout << "\n---Enter creditHours of and Grade obtained in each Course.---\n";

	for (int i = 0; i < numberOfCourses; i++) {

		cin.ignore(); // to clear the buffer for "getline"
		cout << "\nCourse " << i + 1 << ". Enter Name of Course: ";
		getline(cin, courseName); // get the name of the course
		listOfCourses.push_back(courseName); // add name of the course to the list

		cout << "\nCourse " << i + 1 << ". Enter Credit Hours: ";
		cin >> creditHours; // get credit hours of each subject
		listOfCredits.push_back(creditHours); // add creditHours to the list
		totalCreditHours += creditHours; // calculate total credit hours

		cout << "\nCourse " << i + 1 << ". Enter Your Grade: ";
		cin >> grade; // get grade
		totalGradePoints += creditHours * gradePoints(grade, listOfGrades); // calculte total grade pionts and add grade to the list
	}
	display(listOfCourses, listOfCredits, listOfGrades);
	displayCGPA(totalGradePoints, totalCreditHours);

	return 0;
}

float gradePoints(char grade, vector<char>& listOfGrades) {
	if (grade == 'A' || grade == 'a') {
		listOfGrades.push_back(grade); // add grade to the list
		return 4.0;
	}
	else if (grade == 'B' || grade == 'b') {
		listOfGrades.push_back(grade); // add grade to the list
		return 3.0;
	}
	else if (grade == 'C' || grade == 'c') {
		listOfGrades.push_back(grade); // add grade to the list
		return 2.0;
	}
	else if (grade == 'D' || grade == 'd') {
		listOfGrades.push_back(grade); // add grade to the list
		return 1.0;
	}
	else if (grade == 'F' || grade == 'f') {
		listOfGrades.push_back(grade); // add grade to the list
		return 0.0;
	}
	else { // if the input is invalid
		cout << "\nInvaild Grade. Enter a Valid Grade(A/B/C/D/F)\n";
		cin >> grade;
		return gradePoints(grade, listOfGrades);
	}
}

void display(vector<string>& listOfCourses, vector<int>& listOfCredits, vector<char>& listOfGrades) {
	cout << "The following format is used: ";
	cout << "\nCourses,   Credits,   Grade";
	for (int i = 0; i < listOfCourses.size(); i++) {
		cout << "\n";
		cout << i + 1 << ". " << listOfCourses[i];
		cout << ",   " << listOfCredits[i];
		cout << ",   " << listOfGrades[i];
	}
}

static void displayCGPA(float totalGradePoints, int totalCreditHours) {
	float GPA = totalGradePoints / totalCreditHours; // calculate GPA
	cout << "\nSemester GPA: " << GPA;
	float CGPA = 0.0;
	int CGPAcredits = 0;
	if (CGPA == 0.0) CGPA = GPA;
	else {
		CGPA = ((CGPA * CGPAcredits) + (GPA * totalCreditHours)) / (CGPAcredits + totalCreditHours); // formula for total CGPA calculation
	}
	cout << "\nCPGA: " << CGPA;
}



