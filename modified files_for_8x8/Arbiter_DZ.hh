
// Author: DA ZHOU
 

#ifndef __MEM_RUBY_NETWORK_GARNET_FLEXIBLE_PIPELINE_ARBITER_DZ_HH__ 
#define __MEM_RUBY_NETWORK_GARNET_FLEXIBLE_PIPELINE_ARBITER_DZ_HH__ 
#include <iostream> 
#include <vector> 
#include "mem/ruby/network/garnet/BaseGarnetNetwork.hh" 
#include "mem/ruby/network/garnet/NetworkHeader.hh" 
#include "mem/ruby/network/Network.hh" 
#include "params/GarnetNetwork.hh"
using namespace std;

//DZ
#include <string.h>
class NetworkInterface;
class MessageBuffer; 
class Router; 
class Topology; 
class NetDest; 
class NetworkLink; //arbiters-DZ 
class Arbiter_DZ{ 
public:
    Arbiter_DZ(int a,int b){ 
	int temp_arr[60] = {0};
	memcpy(request,temp_arr,sizeof(temp_arr));// as arrays can not be initialized in the class!!!
	arbiter_id=a;
	size = b;
	master = 0;
	bus_status=0;
   }
    void send_request( int id ){request[id] = 1;}// set the request[id] == 1
    void cancel_request(int id){request[id] = 0;}
    void arbitrate(){
	if (bus_status) {}
	else { // cout<<"Arbiter "<< arbiter_id<< "is arbitrating request: "<<request[0]<<" "<<request[1]<<" "<<request[2]<<" "<<request[3]<<" "<<request[4]<<" "<<request[5]<<" "<<request[6]<<" "<<request[7]<<" "<<request[8]<<" "<<request[9]<<" "<<endl;
		for (int i=0;i <60; i++){//including request from arbiters

		if (request[master]) {
		master = master;
		break;
		}
		else master=master+1;
		if  (master==60) master=0;
		}
	     }
	}
	int master;
	int bus_status;
	int get_status() {return bus_status;}
	int get_master() {return master;}
	void control_bus(){bus_status=1;}
	void release_bus(){bus_status=0;}
 private:
	int arbiter_id;
 	int size;
	//int master;
	int request[60];
};

#endif

