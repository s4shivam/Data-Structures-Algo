#include <bits/stdc++.h>

using namespace std;
 
vector <int> v(38,-1);
// Complete the stepPerms function below.
int stepPerms(int n) {
    if( v.at(n) == -1 ){    
        if (n==1 || n==0){
            v[n] = 1;
            return v.at(n);
        }
        if (n==2){
            v[n] = stepPerms(n-1) + stepPerms(n-2);
            return v.at(n);
        }
        v[n] = stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3);
        return v.at(n);
    }
    return v.at(n);
}
//Pre written Code
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
