#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    
    //1
    // pair<int,int> p = {1,3};
    // cout<<p.first<<" "<<p.second<<endl;

    // pair<int,pair<int,int>> p1 = {7,{5,6}};
    // cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;

    // pair<int,int>arr[] = {{2,4},{5,4}};
    // cout<<arr[1].first; 

    //2
    // vector<int> v;
    // v.push_back(1);
    // v.emplace_back(2);

    // vector<int> v1(5); // {0,0,0,0,0}
    // vector<int> v2(5,100); // {100,100,100,100,100}
    // vector<int> v3(v1); // {0,0,0,0,0}
    
    // cout<<v3.at(2);

    //3
    // vector<int> v;
    // v.push_back(3);
    // v.push_back(7);
    // v.push_back(10);

    // // vector<int>:: iterator i = v.end();
    // // cout<<v.back();

    // // for(auto i = v.begin(); i != v.end(); i++)
    // // cout<<*i<<endl;

    // v.erase(v.begin(),v.begin() + 2); // end will after deleted element

    // v.insert(v.begin(),100);

    // vector<int> copy(2,7);
    // v.insert(v.begin(),copy.begin(),copy.end());

    // for(auto i : v)
    // cout<<i<<endl;

    // v.pop_back(); // From end

    // for(auto i : v)
    // cout<<i<<endl;
    
    //4
    // stack<int> st;
    // st.push(10);
    // st.push(7);
    // st.push(18);

    // st.pop();

    // cout<<st.top();
    //cout<<st.size();
    //cout<<st.empty();

    //5
    // queue<int> q;
    // q.push(1);
    // q.push(3);
    // q.push(7);

    // cout<<q.front()<<endl;
    // cout<<q.back()<<endl;

    // q.pop();
    // cout<<q.front();

    //6
    // priority_queue<int> pq;
    // pq.push(1);
    // pq.push(2);
    // pq.push(10);
    // pq.push(7);

    // cout<<pq.top();

    // priority_queue<int,vector<int>,greater<int>>p;
    // p.push(10);
    // p.push(1);
    // p.push(2);
    // p.push(7);

    // cout<<p.top();

    //7
    // int arr[] = {9,6,1,2,0,29};

    // for(auto i : arr)
    // cout<<i<<" ";
    // cout<<endl;

    // sort(arr,arr + 6);

    // for(auto i : arr)
    // cout<<i<<" ";
    // cout<<endl;

    // sort(arr,arr + 6, greater<int>());

    // for(auto i : arr)
    // cout<<i<<" ";
    // cout<<endl;

    //8
    vector<int> v;
    v.push_back(7);
    v.push_back(10);
    v.push_back(18);
    v.push_back(4);
    v.push_back(111);
    v.push_back(7);
    v.push_back(96);

    cout<<*max_element(v.begin(),v.end())<<endl;
    cout<<*min_element(v.begin(),v.end())<<endl;

    cout<<"Count: "<<count(v.begin(),v.end(),4)<<endl;
    cout<<"Sum: "<<accumulate(v.begin(),v.end(),0);
    
    
}