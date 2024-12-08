#include"../include/Student.h"
#include<cstdint>
#include<iostream>
Student ::Student(const std::string&name,const std::string &idNumber,\
const std::string&major,const std::string&advisor,
uint16_t year){
    this->name=name;
    this->idNumber=idNumber;
    this->major=major;
    this->year=year;
    this->advisor=advisor;
    std::cout<<"Student constructor"<<std::endl;

}
std::string Student::getAdvisor() const{
    return advisor;
}
std::string Student::getIdNumber()const{
    return idNumber;
}
std::string Student::getMajor()const{
    return major;
}
void Student::setAdvisor(const std::string& advisor){
    this->advisor=advisor;
}
void Student::setMajor(const std::string &major){
    this->major=major;
}
void Student::setYear(uint16_t year){
    this->year=year;
}
