#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N;
multiset<int> M;

void solve() {
	int i,j,k,l,r,x,y; string s; //자주 사용하는 변수를 미리 설정해놓는듯 대회에서는 유용할듯함
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		M.insert(x);
	}
	
	x=*M.rbegin();
	for(i=1;i<=x;i++) {
		if(x%i==0) M.erase(M.find(i));
	}
	
	cout<<x<<" "<<*M.rbegin()<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin); 
	//아마 디버깅을 위한 코드인듯함 어떻게 써먹는지는 잘 모르겠음
	cout.tie(0); solve(); return 0;
}