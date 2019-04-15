
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

 bool match(string q, string p){
        int i; int j=0; 
        for(i=0; i<p.size(); i++, j++){
            cout<<"j = "<<j<<" i = "<<i<<" p[i] = "<<p[i]<<endl;
            if(j >= q.size()) {
                cout<<" j = "<<j<<" > q.size = "<<q.size()<<" return false"<<endl;
                return false;
            }
            if(p[i] >= 'A' && p[i] <='Z'){
                if(q[j] != p[i]) return false; 
                else {
                    j++; continue;
                }
            }
            cout<<"before while j = "<<j<<endl;
                while(j<q.size()){
                    if(q[j] == p[i]) {break;}
                    j++;
                }
                // if(j == q.size()) return false; 
                cout <<"after while j = "<<j<<endl;
        }
        return true; 
    }
int main()
{
    match("Foooo", "Fab"); 
    return 0;
}
