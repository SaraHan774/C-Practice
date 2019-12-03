/* Possible Solution for Homework 3.
 * The proposed solution is quite basic.
 * All arrays are of fix size ...
 * and there are a lot of range checks missing ....
 */

#include <iostream>

/* Simple copy function for c-strings */
void stringCopy( char *dest, const char *src )
{
	while( *src != 0 )
		*dest++ = *src++;
	*dest = '\0';
} // function

/* problem d) */
class Course {
public:
	int Id; // Course Id
	char Instructor[100]; // Name of Instructor
	int RoomNr; // Room number

	// default constructor
	Course() {
		this->reset();
	} // constructor

	// resets the data of the current course
	void reset( void )
	{
		this->Id = 0; 
		this->Instructor[0] = '\0'; // creates empty string
		this->RoomNr = 0;
	} // method
}; // class

/* problem a) */
class Student {
private: // problem b)
	char Name[100]; // Name of student
	int Number;  // Number of student
	int Courses[10]; // Courses booked by student. We use the course Id (type int) over here! 

public:
	// Default Constructor (problem c) )
	Student() 
	{
		Number = 0;
		Name[0] = '\0';
		for( int i = 0; i < 10; i++ )
			Courses[i] = 0;
	} // constructor

	// Parameterized Constructor (problem c) )
	Student( int IntialNumber,
			 const char *InitialName )
	{
		Number = IntialNumber;
		this->setName( InitialName );
		for( int i = 0; i < 10; i++ )
			Courses[i] = 0;
	} // constructor
	
	// getter for number attribute
	int getNumber( void )
	{
		return this->Number;
	} // method

	// setter for number attribute
	void setNumber( int NewNumber )
	{
		this->Number = NewNumber;
	} // method

	// getter for name attribute
	char* getName( void ) 
	{ 
		return this->Name; 
	} // method
	
	// setter for name attribute
	void setName( const char *NewName ) 
	{
		stringCopy( this->Name, NewName );
	} // method

	// getter for course at index
	int getCourse( int Index )
	{
		return Courses[Index];
	} // method

	// setter for course at index
	void setCourse( int Index, int courseId )
	{
		this->Courses[Index] = courseId;
	} // method

	// adds a new course at first free spot
	void addCourse( int courseId )
	{
		for( int i = 0; i < 10; i++ )
		{
			if( Courses[i] == 0 )
				Courses[i] = courseId;
		} // for
	} // method

	// checks wether for course visit
	bool visitsCourse( int CourseId )
	{
		for( int i = 0; i < 10; i++ )
		{
			if( Courses[i] == CourseId )
				return true;
		} // for
		return false;
	} // method
}; // class

/* Problem f) */
void queryStudents( Student *students, int studentsSize, int courseId )
{
	for( int i = 0; i < studentsSize; i++ )
	{
		if( students[i].visitsCourse( courseId ) )
		{
			std::cout << "The student with number " << students[i].getNumber()
				<< " and name " << students[i].getName()
				<< " visits the course with ID " << courseId << std::endl;
		} // if
	} // for
} // function

/* Problem e) */
void manageCourses( Course *courses, int coursesSize,
					Student *students, int studentsSize )
{
	while( true )
	{
		std::cout << "1: Change course data, 2: Query Students, 3: Assign Student to Course, 0:Back" << std::endl;
		int selection;
		std::cin >> selection;
		if( selection == 0 )
			break;
		switch( selection ) {
		case 1: 
			std::cout << "Index in Course Array (0..9):" << std::endl;
			int index;
			std::cin >> index;
			std::cout << "Course Id (int):" << std::endl;
			int courseId;
			std::cin >> courseId;
			std::cout << "Instructor Name:" << std::endl;
			char InstructorName[100];
			std::cin >> InstructorName;
			std::cout << "Course Room Nr (int):" << std::endl;
			int courseRoomNr;
			std::cin >> courseRoomNr;

			stringCopy( courses[index].Instructor, InstructorName );
			courses[index].Id = courseId;
			courses[index].RoomNr = courseRoomNr;
			std::cout << "At index " << index 
				<< " the Course Id is " << courses[index].Id 
				<< " and the Instructor Name is " << courses[index].Instructor 
				<< " and the Room Nr is " << courses[index].RoomNr
				<< std::endl;
			break;
		case 2: 
			std::cout << "Course Id (int):" << std::endl;
			std::cin >> courseId;
			queryStudents( students, studentsSize, courseId );
			break;
		case 3: 
			std::cout << "Course Id (int):" << std::endl;
			std::cin >> courseId;
			std::cout << "Index in Student Array (0..9):" << std::endl;
			std::cin >> index;
			students[index].addCourse(courseId);
			break;
		default:
			std::cout << "Wrong input";
		} // switch
	} // while
} // function

/* Problem e) */
void manageStudents( Student *students, int studentsSize )
{
	while( true )
	{
		std::cout << "1: Change student data, 0:Back" << std::endl;
		int selection;
		std::cin >> selection;
		if( selection == 0 )
			break;
		std::cout << "Index in Student Array (0..9):" << std::endl;
		int index;
		std::cin >> index;
		std::cout << "Student Number:" << std::endl;
		int studentNumber;
		std::cin >> studentNumber;
		std::cout << "Student Name:" << std::endl;
		char studentName[100];
		std::cin >> studentName;
		students[index].setName( studentName );
		students[index].setNumber( studentNumber );
		std::cout << "At index " << index 
			<< " the Student Number is " << students[index].getNumber() 
			<< " and the Student Name is " << students[index].getName() << std::endl;
	} // while
} // function

/* Problem e) */
int main () {
	Student students[10]; // array for 10 students
	Course courses[10];// array for 10 courses
	while( true )
	{
		std::cout << "1: Manage Courses, 2: Manage Students, 0:Exit" << std::endl;
		int selection;
		std::cin >> selection;
		if( selection == 0 )
			break;
		switch( selection ) {
		case 1: manageCourses( courses, 10, students, 10 );
			break;
		case 2: manageStudents( students, 10 );
			break;
		default:
			std::cout << "Wrong input";
		} // switch
	} // while

    return 0;
} // main
