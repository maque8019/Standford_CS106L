#include"../include/StudentID.h"
#include<string>
StduentID::StduentID{
    name="wph";
    sunet="jappend";
    idNumber= 1234;
}
StudentID::StudentID(std::string &name,std::string& sunet,int idNumber){
    this->name=name;
    this->sunet=sunet;
    if(idNumber>=0){
    this->idNumber=idNumber;
    }else{
        this->idNumber=0;
    }
}
std::string StduentID:: getName(){
    return name;
}
std::string StduentID::getSunet(){
    return sunet;
}
int StduentID::getIdNumber(){
    return idNumber;
}