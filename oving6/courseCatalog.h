#pragma once

#include <iostream>
#include <string>
#include <map>
#include <filesystem>
#include <fstream>



class CourseCatalog {
    private: 
    std::map<std::string, std::string> courses; 
    std::filesystem::path mapCSV{"courseCatalog.csv"};

    public: 
    void addCourse(std::string courseCode, std::string courseName);
    void removeCourse(std::string courseCode);
    std::string getCourse();
    friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& c);
    friend std::ostream& operator<<(std::ostream& os, const std::map<std::string, std::string>& map);

    void writeMapToFile();
    void readMapFromFile();
};

void testCourseCatalogAnOverlad();