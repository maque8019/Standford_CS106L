#include<vector>
#include<iostream>
#include<map>
#include<functional>
#include<string>
#include<deque>
void vectorExample(){
	std::vector<int> vec{ 1, 2, 3, 4};
	vec.push_back(5);
	vec.push_back(6);
	vec[1]=20;
	for(size_t i =0; i < vec.size(); i++){
		std::cout<< vec[i]<<" ";
	}

	std::cout<<vec.at(2)<<std::endl;
	for(const auto& elem : vec){
		std::cout<<elem<<" ";
	}
}
void receivePrice(deque<double>& prices,double price){
	prices.push_front(price);
	if(prices.size()>1000)
		prices.pop_back();
}
void mapExample(){
	std::map<std::string,int> map{
		{"Chris",2},
		{"CS106L",42},
		{"Keith",14},
		{"Nick",51},
		{"Sean",35},
	};
	int sean=map["Sean"];
	map["Chris"] = 31;
	std::cout<<sean<<std::endl;
	for(auto kv : amp){
		std::string key=kv.first;
		int value=kv.second;
		std::cout<<"key: "<<key<<"value: "<<value<<std::endl;
	}
}

int main(){
	std::map<std::string,std::function<void()>> functionMap = {{"vectorExample",vectorExample},{"mapExample",mapExample}};
	std::string inputFunctionName;
	while(true){
		std::cout<<"\nYou can run one of the function.\n";
		for(const auto& pair:functionMap){
			std::cout<<pair.first<<"\n";
		}
		std::cout<<"\nEnter the name of the function you want to run(or'exit' to quit):";
		std::getline(std::cin,inputFunctionName);
		if(inputFunctionName=="exit"){
			break;
		}
		auto iter=functionMap.find(inputFunctionName);
		if(iter!=functionMap.end()){
			std::cout<<"\n######OUTPUT#####\n";
			iter->second();
		}
		else{
			 std::cout<<"Function name not recognized. Please try again."<<std::endl;
		}
	}
	return 0;
}

