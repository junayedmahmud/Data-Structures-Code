#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;

ll sieve_size;
vi primes;

bitset<100000010>bs;

void sieve(ll size_sieve)
{
    sieve_size=size_sieve+1;
    bs.set();

    bs[0]=bs[1]=0;

    for(ll i=0;i<=sieve_size;i++)
    {
        if(bs[i])
        {
            for(ll j=i*i;j<=sieve_size;j=j+i)
            {
                bs[j]=0;
            }

            primes.push_back((int)i);
        }
    }
}

vi primefactors(ll N)
{
    vi factors;
    ll PF_idx=0,PF=primes[PF_idx];

    while(PF*PF<=N)
    {
        while(N%PF==0)
        {
            N=N/PF;
            factors.push_back(PF);
        }

        PF=primes[++PF_idx];
    }

    if(N!=1)
    {
        cout<<N<<endl;
        factors.push_back(N);
    }

    return factors;
}

int main()
{
    sieve(10000000);

    vi r=primefactors(6);///as per need you need to input

    for(vi::iterator i=r.begin();i!=r.end();i++)
    {
        cout<<*i<<" ";
    }

    return 0;
}
