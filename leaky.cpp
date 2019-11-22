#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#define bucketSize 512
using namespace std;

void bktInput(int a,int b){
	if(a>bucketSize)
		cout<<"\n\t\tBucket overflow";
	else{
		usleep(500);
		while(a>b){
			cout<<"\n\t\t"<<b<<" bytes outputted.";
			a-=b;
			usleep(500);
		}
		if (a>0)
			cout<<"\n\t\tLast "<<a<<" bytes sent\t";
		cout<<"\n\t\tBucket output successful\n";
	}
}

int main(){
	int op, pktSize;
	cout<<"Enter output rate : ";
	cin>>op;
	for(int i=1;i<=5;i++){
		usleep(rand()%1000);
		pktSize=rand()%1000;
		cout<<"\nPacket no "<<i<<"\tPacket size = "<<pktSize;
		bktInput(pktSize,op);
	}
	return 0;
}

/*Output:

Enter output rate : 100

Packet no 1	Packet size = 886
		Bucket overflow
Packet no 2	Packet size = 915
		Bucket overflow
Packet no 3	Packet size = 335
		100 bytes outputted.
		100 bytes outputted.
		100 bytes outputted.
		Last 35 bytes sent	
		Bucket output successful

Packet no 4	Packet size = 492
		100 bytes outputted.
		100 bytes outputted.
		100 bytes outputted.
		100 bytes outputted.
		Last 92 bytes sent	
		Bucket output successful

Packet no 5	Packet size = 421
		100 bytes outputted.
		100 bytes outputted.
		100 bytes outputted.
		100 bytes outputted.
		Last 21 bytes sent	
		Bucket output successful


*/
