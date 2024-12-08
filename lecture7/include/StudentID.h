#include<string>
class StudentID{
	protected :
		std::string name;
		std::string sunet;
		int idNumber;
	public:
		StduentID(std::string name,std::string sunet,int idNumber);
		StduentID();
		std::string getName();
		std::string getSunet();
		int getIdNumber();
};
