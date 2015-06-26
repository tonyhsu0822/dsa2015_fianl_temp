#include <iostream>
#include <string>
#include "bank_system.h"
using namespace std;

extern map<string, Account> accountMap;
extern map<string, Account>::iterator current_login;
extern unsigned int timestamp;

void login(string id, string passwd){
	map<string, Account>::iterator it;
	it = accountMap.find(id);
	if(it == accountMap.end()){
		cout << "ID " << id << " not found\n";
	}
	else{
		if(md5(passwd) != it->second.passwd){
			cout << "wrong password\n";
		}
		else{
			cout << "success\n";
			// update the current login account
			current_login = it;
		}
	}
	
	return;
}

void create(string id, string passwd){
	map<string, Account>::iterator it;
	it = accountMap.find(id);
	if(it != accountMap.end()){
		cout << "ID " << id << " exists, ";
		// TODO: recommend best 10 usused ids
	}
	else{
		Account a(passwd);
		accountMap.insert( pair<string, Account>(id, a) );
		cout << "success\n";
	}
	
	return;
}

void myDelete(string id, string passwd){
	map<string, Account>::iterator it;
	it = accountMap.find(id);
	if(it == accountMap.end()){
		cout << "ID " << id << " not found\n";
	}
	else{
		if(md5(passwd) != it->second.passwd){
			cout << "wrong password\n";
		}
		else{
			accountMap.erase(it);
			cout << "success\n";
		}
	}
	
	return;
}


