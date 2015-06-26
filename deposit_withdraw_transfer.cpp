#include <iostream>
#include <string>
#include "bank_system.h"
using namespace std;

extern map<string, Account> accountMap;
extern map<string, Account>::iterator current_login;
extern unsigned int timestamp;

void deposit(int money){
	current_login->second.money += money;
	cout << "success, " << current_login->second.money << " dollars in current account\n";
	return;
}

void withdraw(int money){
	if(current_login->second.money < money){
		cout << "fail, " << current_login->second.money << " dollars only in current accout\n";
	}
	else{
		current_login->second.money -= money;
		cout << "success, " << current_login->second.money << "dollars left in current account\n";
	}
	return;
}

void transfer(string id, int money){ // TODO: add timestamp to the record
	map<string, Account>::iterator it;
	it = accountMap.find(id);
	if(it == accountMap.end()){
		cout << "ID " << id << " not found, ";
		// TODO: recommand best 10 existing ids
	}
	else{
		if(current_login->second.money < money){
			cout << "fail, " << current_login->second.money << " dollars only in current accout\n";
		}
		else{
			current_login->second.money -= money;
			it->second.money += money;
			cout << "success, " << current_login->second.money << "dollars left in current account\n";
		}
	}
	return;
}



