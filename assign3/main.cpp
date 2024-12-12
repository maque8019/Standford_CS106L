/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include<iostream>
#include"class.h"
/* #### Please don't change this line! #### */
int run_autograder();

int main() {
	Class st{"wph","CS","C4-605",202022};
	std::cout<<"Name: "<<st.getName()<<std::endl;
	std::cout<<"Majory: "<<st.getMajor()<<std::endl;
	std::cout<<"Dormitory: "<<st.getDormitory()<<std::endl;
	std::cout<<"Id: "<<st.getId()<<std::endl;

  // STUDENT TODO: Construct an instance of your class!

  /* #### Please don't change this line! #### */
  return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"
