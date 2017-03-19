#includeiostream
#includemap
#includestring
#includestring.h
#includevector
#includestdio.h
#include cstdio
#include vector
#include cstdio
#include algorithm
#include cstring
#include cctype
#include stack
#include queue
#include list
#include sstream
#include cmath
#include bitset
#include utility
#include set
#include functional
#include math.h
#define LL long long int
#define ii pair int,int 
#define iii pair int , ii  
#define vi vectorint
#define II pair LL , LL 
#define III pair LL  , LL  
#define vI vectorLL
#define rI(B) scanf(%d,&B)
#define wI(B) printf(%d,B)
#define R(i) freopen(i,r,stdin)
#define W(i) freopen(i,w,stdout)
#define R_W R(i.txt),W(o.txt);
#define FOR(i,f,t) for(int i=f;it;i++)
#define r(e) for(int i=0;ie;i++)
double pi = acos(-1);
using namespace std;
vi data;
class SegmentTree {         
private vi st, A;           
  int n;
  int left (int p) { return p  1; }
  int right(int p) { return (p  1) + 1; }
 
  void build(int p, int L, int R) {             
    if (L == R)                        
      st[p] = L;                 
    else { 
      build(left(p) , L              , (L + R)  2);
      build(right(p), (L + R)  2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] = A[p2])  p1  p2;
  } }
 
  int rmq(int p, int L, int R, int i, int j) {  
    if (i   R  j   L) return -1;
    if (L = i && R = j) return st[p];          
    int p1 = rmq(left(p) , L              , (L+R)  2, i, j);
    int p2 = rmq(right(p), (L+R)  2 + 1, R          , i, j);
 
    if (p1 == -1) return p2;
    if (p2 == -1) return p1; 
    return (A[p1] = A[p2])  p1  p2; }  
 
  int update_point(int p, int L, int R, int idx, int new_value) {
    int i = idx, j = idx;
    if (i  R  j  L)
      return st[p];
    if (L == i && R == j) {
      A[i] = new_value;
      return st[p] = L; 
    }
    int p1, p2;
    p1 = update_point(left(p) , L              , (L + R)  2, idx, new_value);
    p2 = update_point(right(p), (L + R)  2 + 1, R          , idx, new_value);
    return st[p] = (A[p1] = A[p2])  p1  p2;
  }
 
public
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size(); 
    st.assign(4  n, 0);
    build(1, 0, n - 1);
  }
 
  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
 
  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
};
int main(){
	R_W;
	int n;
	while(cinn && n)
	{
		data.clear();
		r(n){        read the n elements and calculate partial sum for them so that data[i]= Sum(data[0]data[i]);
			int in;
			cinin;
			if(data.size()) in+=data.back();
			data.push_back(in);
		}
		r(n){  extend the partail sum to 2n to get the cyclic partial sum data[i](Sum(data[0]data[i%n]))
			int in=data[i];
			if(i) in-=data[i-1];
			if(data.size()) in+=data.back();
			data.push_back(in);
		}
		SegmentTree st(data);
		int last=0;
		int ans=n;    this maximum possible answer all are non-negative
		r(n){
			if(i) last=data[i-1];    get last element (to handle if i ==0 there is no last element)
			int val=st.rmq(i,i+n-1);  here we get minimum value we colud reach in this summation 
			if(data[val]-last0) ans--;   the actual value we colud reach (by removing partial sum from 0 to i-1 )
			 if this sum less than zero we decrease the answer;
		}
		coutansendl;
	}
	return 0;
} 