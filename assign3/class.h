#include<string>

class Class{
	private :
		double score;
		void grade(double score);

	 	std::string name;
	 	std::string major;
	 	std::string dormitory;
		 int id;
	public:
	 Class();
	Class(const std::string &name,const std::string& major,const std::string& dormitory,int id);
	std::string getName() const;
	bool setGrade(double score);
	std::string getMajor() const;
	std::string getDormitory() const;
	int getId() const;
	void setName(const std::string & name);
	void setMajor(const std::string& major);
	void setDormitory(const std::string& dormitory);
	void setId(int id);
	~Class()=default;
};

