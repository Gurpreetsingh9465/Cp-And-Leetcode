#include<iostream>

struct details{
	int count;
	bool find;
	bool dot = false;
};

details findStar(int position, std::string p){
	details detail;
	int counts = 1;
	int i;
	bool find = false;
	bool dot = false;
	for(i = position + 1; i<p.length(); i++){
		if(p[i] == p[i-1]){
			counts++;
			continue;
		}if(p[i] == '*'){
			counts++;
			detail.count = counts;
			find = true;
			detail.find = find;
			return detail;
		}if(p[i] == '.'){
			counts++;
			detail.count = counts;
			find = false;
			detail.find = find;
			dot = true;
			detail.dot = true;
			return detail;
		}if(p[i] != '*' || p[i] != '.'){
            counts = 0;
            find = false;
			detail.find = find;
            detail.count = counts;
			return detail;
        }else{
		detail.count = counts;
		detail.find = false;
		return detail;
		}
	}
	if(position + 1 >= p.length()){
		counts = 0;
		detail.count = counts;
		detail.find = false;
		return detail;
	}
	detail.count = counts;
	detail.find = false;
	return detail;
}

bool isMatch(std::string s, std::string p){
	int startS  = 0;
	int currentS = 0;
	int startP = 0;
	int currentP = 0;
	while(currentP < p.length() && currentS < s.length()){
		if(s[currentS] == p[currentP]){
			if(s[currentS] == s[currentS + 1] && currentS + 1 < s.length()){
				currentS++;
				while(s[currentS] == s[currentS + 1]){
					currentS++;
				}currentS++;
				details detail = findStar(currentP, p);
				if(currentP + detail.count > p.length()){
					return 0;
				}
				if(!detail.find){
					if(detail.dot){
						if(currentS-startS < detail.count){
							return 0;
						}else{
							currentS = currentS - detail.count + 1;
							startS = currentS;
							currentP+= detail.count;
							startP = currentP;
							continue;
						}
					}
					if(currentS-startS > detail.count || currentS-startS < detail.count)
					return 0;
				}
				currentP += detail.count;
				startS = currentS;
				startP = currentP;
			}else{
				details detail = findStar(currentP, p);
				if(detail.find){
					currentP += 2;
					currentS++;
					startS = currentS; startP = currentP;
				}
				currentS++; currentP++; startS = currentS; startP = currentP;
				continue;
			}
		}else if(s[currentS] != p[currentP]){
			if(p[currentP] != '.'){
				if(p[currentP + 1] == '*'){
				currentP += 2;
				startP = currentP;
				startS = currentS;
				continue;
			}
				return 0;
			}
			if(p[currentP] == '.' && p[currentP+1] != '*'){
				currentP++;
				startP = currentP;
				currentS++;
				startS = currentS;
			}
			else if(p[currentP] == '.' && p[currentP+1] == '*'){
				if(currentP + 2 < p.length()){
					while(s[currentS] != p[currentP + 2]){
						currentS++;
					}
					startS = currentS;
					currentP += 2;
					startP = currentP;
					continue;
				}
				return 1;
			}
		}
	}
	if(currentP > currentS  && s.length() > p.length()){
		return 0;
	}
	if( currentS < s.length() || currentP < p.length()){
		return 0;
	}
	return 1;
}

int main(){
	std::string s = "ab";
	std::string p = ".*c";
	std::cout<<"\nResult is :"<<isMatch(s, p);
}
