#include<iostream>
#include<cmath>
#include<utility>
using Zeros=std::pair<double,double>;
using Solution=std::pair<bool,Zeros>;
Solution  solveQuadratic(double a,double b, double c)
{
	double discrim=b*b-4*a*c;
	if(discrim<0){
		return {false,{10.0,250.0}};
	}
	else{
		discrim=sqrt(discrim);
		return {true,{(-b+discrim)/(2*a),(-b-discrim)/(2*a)}};
	}
}
int main()
{
	double a,b,c;
	std::cout<<"a: ";std::cin>>a;
	std::cout<<"b: ";std::cin>>b;
	std::cout<<"c: ";std::cin>>c;
	auto result=solveQuadratic(a,b,c);
	if(result.first){
		auto solutions=result.second;
		std::cout<<"Solutions: "<<solutions.first<<','<<solutions.second<<std::endl;
	}else{
		std::cout<<"No Solutions"<<std::endl;
	}
	return 0;
}
		
