#include<string>
#include"class.h"
#include<iostream>
Class::Class():name(""),major(""),dormitory(""),id(0){};
Class::Class(const std::string& name,const std::string& major,const std::string& dormitory,int id):name(name),major(major),dormitory(dormitory),id(id){
			std::cout<<"Student constructor"<<std::endl;
}
void Class::grade(double score){
	this->score=score;
}
bool Class::setGrade(double score){
	grade(score);
	return true;
}
std::string Class::getName()const{
	return name;
}
std::string Class::getMajor()const{
	return major;
}
std::string Class::getDormitory()const{
	return dormitory;
}
int Class::getId()const {
	return id;
}
void Class::setName(const std::string& name){
	this->name=name;
}
void Class::setMajor(const std::string &major){
	this->major=major;
}
void Class::setDormitory(const std::string &dormitory){
	this->dormitory=dormitory;
}


void Class::setId(int id){
	this->id=id;
}



