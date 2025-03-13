#include <fstream>
using namespace std;
ifstream f("summit.in");
ofstream g("summit.out");
int n;
long long a,s[1000001];

int caut(int i,int j)
{
    if(a==s[(i+j)/2])
        return (i+j)/2;
    else if(i<j)
        if(a<s[(i+j)/2])
            caut(i,(i+j)/2 -1);
        else caut((i+j)/2+1,j);
    else return 0;
}

int main()
{
    f>>n;
    f>>a;
    s[1]=a;
    g<<1<<'\n';
    for (int i=2;i<=n;++i)
    {
        f>>a;
        s[i]=s[i-1]+a,g<<caut(1,i-1)<<'\n';
    }
    return 0;
}