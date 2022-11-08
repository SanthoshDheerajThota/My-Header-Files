#include <reg51.h>
void bin(int num,int arr[]){
	int rem;
	int flag=3;
	while(num){
		rem=num%2;
		arr[flag]=rem;
		flag--;
		num=num/2;
	}
	for(rem=flag;rem>=0;rem--){
		arr[rem]=0;
	}
	return ;
}
sbit p1=P1^1;
sbit p2=P1^2;
sbit p3=P1^3;
sbit p4=P1^4;
sbit p5=P1^5;
sbit p6=P1^6;
sbit p7=P1^7;
sbit p0=P1^0;
void delay(){
	TH0=0xFE;
	TL0=0x0C;
	TR0=1;
	while(TF0==0){
	}
	TF0=0;
	TR0=0;
	return ;
}
void main(){
	unsigned int i,j,k;
	int arr[4]={0};
	while(1){
		for(i=0;i<10;i++){
			bin(i,arr);
			p0=arr[3];
			p1=arr[2];
			p2=arr[1];
			p3=arr[0];
			for(j=0;j<10;j++){
				bin(j,arr);
				p4=arr[3];
				p5=arr[2];
				p6=arr[1];
				p7=arr[0];
				for(k=0;k<5000;k++){
					delay();
				}
				if(i==6&&j==0){
					
				}
			}
		}
	}
}
				
