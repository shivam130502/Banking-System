#include<iostream>
#include<fstream>
#include<sstream>//for stringstream.
using namespace std;
void open_account();
void deposit();
void withdraw();
void change_password();
struct bank{
	string user_name,password,email_id;
	long int account_number,phone_number;
	int balance ;
};

int main(){
	int answer;
	cout<<"                                         WELCOME TO OUR BANK"<<endl;
			repeat:
		cout<<endl<<endl;
	cout<<"which operation would you like to perform "<<endl;
	cout<<"1. WITHDRAWAL"<<endl<<"2. DEPOSIT"<<endl<<"3. OPEN ACCOUNT"<<endl<<"4. CHANGE PASSWORD"<<endl<<"5. EXIT"<<endl;
    cin>>answer;
    if(answer == 1)withdraw();
    else if(answer == 2)deposit();
    else if(answer == 3)open_account();
    else if(answer == 4)change_password();
    else if(answer == 5){
    	cout<<"THANK YOU , VISIT AGAIN";
    	exit(0);
	}
    goto repeat;

}

void open_account(){
	ofstream i ;
	bank customer ;
	cout<<"enter user name"<<endl;
	cin>>customer.user_name;
	string filename = customer.user_name+".txt";
	i.open(filename.c_str(),ios::out);
         customer.balance = 0;
  			cout<<"enter password"<<endl;
	cin>>customer.password;
	cout<<"enter e-mail id"<<endl;
	cin>>customer.email_id;
	i<<customer.password<<endl;
	i<<customer.email_id<<endl;
	i<<customer.balance<<endl;
	cout<<"YOUR ACCOUNT HAS BEEN SUCCESSFULLY CREATED."<<endl;
}
void deposit(){
	string name,extension = ".txt";
	int num = 0 ; 
	cout<<"enter user name"<<endl;
	cin>>name;
	string filename = name + extension;
	ifstream f(filename.c_str(),ios::in);
	cout<<"enter password"<<endl;
	string pass,password,was;
		cin>>pass;
	while(! f.eof()){
		getline(f,password);
		if(num == 0){
			was = password;
		}
		num++;
	}
	if(pass == was ){
		cout<<"welcome"<<endl;
	}
	else
	{
		cout<<"wrong password"<<endl;
		exit(0);
	}
	num = 0;
	f.close();
	ifstream wr(filename.c_str(),ios::in);
	ofstream g("temp.txt",ios::out);
	string get;
	int line_num = 0;
	while(! wr.eof()){
		getline(wr,name);
		if(line_num < 2){
			g<<name<<endl;
		}
		if(num == 2){
			get = name;
			cout<<"your current balance is : Rs "<<name<<endl;
		}
		num++;
		line_num++;
	}
	f.close();
	g.close();
	stringstream take(get);
	int past = 0 ;
	take>>past;
	int deposit ;
	label:
	cout<<"enter the amount you would like to deposit : ";
	cin>>deposit;
	if(deposit < 0){
		cout<<"please enter a valid amount"<<endl<<endl;
		goto label;
	}
	past += deposit;
	cout<<"total balance is : "<<past;
	ofstream of(filename.c_str(),ios::out);
	ifstream st("temp.txt",ios::in);
	string str;
	line_num = 0; 
	while(! st.eof()){
		getline(st,str);
		if(line_num != 2){
			of<<str<<endl;
		}else goto conclude;
		
		line_num++;
	}
	conclude:
		of<<past;
		of.close();
		st.close();
	
}
void withdraw(){
      cout<<"enter user name"<<endl;
	  string name ;
	  cin>>name;
	  string filename = name+".txt";
	  ifstream op(filename.c_str(),ios::in);
	  ofstream of("temp.txt",ios::out);
	  
	  cout<<"enter password"<<endl;
	  string enter_pass;
	  cin>>enter_pass;
	  string check_pass;
	  
	  
	  
      string line,bal ;
	  int line_num = 0,number = 0;
	  while(! op.eof()) {
	  	getline(op,line);
	  	if(number == 0){
	  		check_pass = line;
		  }
	  	if(number < 2){
	  		of<<line<<endl;
		  }
	  	if(line_num == 2){
	  		bal = line ;
		  }
		  line_num++;
		  number++;
	  }
	   op.close();
	   of.close();
	   
	   if(enter_pass == check_pass){
	   	cout<<"welcome"<<endl;
	   }else{
	   	cout<<"wron password"<<endl;
	   	exit(0);
	   }
       
	   
	   stringstream str(bal);
       int convert = 0;
       str>>convert;
       cout<<"current balance is : "<<convert<<endl;
       repeat:
	   cout<<"enter amount to withdraw : ";
       int with = 0;
       cin>>with;
       if(with < 0 || with > convert){
       	cout<<"please enter a valid amount"<<endl;
       	goto repeat;
	   }
       convert -= with;
       cout<<"total balance is : "<<convert;
       ifstream it("temp.txt",ios::in);
       ofstream os(filename.c_str(),ios::out);
       number = 0; 
       while(! it.eof()){
       	getline(it,name);
       	if(number < 2){
       		os<<name<<endl;
		   }else goto conclude;
		   number++;
	   }
	   conclude:
	   	os<<convert;
	   	it.close();
	   	os.close();
}
void change_password(){
	cout<<"enter user name"<<endl;
	string username;
	cin>>username;
	string filename = username + ".txt";
	cout<<"enter password"<<endl;
	string pass,inTake,old_password,new_password;
	cin>>pass;
	ifstream in(filename.c_str(),ios::in);
	ofstream of("temp.txt",ios::out);
	int line_num = 0;
	while(! in.eof()){
		getline(in,inTake);
		if(line_num == 0){
			 old_password = inTake;
		}
		else{
			of<<inTake<<endl;
		}
		line_num++;
	}
	in.close();
	of.close();
	if(pass == old_password){
		cout<<"welcome"<<endl;
	}else {
		cout<<"wrong password "<<endl;
		exit(0);
	}
	cout<<"enter new password"<<endl;
	cin>>new_password;
	ofstream x(filename.c_str(),ios::out);
	ifstream y("temp.txt",ios::in);
	string put;
	x<<new_password<<endl;
	while(! y.eof()){
		getline(y,put);
		x<<put<<endl;
	}
	cout<<"YOUR PASSWORD HAS BEEN SUCCESSFULLY UPDATED"<<endl;
	x.close();
	y.close();
}
