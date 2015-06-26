#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

typedef struct{
	int from_to;
	string id;
	int money;
} History;

typedef struct{
	string passwd;
	int money;
	vector<History> history;
} Account;

/*
class Account{
	private:
		string passwd;
		int money;
		vector<History> history;
	public:
		string passwd(){
			return passwd;
		}
		
		Account(string password){
			passwd = password;
			money = 0;
		}
		
		~Account(){}
}
*/
// map<string, Account> accountMap;

void login(string id, string passwd);
void create(string id, string passwd);
void myDelete(string id, string passwd);
void merge(string id1, string passwd1, string id2, string passwd2);
void deposit(int money);
void withdraw(int money);
void transfer(string id, int money);
void myFind(string wildcard_id);
void search(string id);
