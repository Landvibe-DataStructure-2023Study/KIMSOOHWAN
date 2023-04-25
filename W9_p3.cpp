#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct compare{
    bool operator()(const int &e1, const int &e2){
        if(e1>e2) return true;
        else return false;
    }
};
class unsortedPQ{
private:
    vector<int>seq;
public:
    void insert(int x){
        seq.push_back(x);
    }
    void removeMin(){
        if(seq.empty()) return;
        else {
            compare c;
            int mindex = 0;
            for(int i=0;i<seq.size();i++){
                if(c(seq[i],seq[mindex])) mindex = i;
            }
            seq.erase(seq.begin()+mindex);
        }
    }
    int min(){
        if(seq.empty()) return -1;
        else{
            compare c;
            int mindex = 0;
            for(int i=0;i<seq.size();i++){
                if(c(seq[i],seq[mindex])) mindex=i;
            }
            return seq[mindex];
        }
    }
};
int main()
{
    int t;
    int n;
    int lis[20];
    unsortedPQ q;
    cin>>t;
    while(t--){
        cin>>n;
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
        cout<<endl;
    }
}
