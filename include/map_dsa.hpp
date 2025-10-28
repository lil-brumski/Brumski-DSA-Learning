#pragma once

#include <map>
#include <string>
#include <utility>
#include <list>
#include <iostream>

void UsingMap() {
	std::cout << "\nMAP (1) DATA STRUCTURE" << std::endl;

	std::map<std::string, std::pair<std::string, std::string>> students;
	students.emplace("7890", std::pair{ "David", "Tamaratare" });
	students.emplace("7891", std::pair{"David", "Tamaralayefa"});
	students.emplace("7892", std::pair{"Daniel", "Mark"});

	std::cout << "The student with a MATRIC. NO. of 7890 is " << students["7890"].first << " " << students["7890"].second << std::endl;
}

void UsingMap2() {
	std::cout << "\nMAP (2) DATA STRUCTURE" << std::endl;

	std::map<std::string, std::list<std::string>> students;
	students.emplace("7890", std::list<std::string>{"David", "Tamaratare", "Oghenebrume"});
	students.emplace("7891", std::list<std::string>{"David", "Tamaralayefa"});
	students.emplace("7892", std::list<std::string>{"David", "Oghenebrume"});

	for (auto& student : students) {
		std::cout << "The student with a MATRIC. NO. of " << student.first << " is ";
		for (auto& name : student.second) {
			std::cout << name << " ";
		}
		std::cout << std::endl;
	}
}