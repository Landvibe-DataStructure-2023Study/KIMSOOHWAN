#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct compare{
    bool operator ()(const int &e1, const int &e2){
        if(e1%2==0 && e2%2==1)return true;
        else if(e1%2==1 && e2%2==0)return false;
        else return e1<e2;
    }
};

class unsortedPQ{
public:
    vector<int>seq;
    void insert(int x){
        seq.emplace_back(x);
    }
    int min(){
        if(seq.empty()) return -1;
        else{
            compare c;
            int mindex = 0;
            for(int i=0;i<seq.size();i++){
                if(c(seq[i],seq[mindex])) mindex = i;
            }
            return seq[mindex];
        }
    }
    void removeMin(){
        if(seq.empty()) return;
        else{
            compare c;
            int mindex = 0;
            for(int i=0;i<seq.size();i++){
                if(c(seq[i],seq[mindex]))mindex=i;
            }
            seq.erase(seq.begin()+mindex);
        }
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int lis[20];
        unsortedPQ q;
        for(int i=0;i<n;i++){
            cin>>lis[i];
        }
        for(int i=0;i<n;i++){
            q.insert(lis[i]);
        }
        for(int i=0;i<n;i++){
            cout<<q.min()<<" ";
            q.removeMin();
        }
    }
}
