#include<string>
#include"Employee.h"
#include<vector>
class SectionLeader :public Student,public Employee{
    protected:
        std::string section;
        std::string course;
        std::vector<std::string> student;
    public:
        SectionLeader(const std::string &name,const std::string &idNumber,const std::string major,const std::string advisor,uint16_t year,const std::string& section,const std::string& course,double salary);
        std::string getSection()const;
        std::string getCourse()const;
        void addStudent(const std::string& student);
        void removeStudent(const std::string& student);
        std::vector<std::string> getStudent()cosnt;
        std::string getRole() const override;
        double getSalary() const override;
        void setSalary(double salary) override;
        ~SectionLeader();      
};