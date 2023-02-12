#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class hero {

	int health;

	public:
	char *name;
	char level;
	static int timeToComplete;

	// Default Constructor.
	hero(){
		cout<<"Constructor Called"<<"\n";
	}
	// Parameter Constructor.
	hero(int health){
		cout<<"This "<<this<<"\n";
		this -> health = health;
	}
	// copy constructor.
	hero(hero& temp){
		char *ch= new char[strlen(temp.name)+1];
		strcpy(ch,temp.name);
		this->name=ch;
		cout<<"Copy constructor called"<<"\n";
		this->health=temp.health;
		this->level=temp.level;

	}

	hero(int health, char level){
		this->health=health;
		this->level=level;
	}
	void print(){
		cout<<"\n";
		cout<<"Name: "<<this->name<<"\n";
		cout<<"Health: "<<this->health<<"\n";
		cout<<"Level: "<<this->level<<"\n";
	}

	string getName(){
		return name;
	}
	int getHealth(){
		return health;
	}

	void setName(char *s){
		name=s;
	}
	void setHealth(int h){
		health=h;
	}
	// static function can only acces to static members.
	static int random(){
		return timeToComplete;
	}
	// Destructor.
	~hero(){
		cout<<"Destructor called"<<"\n";
	}
};

int hero::timeToComplete=5;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		jack420
	#define int long long

	cout<<hero::random()<<"\n";

	// No need to create object to print ststic member.
	// it does not have this keyword as this is pointer to current object.
	// cout<<hero::timeToComplete<<"\n";
	// hero a;
	// cout<<a.timeToComplete<<"\n";
	// hero b;
	// b.timeToComplete=10;
	// cout<<a.timeToComplete<<"\n";
	// cout<<b.timeToComplete<<"\n";

	// hero a;
	// hero *b=new hero();
	// // Destructor is called automatically for static and manually for dynamic objects
	// delete b;

	// hero hero1;
	// char m[7]="Mrinal";
	// hero1.setHealth(70);
	// hero1.setName(m);
	// hero1.level='D';
	// hero1.print();
	// hero hero2(hero1);
	// hero2.print();
	// hero1.name[0]='G';
	// hero1.print();
	// hero2.print();
	// // Copy Assignment.
	// hero1=hero2;
	// hero1.print();
	// hero2.print();

	// copy constructor
	// hero R(10,'B');
	// R.print();
	// hero S(R);
	// S.print();

	// hero ramesh(10);
	// cout<<"Adress of ramesh "<<&ramesh;

	// hero a;
	// cout<<"Level of a is "<<a.level<<"\n";
	// cout<<"Name of a is "<<a.getName()<<"\n";
	// cout<<"Health of a is "<<a.getHealth()<<"\n";

	// hero *b = new hero;
	// cout<<"Level of b is "<<b->level<<"\n";
	// cout<<"Name of b is "<<b->getName()<<"\n";
	// cout<<"Health of b is "<<b->getHealth()<<"\n";

	// hero h1;
	// cout<<sizeof(h1)<<"\n";
	// h1.level='A';
	// h1.setName("Mrinal");
	// h1.setHealth(70);

	// cout<<h1.level<<"\n";
	// cout<<h1.getHealth()<<"\n";
	// cout<<h1.getName()<<"\n";
}