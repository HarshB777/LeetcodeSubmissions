const long long int MX = 1000000;
vector<bool> isPrime(MX,true);
bool isPrimeComputed = false;
void pre(){
    if(isPrimeComputed)
        return;
    isPrimeComputed = true;
    isPrime[0]=isPrime[1]=false;
    for(long long int p=2;p<MX;p++)
        for(long long int j=p*p;j<MX;j+=p)
            isPrime[j]=false;
}

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        const long long int n=size(mat),m=size(mat[0]);
        pre();
        map<long long int,long long int> freq;
        for(long long int dX=-1;dX<=1;dX++)
            for(long long int dY=-1;dY<=1;dY++){
                if(dX==0&&dY==0)
                    continue;
                
                for(long long int sX=0;sX<n;sX++)
                    for(long long int sY=0;sY<m;sY++){
                        long long int curX=sX,curY=sY;
                        long long int cur = 0;
                        while(0<=curX&&curX<n&&0<=curY&&curY<m){
                            cur = cur*10+mat[curX][curY];
                            freq[cur]++;
                            curX+=dX;
                            curY+=dY;
                        }
                    }
            }
        
        long long int ans=-1,f=0;
        for(const auto &x:freq){
            const long long int cur = x.first,curF=x.second;
            if(cur<10)
                continue;
            if(!isPrime[cur])
                continue;
            if(curF<f)
                continue;
            ans=cur;
            f=curF;
        }
        return ans;
    }
};