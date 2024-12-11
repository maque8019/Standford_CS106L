#include<fstream>
#include<functional>
#include<iostream>
#include<map>
#include<sstream>
void classExample(){
	std::string lecturing="1 2 3 4 5 6";
	std::stringstream ss;
	ss<<lecturing;
	int one,two,three,four;
	std::string five,six;
	ss>>one;
	ss>>two;
	ss>>three;
	ss>>four>>five>>six;
	std::cout<<one+two+three+four<<std::endl;
}
int outputFileStreamCodeTruncate(){
	std::ofstream ofs("truncate.txt");
	if(ofs.is_open()){
		ofs<<"Hello CS106L!"<<'\n';
	}
	ofs.close();
	ofs<<"this will not get written";
	ofs.open("truncate.txt");
	ofs<<"test";
	return 0;
}
int outputFileStreamCodeAppend(){
	std::ofstream ofs("append.txt");
	if(ofs.is_open()){
		ofs<<"Hello CS106L!"<<'\n';
	}
	ofs.close();
	ofs<<"this will not get written";
	ofs.open("append.txt",std::ios::app);
	ofs<<"this will  though!it's open again";
	ofs.close();
	return 0;
}
int inputFileStreamExample(){
	std::ifstream ifs("append.txt");
	if(ifs.is_open()){
		std::string line;
		std::getline(ifs,line);
		std::cout<<"Read the first line"<<line<<'\n';
	}
	if(ifs.is_open()){
		std::string linetwo;
		std::getline(ifs,linetwo);
		std::cout<<"Read the second line"<<linetwo<<'\n';
	}
	return 0;
}
void cinFailure(){
	double pi;
	double tao;
	std::string name;
	std::cin>>name;
	std::cin>>pi;
	std::cin>>tao;
	std::cout<<"name is"<<name<<"  "<<"pi: "<<pi<<"tao: "<<tao<<std::endl;
}
void cinGetlineBug() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;
  std::getline(std::cin, name);
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

void cinActuallyFixed() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;
  std::getline(std::cin, name);
  std::getline(std::cin, name);
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

int testFstream() {
  std::fstream fs("append.txt", std::ios::in | std::ios::out | std::ios::app);
  if (fs.is_open()) {
    fs << "Hello CS106L!" << '\n';
    fs.seekg(0, std::ios::beg);
    std::string line;
    std::getline(fs, line);
    std::cout << "Read from the file: " << line << '\n';
    std::string lineTwo;
    std::getline(fs, lineTwo);
    std::cout << "Read from the file: " << lineTwo << '\n';
  } else {
    std::cout << "Whoops the file is not open!" << '\n';
  }
  fs.close();

  return 0;
}

int main(){
	std::map<std::string,std::function<void()>>functionMap={{"testFstream",testFstrean},{"cinActuallyFixed",cinActuallyFixed},{"cinFailure",cinFailure},{"inputFileStreamExample",inputFileStreamExample},{"outputFileStreamCodeAppend",outputFileStreamCodeAppend},{"classExample",classExample},{"outputFileStreamCodeTruncate",outputFileStreamCodeTruncate}};
	std::string inputFunctionName;
	while(true){
		std::cout<<"\nYou can run one of these functions:\n";
		for(const auto &pair : functionMap){
			std::cout<<pair.first<<'\n';
		}
		std::cout<<"\nEnter the name of the function you want to run(or 'exit' " "to quit):";
		std::getline(std::cin,inputFunctionName);
		if(inputFunctionName=="exit"){
			break;
		}
		auto iter=functionMap.find(inputFunctionName);
		if(iter!=functionMap.end()){
			std::cout<<"\n###### OUTPUT ######\n";
			iter->second();
		}
		else{
			std::cout<<"Function name not recognized. Please try again."<<std::endl;
		}
	}
	return 0;
}

