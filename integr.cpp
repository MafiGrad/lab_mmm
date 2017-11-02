#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


float func(float x){
	

return x*sin(x)+1; 
}

	const float n=100;
	const float a=0;
	const float b=10;

void left_rect(float a, float b, float n);
void right_rect(float a, float b, float n);
void mid_rect(float a, float b, float n);
float simpson(float a, float b, float n);
void trap(float a, float b, float n);

ofstream ofs;

int main(){

	left_rect(a, b, n);
	right_rect(a, b, n);
	mid_rect(a, b, n);
	trap(a, b, n);
	cout << "simpson result = " << simpson(a, b, n) << endl;
				
	return 0;
}

void left_rect(float a, float b, float n){

float s(0), x(0);
float h = (b-a)/n;
ofs.open("lab1.txt");
for (int i(0); i<n+1; i++){
	x=a+i*h;
	ofs << x;
	ofs << " ";
	s=s+func(x);
	ofs << func(x);
	ofs << "\n";
}
ofs << "left rectangle result = ";
ofs << s*h;
ofs << "\n\n";
ofs.close();
}

void right_rect(float a, float b, float n){

float s(0), x(0);
float h = (b-a)/n;
ofs.open("lab1.txt");
for (int i(1); i<n+2; i++){
	x=a+i*h;
	ofs << x;
	ofs << " ";
	s=s+func(x);
	ofs << func(x);
	ofs << "\n";
}
ofs << "right rectangle result = ";
ofs << s*h;
ofs << "\n\n";
ofs.close();
}

void mid_rect(float a, float b, float n){

float s(0), x(0);
float h = (b-a)/n;
ofs.open("lab1.txt");
for (int i(0); i<n+1; i++){
	x=a+i*h;
	ofs << x;
	ofs << " ";
	s=s+func(x+h/2);
	ofs << func(x+h/2);
	ofs << "\n";
}
ofs << "mid rectangle result = ";
ofs << s*h;
ofs << "\n\n";
ofs.close();
}

float simpson(float a, float b, float n){

float s(0), x(0);
float h = (b-a)/(2*n);

for (int i(0); i<=2*n; i++){
	x=a+i*h;
	s=s+func(x)*((i==0 || i==n) ? 1 : ((i&1)==0) ? 2 : 4);
}

return s*(h/3);
}

void trap(float a, float b, float n){

float s(0), x(0);
float h = (b-a)/n;
ofs.open("lab1.txt");
for (int i(1); i<n+1; i++){
	x=a+i*h;
	ofs << x;
	ofs << " ";
	s=s+func(x);
	ofs << func(x+h/2);
	ofs << "\n";
}
s+=func(a)/2+func(b)/2;
ofs << "trap result = ";
ofs << s*h;
ofs << "\n\n";
ofs.close();
}
