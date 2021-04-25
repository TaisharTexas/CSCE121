#include <iostream>
#include <string>
#include "Course.h"
#include "Section.h"
#include "CourseOfferings.h"

using std::cout, std::endl, std::string, std::ostream;

/* TODO: Define copy constructor here. */
CourseOfferings::CourseOfferings(const CourseOfferings& co)
		: course(co.course),
			year(co.year),
			semester(co.semester),
			nbSections(co.nbSections),
			capacity(co.capacity),
			sectionList(nullptr)

{
		sectionList = new Section[nbSections];
		for(unsigned int i = 0; i < nbSections; i++)
		{
				sectionList[i] = co.sectionList[i];
		}
}

/* TODO: Define copy assignment operator function here. */
CourseOfferings& CourseOfferings::operator=(const CourseOfferings& co)
{
		course = co.course;
		year = co.year;
		semester = co.semester;
		nbSections = co.nbSections;
		capacity = co.capacity;
		delete[] sectionList;
		sectionList = new Section[nbSections];
		for(size_t i = 0; i < nbSections; i++)
		{
				sectionList[i] = co.sectionList[i];
		}

		return *this;
}

/* TODO: Define destructor here. */
CourseOfferings::~CourseOfferings()
{
		delete[] sectionList;
}

/* TODO: Define CourseOfferings extractor operator overload here. */
std::ostream& operator<<(std::ostream& os, const CourseOfferings& co)
{
    os << "Year: " << co.getYear() << " Semester: " << co.getSemester() << " Course id: " << co.getCourse().getId() << endl;
		os << "Course title: " << co.getCourse().getTitle() << endl;
		os << "Sections:" << endl;
		// os << getSectionList();
    return os;
}


//default constructor
CourseOfferings::CourseOfferings(Course course, unsigned int year, char semester)
		: course(course),
			year(year),
			semester(semester),
			nbSections(0),
			capacity(0),
			sectionList(nullptr)
{ }

//full constructor
CourseOfferings::CourseOfferings(unsigned int year, char semester, const CourseOfferings& other)
		: CourseOfferings(other)
{
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
