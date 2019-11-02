#include<bits/stdc++.h>
using namespace std;
char ch;
long long ac;
string ps,id;

void clrscr(){
    cout << string( 100, '\n' );
}

class address{
	public :
		int houseNumber,pinCode;
		string block,locality,city,state,country;		
};

class branch:public address{
	public:
		string ifscCode;
};

class person{
	public:
		string name,motherName,dob,aadharNumber,email;
		long long mobileNumber;
};

class account:public branch{	
	public:
		long long balance,accountNumber,interest,lInterest;
		string openingDate;
};

class user:public address, public person{
	public:
		string panNumber,password;
		account userAccount;
		void showDetails();
		void getData();
		
};

class admin : public branch, public person{
	public:
		string password,id;
		string joiningDate,post;
		long long salary;
		void createUser();
		void listUsers();
		void findUser();
		void withdraw(user &a);
		void deposit(user &a);
		void delUser(user &a);
		void grantLoan(user &a);
		void acceptInstallment(user &a);
};

vector<user> uList;
vector<admin> aList(1);

void adminPortal(admin &adm){
	cout<<"Welcome "<<adm.name<<endl;
	int y=1;
	while(y){
		cout<<"Press 1 to Open an Account\n";
		cout<<"Press 2 to Find Account\n";
		cout<<"Press 3 to Sign-out\n";
		cin>>ch;
		if(ch=='1'){
			adm.createUser();
		}
		else if(ch=='2'){
			adm.findUser();
		}
		else if(ch=='3'){
			y=0;
			cout<<"Signed Out successfully\n";
		}
		else{
			clrscr();
			cout<<"Enter a valid choice\n";
			//adminPortal(adm);
		}
	}
}
void admin::createUser(){
	clrscr();
	user newUser;
	newUser.getData();
	uList.push_back(newUser);
}

void admin::listUsers(){
	for(int i=0;i<uList.size();i++){
		cout<<uList[i].userAccount.accountNumber<<"   "<<uList[i].name<<endl;
	}
}

void admin::findUser(){
	cout<<"Enter Account No.\n";
	cin>>ac;
	int flag1=1;
	for(int i=0;i<uList.size();i++){
		if(ac==uList[i].userAccount.accountNumber){
			flag1=0;
			cout<<"Account found\n";
			int x=1;
			while(x){
				cout<<"Press 1 to show details\n";
				cout<<"Press 2 to withdraw\n";
				cout<<"Press 3 to deposit\n";
				cout<<"Press 4 to close\n";
				cout<<"Press 5 to grant loan\n";
				cout<<"Press 6 to accept installment\n";
				cout<<"Press 7 to exit\n";
				cin>>ch;
				switch(ch){
					case 1:{
						uList[i].showDetails();
						break;
					}
					case 2:{
						this->withdraw(uList[i]);
						break;
					}
					case 3:{
						this->deposit(uList[i]);
						break;
					}
					case 4:{
						this->delUser(uList[i]);
						break;
					}
					case 5:{
						this->grantLoan(uList[i]);
						break;
					}
					case 6:{
						this->acceptInstallment(uList[i]);
						break;
					}
					case 7:{
						x=0;
						break;
					}
					default:{
						cout<<"Enter a valid choice\n";
						break;
					}
				}
			}
		}
	}
	if(flag1==1){
			cout<<"Account Not Found\n";
		}
}

void admin::withdraw(user &a){
	long long amountx;
	cout<<"Enter amount to withdraw\n";
	cin>>amountx;
	if(amountx<a.userAccount.balance){
		a.userAccount.balance-=amountx;
		cout<<"Updated Balance"<<" = "<<a.userAccount.balance<<endl;
	}
	else{
		cout<<"Insufficient balance\n";
	}		
}

void admin::deposit(user &a){
	long long amountx;
	cout<<"Enter amount to deposit\n";
	cin>>amountx;
		a.userAccount.balance+=amountx;
		cout<<"Updated Balance"<<" = "<<a.userAccount.balance<<endl;			
}

void admin::delUser(user &a){
	int pos=-1;
	for(int i=0;i<uList.size();i++){
		if(a.userAccount.accountNumber==uList[i].userAccount.accountNumber){
			pos=i;
			break;
		}
	}
	if(pos!=-1){
		uList.erase(uList.begin()+pos);
		cout<<"Account Closed\n";
	}
	else{
		cout<<"Account does not exist\n";
	}
}

int main(){
	int i=1;
	while(i){
		clrscr();
		cout<<"WELCOME\n\n"<<"Press 1 to login as user\nPress 2 to login as admin\nPress 3 to end session\n";
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"Enter Account No. and Password\n";
				cin>>ac>>ps;
				for(int i=0;i<uList.size();i++){
					if(ac==uList[i].userAccount.accountNumber&&ps==uList[i].password){
						uList[i].showDetails();
						break;
					}
				}
				break;
			}
			case 2:{
				cout<<"Enter Id and Password\n";
				cin>>id>>ps;
				for(int i=0;i<aList.size();i++){
					if(id==aList[i].id&&ps==aList[i].password){
						cout<<"Login Successful\n";
						adminPortal(aList[i]);
						break;
					}
				}
				break;
			}
			case 3:{
				i=0;
				break;
			}
			default:{
				cout<<"Enter valid choice\n";
				break;
			}
		}
	}
}
