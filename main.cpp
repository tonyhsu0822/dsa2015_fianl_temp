#include <iostream>
#include <string>
#include "bank_system.h"
using namespace std;

map<string, Account> accountMap;
map<string, Account>::iterator current_login;
unsigned int timestamp;

int main(){
	string cmd;
	string id1, id2;
	string passwd1, passwd2;
	string wildcard_id;
	int money;
	
	while(1){
		cin >> cmd;
		if(cmd == "login"){
			cin >> id1 >> passwd1;
			login(id1, passwd1);
		}
		else if(cmd == "create"){
			cin >> id1 >> passwd1;
			create(id1, passwd1);
		}
		else if(cmd == "delete"){
			cin >> id1 >> passwd1;
			myDelete(id1, passwd1);
		}
		else if(cmd == "merge"){
			cin >> id1 >> passwd1 >> id2 >> passwd2;
			merge(id1, passwd1, id2, passwd2);
		}
		else if(cmd == "deposit"){
			cin >> money;
			deposit(money);
		}
		else if(cmd == "withdraw"){
			cin >> money;
			deposit(money);
		}
		else if(cmd == "transfer"){
			cin >> id1 >> money;
			transfer(id1, money);
		}
		else if(cmd == "find"){
			cin >> wildcard_id;
			myFind(wildcard_id);
		}
		else if(cmd == "search"){
			cin >> id1;
			search(id1);
		}
		else{
			cout << "unknown command\n";
			break;
		}
	}
	return 0;
}




