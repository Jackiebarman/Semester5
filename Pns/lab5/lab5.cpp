#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n)  for(int i=k;i<n;i++)
#define ll long long int
// check if no is a positive integer
bool is_valid(string &n,string &x,string &y,string &z)
{
   //////////////check n//////////////////
    int start=0;
    while(start<n.size()&&n[start]==' ')            // if input is number but space are ahead of it
        start++;
    if(start<n.size()&&n[start]=='-')           //negetive check
        return false;
    for(int i=start;i<n.size();i++)
    {
        if(n[i]=='.')                           
            return false;                     //N should be an integer as we cann't pick fraction ball
        else
        {
            if(n[i]>='0'&&n[i]<='9')          //No other char ....other than digits 0-9
                continue;
            else
                return false;
        }
    }

   //////////Check x

start=0;
    
    while(start<x.size()&&x[start]==' ')            // if input is number but space are ahead of it
        start++;
    if(start<x.size()&&x[start]=='-')           //negetive check
        return false;
    for(int i=start;i<x.size();i++)
    {
        if(x[i]=='.')                           
            return false;                     //X should be an integer as we cann't pick fraction ball
        else
        {
            if(x[i]>='0'&&x[i]<='9')          //No other char ....other than digits 0-9
                continue;
            else
                return false;
        }
    }

    /////////Check y

start=0;
    
    while(start<y.size()&&y[start]==' ')            // if input is number but space are ahead of it
        start++;
    if(start<y.size()&&y[start]=='-')           //negetive check
        return false;
    for(int i=start;i<y.size();i++)
    {
        if(y[i]=='.')                           
            return false;                     //Y should be an integer as we cann't pick fraction ball
        else
        {
            if(y[i]>='0'&&y[i]<='9')          //No other char ....other than digits 0-9
                continue;
            else
                return false;
        }
    }
    /////////check z

start=0;
    
    while(start<z.size()&&z[start]==' ')            // if input is number but space are ahead of it
        start++;
    if(start<z.size()&&z[start]=='-')           //negetive check
        return false;
    for(int i=start;i<z.size();i++)
    {
        if(z[i]=='.')                           
            return false;                     //Z should be an integer as we cann't pick fraction ball
        else
        {
            if(z[i]>='0'&&z[i]<='9')          //No other char ....other than digits 0-9
                continue;
            else
                return false;
        }
    }

  int N,X,Y,Z;
    N=stoi(n);
    X=stoi(x);
    Y=stoi(y);
    Z=stoi(z);
if(N<=X+Y+Z)
  return true;  
else
  return false;            
}
//
ll fact(ll val)
{
  if(val==0 || val==1)
    return 1;
  else
  {
    return val*fact(val-1);
  }
}

// ll findCombination(ll n,ll r)
// {
//   ll x=fact(n);
//   ll y=fact(n-r);
//   ll z=fact(r);
//   //z=z*y;
//   return x/(y*z);
// }

ll findCombination(ll n,ll r)
{ 
    long long p = 1, k = 1; 
  
    // C(n, r) == C(n, n-r), 
    // choosing the smaller value 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
  
            // gcd of p, k 
            long long m = __gcd(p, k); 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
  
    else
        p = 1; 
  
    // if our approach is correct p = ans and k =1 
   return p;
} 




int main(int argc,char* argv[])
{
  double total,den,sum,temp,row,common;
  int N,X,Y,Z;
  string find_name,input,T="1";
  string n,x,y,z;
  cout<<"Enter value of N: ";
  cin>>n;
  cout<<"\nEnter the total number of Blue balls: ";
  cin>>x;
  cout<<"\nEnter the total number of Red balls: ";
  cin>>y;
  cout<<"\nEnter the total number of Green balls: ";
  cin>>z;


  //double arr[N+1];
  vector<double> arr;
  unordered_map<int,double> Row(N+1);
  for(int i=0;i<=N;i++)
  {
    Row[i]=0;
  }
  bool check=false;
  if(is_valid(n,x,y,z))
  {
    N=stoll(n);
    X=stoll(x);
    Y=stoll(y);
    Z=stoll(z);
      check=true;
      total=X+Y+Z;
      row=0;
      den=findCombination(total,N);
      cout<<"OUTPUT:"<<endl;
      for(ll i=0;i<=N;i++)
      {
        temp=0;

        for(ll j=0;j<=N;j++)
        {
          if(i+j<=N && i<=Y && j<=Z && X>=(N-i-j))
          {
            cout<<"f("<<i<<","<<j<<"): ";
            common=((findCombination(Y,i)/den)*findCombination(Z,j)*findCombination(X,(N-i-j)));
            sum+=(common);
            cout<<common<<endl;
            temp+=common;

            Row[j]+=common;
          }
          else
          {
            cout<<"f("<<i<<","<<j<<"): ";
            cout<<"0"<<endl;
          }
        }
        arr.push_back(temp);
      }
      cout<<"INTERMEDIATE RESULT: \n";
      cout<<"ROW TOTALS:\n";
      for(int i=0;i<=N;i++)
      {
        cout<<"f(y,"<<i<<"): "<<Row[i]<<endl;
      }
      cout<<"COLUMN TOTALS:\n";
      for(int i=0;i<=N;i++)
      {
        cout<<"f("<<i<<",z): "<<arr[i]<<endl;
      }

      cout<<"Total Sum: "<<sum<<endl;

    }
    else
    {
      cout<<"\nInvalid input";
    }
    cout<<"\n";
//////////////////////////////////////////////////////////////////////////////////////
////////////////////////Creating my file                                   
/////////////////////////////////////////////////////////////////////////////////////

    if(argc>1)
        T=argv[1];      // i.e ./a.out 2    so T=2 ,implying second test case
    string outputfile = "181IT211_IT302_P4_Output_TC"+T+".txt"; 
    freopen(outputfile.c_str(),"w+",stdout);
    if(check)
    {
      cout<<"OUTPUT:"<<endl;
      for(int i=0;i<=N;i++)
      {
        temp=0;

        for(int j=0;j<=N;j++)
        {
          if(i+j<=N && i<=Y && j<=Z && X>=(N-i-j))
          {
            cout<<"f("<<i<<","<<j<<"): ";
            common=(findCombination(Y,i)*findCombination(Z,j)*findCombination(X,(N-i-j)))/den;
           // sum+=(common);
            cout<<common<<endl;
          }
          else
          {
            cout<<"f("<<i<<","<<j<<"): ";
            cout<<"0"<<endl;
          }
        }
        arr.push_back(temp);
      }
      cout<<"INTERMEDIATE RESULT: \n";
      cout<<"ROW TOTALS:\n";
      for(int i=0;i<=N;i++)
      {
        cout<<"f(y,"<<i<<"): "<<Row[i]<<endl;
      }
      cout<<"COLUMN TOTALS:\n";
      for(int i=0;i<=N;i++)
      {
        cout<<"f("<<i<<",z): "<<arr[i]<<endl;
      }

      cout<<"Total Sum--->f(y,z): "<<sum<<endl;
    }
    else
        cout<<"Invaid input";
}