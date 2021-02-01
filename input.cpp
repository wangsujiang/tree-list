// 输入数据的长度已知：

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    while (cin>>num){
      vector<string>v;
      string val;
      while(num--){
          cin>>val;
          v.push_back(val);
      }
      // other codes
    }
    return 0;
}

// 输入长度未知
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
     string input;
    while(getline(cin,input)){
        istringstream iss(input);
        string str;
        vector<string>v;
        while(iss>>str)
            v.push_back(str);
      // other codes
    }
    return 0;
}


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    string input;
    while(getline(cin,input)){
        istringstream iss(input);
        int sum = 0, val;
        while(iss >> val)
            sum += val;
        cout<<sum<<endl;
    }
    return 0;
}
