#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	long case_test;
	long total_points;
	
	scanf("%ld\n", &case_test);
	
	while(scanf("%li\n", &total_points)!= EOF)
	{
		using point = pair<double, double>;
		point N;
		vector<point> pointV;

		for(int i=0; i< total_points; i++){
			scanf("%lf %lf\n", &N.first, &N.second);
			pointV.push_back(N);	
		}
		sort(pointV.begin(), pointV.end());
		
		point pointB = * pointV.begin();
		point pointE = * (pointV.end()-1);
		point s;	
		
		s.first = (pointB.first+pointE.first)/2; 
		s.second = (pointB.second+pointE.second)/2; 

		if(total_points%2==0)
		{	
			point testP;
			std::vector<point>::reverse_iterator reverse = pointV.rbegin();
			point pointT = *(reverse);
			int check = 0;
			for(auto j : pointV){
				testP.first = (j.first+pointT.first)/2; 
				testP.second = (j.second+pointT.second)/2; 
				pointT = *(++reverse);
				
				if((testP.first == s.first) and (testP.second == s.second)){
					continue;
				}else{
					check++;
					break;
				}
			}
			if(check!=0)
				printf("no\n");
			else
				printf("yes\n");
			
		}
		else{
			long verify = (total_points/2)+1;
			pointB = * (verify+pointV.begin());
			if(s.first==pointB.first and s.second==pointB.second){
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}
	}
	return 0;
}
