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
	int total_meter = capacity*average;//����������ܵ�·�� 
	if(gas[0].dis != 0){
		printf("The maximum travel distance = 0");
		return 0;
	}else{
		int gasBox = 0; 
		float pay = 0;  //֧����Ǯ 
		int idx = 0;   //������ʲô����վ 
		int min_idx = 0;   //��С�۸�ļ���վ�ĵص� 
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
					// �ҵ���һ����idxС�ļ۸�Ľڵ㣬Ȼ���˳� 
					if (gas[idx].price > gas[i].price){
						// ���������� 
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
			// ����Ҳ�����idxС�ļ۸�ڵ�
			if( min_idx != idx){
				// ���min_idx�����һ���ڵ���
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
