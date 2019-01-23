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

/*void prime_factors(ll N)
{
    ll factor_index=0;
    ll pf=primes[factor_index];

    while(pf*pf<=N)
    {
        while(N%pf==0)
        {
            N=N/pf;

            cout<<pf<<" ";
        }
        pf=primes[++factor_index];
    }

    if(N!=1)
    {
        cout<<N<<endl;
    }
}*/

ll divisors(ll n)
{
    ll t=0,pf=primes[t],ans=1;

    while(pf*pf<=n)
    {
        ll power=0;

        while(n%pf==0)
        {
            n=n/pf;
            power=power+1;
        }

        ans=ans*(power+1);
        pf=primes[++t];
    }

    if(n!=1)
    {
        ans=ans*2;
    }

    return ans;
}

int main()
{
    sieve(10000000);

    ll result=divisors(60);

    cout<<result<<endl;

    return 0;
}
