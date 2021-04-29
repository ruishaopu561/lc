#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> a){
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

#include <iostream>
#include <vector>

using namespace std;

void address(vector<int> &people, int x)
{
    int length = people.size(), index = 0;
    for(int i=0; i<length; i++){
        if(people[i] < people[index]){
            index = i;
        }
    }
    int num = people[index];
    int i=(index+1) % length, count = 0;;
    while(people[index] > 0 || i != x)
    {
        people[i]--;
        count++;
        i = (i+1) % length;
    }

    people[index] = count;
}

int main()
{
    int n ,x;
    vector<int> people;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        people.push_back(t);
    }
    
    address(people, x);
    print(people);
}