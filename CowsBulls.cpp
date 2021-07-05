#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>

using namespace std;


//generate random number for the player to guess
int generateRand(){
	
	while(1){
	int flag = 0;
	srand(time(NULL));
	long secret = rand()%9000 + 1000;
	
	string temp = to_string(secret);
	
	int count[10] ={0,0,0,0,0,0,0,0,0,0};
	
	for(int i = 0; i < 4; i++){
		if ( ++count[temp[i] - '0']>1){
			flag = 1;
			break;
			}
		}	
	
	if (flag == 0){
			return secret;
	}
	
	}
}

//evaluating the number of cows and bulls from player's guess
void cb (string num, string guess){
	int bullcnt= 0, cowcnt = 0;
	for (int i=0; i<4; i++){
		if(num[i] == guess [i])
			bullcnt++;
	}
	for(int i = 0; i < 4; i++){
		for(int j=0; j<4; j++){
			if( guess[i] == num[j])
				cowcnt++;
		}
	}
	cout<<bullcnt<<" bulls ";
	cout<<cowcnt-bullcnt<<" cows\n ";
}

int main(){
	int num = generateRand();
	int guess;
	
	cout<<"Target set"<<endl;
	cout<<"enter your guess ";
	cin>>guess;
	cb(to_string(num), to_string(guess));
	while(num != guess){
		cout <<"enter your next number ";
		cin >> guess;
		cout<<"\n";
		cb(to_string(num), to_string(guess));
	}
	cout<<"done!";
}
