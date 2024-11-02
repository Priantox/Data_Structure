#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void printVector(vector<int> &v){
    for(auto it=v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void printVectorString(vector<string> &v){
    for(auto it=v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


int main(){
    
    vector<string> v_str;
    v_str.push_back("abc");
    v_str.push_back("def");
    v_str.push_back("wst");
    v_str.push_back("plt");
    v_str.push_back("lse");

    printVectorString(v_str);

    v_str.pop_back();
    printVectorString(v_str);
    v_str.pop_back();
    printVectorString(v_str);

    v_str.insert(v_str.begin()+1, "uv");
    printVectorString(v_str);
    v_str.insert(v_str.begin()+1, 3, "0");
    printVectorString(v_str);

    vector<string> v_str2;
    v_str2.push_back("1");
    v_str2.push_back("2");
    v_str2.push_back("3");
    printVectorString(v_str2);


    v_str.insert(v_str.begin()+1, v_str2.begin(), v_str2.end());
    printVectorString(v_str);


    /*vector<int> v4{23, 7, 10, -4 , 11}, v5{3, 7, 0};
    int Max=-999999;

    for(int i=0;i<v4.size();i++){
        if(Max<v4[i]) Max=v4[i];
    }
    cout<<"Max= "<<Max<<endl;

    printVector(v4);
    printVector(v5);
    v4.swap(v5);

    printVector(v4);
    printVector(v5);

    vector<int> tmp;
    tmp=v4;
    v4=v5;
    v5=tmp;

    printVector(v4);
    printVector(v5);*/


    /*vector<int> v3(5);
    for(int i=0;i<v3.size();i++){
        v3[i]=rand()%50;
    }

    printVector(v3);

    v3.resize(3);
    printVector(v3);

    v3.resize(10);
    printVector(v3);

    v3.assign(7, 15);///assign(length, initial_value)
    printVector(v3);

    cout<<v3.front()<<endl;
    cout<<v3.back()<<endl;

    for(int i=0;i<v3.size();i++){
        cout<<v3.at(i)<<" ";
    }
    cout<<endl;

    cout<<v3[25]<<endl;
    cout<<v3.at(25)<<endl;*/

    /*int n; cin>>n;
    vector<int> v2(n, 123);

    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    for(int i: v2){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto it=v2.begin(); it!=v2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    int *pos=v2.data();
    for(int i=0;i<v2.size();i++){
        cout<<*(pos+i)<<" ";
    }
    cout<<endl;*/


    /*vector<int> v;

    int n=5, x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;*/

    return 0;
}
