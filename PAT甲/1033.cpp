#include<bits/stdc++.h>
using namespace std;
struct Gas{
	float price;
	int dis;
};
bool cmp(struct Gas a,struct Gas b){
	if(a.dis < b.dis){
		return true;
	}else if (a.dis > b.dis){
		return false;
	}else{
		return a.price <b.price;
	}
}
int main(){
	int capacity,d,average,n;
	cin >>capacity>>d>>average>>n;
	struct Gas gas[n];
	for(int i=0;i<n;i++){
		cin >>gas[i].price>>gas[i].dis;
	}
	sort(gas,gas+n,cmp);
	int total_meter = capacity*average;//油箱加满能跑的路程 
	if(gas[0].dis != 0){
		printf("The maximum travel distance = 0");
		return 0;
	}else{
		int gasBox = 0; 
		float pay = 0;  //支付的钱 
		int idx = 0;   //现在在什么加油站 
		int min_idx = 0;   //最小价格的加油站的地点 
		float gasBoxPrice = 0;
		while(idx < n){
			int minprice = 999999;
			if(gas[idx].dis+total_meter < gas[idx+1].dis){
				printf("The maximum travel distance = %.2f",gas[idx].dis+total_meter);
				return  0; 
			}
			for(int i=idx+1;i<n;i++){
				if(gas[idx].dis+total_meter < gas[i].dis) break;
				if(gas[i].price < minprice){
					minprice = gas[i].price;
					min_idx = i;
					// 找到第一个比idx小的价格的节点，然后退出 
					if (gas[idx].price > gas[i].price){
						// 油箱内有油 
						if (gasBox != 0){
							if(gasBox < gas[i].dis-gas[idx].dis){
									pay += (gas[i].dis-gas[idx].dis-gasBox) * gas[idx].price;
									gasBox = 0;
							}else{
								gasBox -= gas[i].dis-gas[idx].dis-gasBox;
							}
							
						}else{
							pay += (gas[i].dis-gas[idx].dis) * gas[idx].price;
						}
						
						idx = i; 
						break;
					}
				}
			}
			// 如果找不到比idx小的价格节点
			if( min_idx != idx){
				// 如果min_idx是最后一个节点了
					if(gasBox != 0){
						pay += (total_meter-gasBox) * gas[idx].price;
					}else{
						pay += total_meter * gas[idx].price;
					}
					gasBox = total_meter-(gas[min_idx].dis - gas[idx].dis);
					idx = min_idx; 
			} 
		}
		printf("%.2f",pay/average);
	}
} 
