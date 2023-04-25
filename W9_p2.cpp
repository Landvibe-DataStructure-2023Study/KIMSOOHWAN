#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct compare{
    bool operator()(const int &e1,const int &e2){
        if(e1%2==1&&e2%2==0) return true;
        else if(e1%2==0&&e2%2==1) return false;
        else return e1>e2;
    }
};

class unsortedPQ{
public:
    void insert(int x){
        seq.push_back(x);
    }
    int min(){
        if (seq.empty()) return -1;
        compare c;
        int a = seq[0];
        for(int i=0;i<seq.size();i++){
            if(c(seq[i],a)) a=seq[i];
        }
        return a;
    }
    void removeMin(){
        compare c;
        int mindex = 0;
        for(int i =0;i<seq.size();i++){
            if(c(seq[i],seq[mindex])) mindex = i;
        }
        seq.erase(seq.begin()+mindex);
    }
private:
    vector<int>seq;
};
int main(){
    int t;
    cin>>t;
    unsortedPQ q;
    while(t--){
        int n;
        cin>>n;
        int lis[20];
        for(int i=0;i<n;i++){
            cin>>lis[i];
        }
        for(int i=0;i<n;i++){
            q.insert(lis[i]);
        }
        for(int i=0;i<n;i++){
            cout << q.min() << " ";
            q.removeMin();
        }
        cout<<endl;
        
    }
    return 0;
}
