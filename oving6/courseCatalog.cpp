#include "courseCatalog.h"


void CourseCatalog::addCourse(std::string courseCode, std::string courseName) {
    //std::string courseCode;
    //std::string courseName;
    //std::cout << "Enter course code: ";
    //std::cin >> courseCode;
    //std::cout << "\nEnter course name: ";
    //std::cin >> courseName;
    courses.insert({courseCode, courseName});
    //courses[courseCode] = courseName;
}



void CourseCatalog::removeCourse(std::string courseCode) {
    //std::string courseCode;
    //std::cout << "Enter course code: ";
    //std::cin >> courseCode;
    courses.erase(courseCode);
}

std::string CourseCatalog::getCourse() {
    std::string courseCode;
    std::cout << "Enter course code: ";
    std::cin >> courseCode;
    return courses.at(courseCode);
}

std::ostream& operator<<(std::ostream& os, const CourseCatalog& c) {
    std::cout << "Courses: " << std::endl;
    for (std::pair<const std::string&, const std::string&> element : c.courses) {
        os << element.first << "," << element.second << std::endl;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::map<std::string, std::string>& map) {
    std::cout << "Courses: " << std::endl;
    for (std::pair<const std::string&, const std::string&> element : map) {
        os << element.first << "," << element.second << std::endl;
    }
    return os;
}

void testCourseCatalogAnOverlad() {
    CourseCatalog c;
    c.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    c.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    c.addCourse("TMA4100", "Matematikk 2");
    c.addCourse("TDT4102", "C++"); // Fungerer ikke for å legge til.
    std::cout << c;
    c.writeMapToFile();
}

void CourseCatalog::writeMapToFile() {
    std::ofstream writeStream{mapCSV};
    writeStream << courses;
    writeStream.close();
}

void CourseCatalog::readMapFromFile() {
    std::ifstream readStream{mapCSV};
    if (readStream.is_open()) {
        std::string keyOrValue;
        while (getline(readStream, keyOrValue, ',')) {
            std::string key = keyOrValue;
            getline(readStream, keyOrValue);
            std::string value = keyOrValue;
            courses.insert({key, value});
        }
    }
    else {
        std::cout << "Kunne ikke åpne filen" << std::endl;
    }
    readStream.close();
}


// Metoden med å bruke courses[courseCode] = courseName fungerer for å oppdatere verdien av til TDT4102. 
// .at() metoiden vil være bedre for å få tilgang til en verdi, og oppdatere denne. Fordi den håndterer situasjoner hvor nøkkelen ikke finnes.
