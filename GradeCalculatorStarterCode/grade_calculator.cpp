// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;
using std::max, std::min;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade,
                   double numOfExams);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    double exam = 0;
    double final_exam = 0;
    double homework = 0;
    double labwork = 0;
    double studentEngagement = 0;
    int numExams = 0;
    int numHW = 0;
    int numLW = 0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            exam += score;
            ++numExams;
        } else if (category == "final-exam") {
            final_exam = score;
            ++numExams;
        } else if (category == "hw") {
            homework += score;
            ++numHW;
        } else if (category == "lw") {
            labwork += score;
            ++numLW;
        } else if (category == "engagement") {
            studentEngagement += score;
        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
    double exam_average = ((exam + final_exam) / numExams);  //40% of grade
    if (final_exam > exam_average) {
        exam_average = final_exam;
    }
    double hw_average = (homework / numHW);  //40% of grade
    double lw_average = (labwork / numLW) * 100;  //10% of grade
    double engagement = max(0.0, min(studentEngagement, 100.0)); //max 100 pts, 10% of grade

    // TODO(student): compute weighted total of components
    double weighted_total = ((exam_average * .4) + (hw_average * .4) + (lw_average / 10) + (engagement * .1));

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if (weighted_total >= 90){
        final_letter_grade = 'A';
    }
    else if (weighted_total >= 80){
        final_letter_grade = 'B';
    }
    else if (weighted_total >= 70){
        final_letter_grade = 'C';
    }
    else if (weighted_total >= 60){
        final_letter_grade = 'D';
    }
    else{
        final_letter_grade = 'F';
    }

    print_results(
        exam_average, hw_average, lw_average, engagement,
        weighted_total, final_letter_grade, numExams);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}


void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double engagement,
    double weighted_total,
    char final_letter_grade,
    double numOfExams) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "      num of exams: " << numOfExams << endl;
    cout << "     ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
