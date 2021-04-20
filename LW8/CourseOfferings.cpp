#include <iostream>
#include <string>
#include "Course.h"
#include "Section.h"
#include "CourseOfferings.h"

using std::cout, std::endl, std::string, std::ostream;

/* TODO: Define copy constructor here. */
CourseOfferings::CourseOfferings(const CourseOfferings& origObj)
{
	cout << "copy constructor called" << endl;
	//What the book example suggested
	year = new int;
	semester = new char;
	nbSections = new size_t;
	capacity = new size_t;
	course = new Course;
	sectionList = new sectionList;

	*year = *(origObj.year);
	*semester = *(origObj.semester);
	*nbSections = *(origObj.nbSections);
	*capacity = *(origObj.capacity);
	*course = *(origObj.course);
	*sectionList = *(origObj.sectionList);

	//What I had to do to make the DIY book example work
	// year = origObj.year;
	// semester = origObj.semester;
	// nbSections = origObj.nbSections;
	// capacity = origObj.capacity;
	// course = origObj.course;
	// sectionList = origObj.sectionList;

}

/* TODO: Define copy assignment operator function here. */
CourseOfferings& CourseOfferings::operator=(const CourseOfferings& objToCopy)
{
	cout << "assignment operator called" << endl;
	if(this != &objToCopy)
	{
		delete course;
		delete year;
		delete semester;
		delete nbSections;
		delete capacity;
		delete sectionList;
		course = new Course;
		*course = *(objToCopy.course);
		year = new int;
		*year = *(objToCopy.year);
		semester = new char;
		*semester = *(objToCopy.semester);
		nbSections = new size_t;
		*nbSections = *(objToCopy.nbSections);
		capacity = new size_t;
		*capacity = *(objToCopy.capacity);
		sectionList = new sectionList;
		*sectionList = *(objToCopy.sectionList);

	}
	return *this;
}

/* TODO: Define destructor here. */
CourseOfferings::~CourseOfferings()
{
	cout << "destructor called" << endl;
	delete[] sectionList;
}

/* TODO: Define CourseOfferings extractor operator overload here. */ 

CourseOfferings::CourseOfferings(Course course, unsigned int year, char semester) 
	: course(course), year(year), semester(semester), nbSections(0), capacity(0), sectionList(nullptr) { }

CourseOfferings::CourseOfferings(unsigned int year, char semester, const CourseOfferings& other)
	: CourseOfferings(other) {
	this->year = year;
	this->semester = semester;
}

void CourseOfferings::addSection(const Section& section) {
	if (nbSections == capacity) {
		increaseSectionListCapacity();
	}
	sectionList[nbSections++] = section;
}

void CourseOfferings::increaseSectionListCapacity() {
	// increase capacity
	capacity = capacity == 0 ? 1 : capacity * 2;
	if (capacity == 0) {
		capacity = 1;
		sectionList = new Section[1] {}; // initialize section list
	}

	// copy old contents to new contents
	Section* newSectionList = new Section[capacity];
	for (size_t i = 0; i < nbSections; ++i) {
		newSectionList[i] = sectionList[i];
	}

	// deallocate old contents
	delete[] sectionList;

	// set old contents to new contents
	sectionList = newSectionList;
}

bool operator==(const CourseOfferings& lhs, const CourseOfferings& rhs) {
	// checking year
	if (! (lhs.getYear() == rhs.getYear()
		&& lhs.getSemester() == rhs.getSemester()
		&& lhs.getCourse().getId() == rhs.getCourse().getId()
		&& lhs.getCourse().getTitle() == rhs.getCourse().getTitle()
		&& lhs.getNumberSections() == rhs.getNumberSections()
		&& lhs.getSectionListCapacity() == rhs.getSectionListCapacity())) {
		return false;
	}

	// checking sections
	for (size_t i = 0; i < lhs.getNumberSections(); i++) {
		Section ls = lhs.getSectionList()[i];
		Section rs = rhs.getSectionList()[i];
		if (!(ls.getId() == rs.getId()
				&& ls.getTime() == rs.getTime()
				&& ls.getLocation() == rs.getLocation()
				&& ls.getInstructor() == rs.getInstructor())) {
			return false;
		}
	}
	return true;
}
