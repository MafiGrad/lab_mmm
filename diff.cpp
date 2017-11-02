#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

float func(float x){
return cos(x);
}

float back(float x, float d);
float forward(float x, float d);
float mid(float x, float d);
float sevenpoints(float x, float d);
float fivepoints(float x, float d);

ofstream ofs;

int main(){
	
	float x1(0);
	float x2(8);
	float h(0.5);
	
	float h1(0.001);
	float h2(0.1);
	float n(200);
	float s(0);
	s=(h2-h1)/n;
	
	ofs.open("dif_lab.txt");
	
	ofs << "func\n";
	for (float x=x1; x<=x2; x+=h){
	ofs << x;
	ofs << " ";
	ofs << func(x);
	ofs << "\n";
	}
	
	ofs << "back\n";
	for (float x=x1; x<=x2; x+=h){
	ofs << x;
	ofs << " ";
	ofs << back(x, h);
	ofs << "\n";
	}
	
	ofs << "forward\n";
	for (float x=x1; x<=x2; x+=h){
	ofs << x;
	ofs << " ";
	ofs << forward(x, h);
	ofs << "\n";
	}
	
	ofs << "mid\n";
	for (float x=x1; x<=x2; x+=h){
	ofs << x;
	ofs << " ";
	ofs << mid(x, h);
	ofs << "\n";
	}
	
	ofs << "five points\n";
	for (float x=x1; x<=x2; x+=h){
	ofs << x;
	ofs << " ";
	ofs << fivepoints(x, h);
	ofs << "\n";
	}
	
	ofs << "seven points\n";
	for (float x=x1; x<=x2; x+=h){
	ofs << x;
	ofs << " ";
	ofs << sevenpoints(x, h);
	ofs << "\n";
	}
	
	ofs << "\npogr\n";
	ofs << "back\n";
	for (float x=h1; x<=h2; x+=s){
	ofs << x;
	ofs << " ";
	ofs << back(1, x);
	ofs << "\n";
	}
	
	ofs << "forward\n";
	for (float x=h1; x<=h2; x+=s){
	ofs << x;
	ofs << " ";
	ofs << forward(1, x);
	ofs << "\n";
	}
	
	ofs << "mid\n";
	for (float x=h1; x<=h2; x+=s){
	ofs << x;
	ofs << " ";
	ofs << mid(1, x);
	ofs << "\n";
	}
	
	ofs << "five points\n";
	for (float x=h1; x<=h2; x+=s){
	ofs << x;
	ofs << " ";
	ofs << fivepoints(1, x);
	ofs << "\n";
	}
	
	ofs << "seven points\n";
	for (float x=h1; x<=h2; x+=s){
	ofs << x;
	ofs << " ";
	ofs << sevenpoints(1, x);
	ofs << "\n";
	}

	ofs.close();
	return 0;
}

float back(float x, float d){

return (func(x)-func(x-d))/d;
}

float forward(float x, float d){

return (func(x+d)-func(x))/d;
}

float mid(float x, float d){

return (func(x+d)-func(x-d))/(2*d);
}

float fivepoints(float x, float d){

return (func(x-2*d)-8*func(x-d)+8*func(x+d)-func(x+2*d))/(12*d);
}

float sevenpoints(float x, float d){

return (-func(x-3*d)+9*func(x-2*d)-45*func(x-d)+45*func(x+d)-9*func(x+2*d)+func(x+3*d))/(60*d);
}
