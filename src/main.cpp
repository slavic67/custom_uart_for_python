#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include <fstream>
#include <dos.h>
#include <windows.h>
#include "SerialPort.h"
#include <typeinfo>
#include <string>

char output[MAX_DATA_LENGTH];
//char * port="\\\\.\\COM5";
char incoming[MAX_DATA_LENGTH];




int main(int argc, char* argv[]) {



	SerialPort arduino(argv[1]);
	string path="signal.bin";
	ifstream file;

	while (1)
	{
		string str="";
		file.open(path);
		//if (file.is_open()) cout<<"file is open"<<endl;
		file>>str;
		file.close();
		if (str==""||str.length()==1)
		{
			continue;
			Sleep(100);
		}
		else if (str=="close")
		{
			break;
		}
		else
		{
			char *charArray=new char[str.size()+1];
			copy(str.begin(),str.end(),charArray);
			charArray[str.size()]='\0';
			arduino.writeSerialPort(charArray,MAX_DATA_LENGTH);
			while (output[0]=='\0')
			{arduino.readSerialPort(output,MAX_DATA_LENGTH);}
			//cout<<endl<<output;

			delete [] charArray;

			ofstream wfile;
			wfile.open(path);
			wfile<<output;
			wfile.close();
			output[0]='\0';
		}
		Sleep(100);
	}


	return 0;
}
