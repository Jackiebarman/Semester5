#include <bits/stdc++.h> 
using namespace std; 
bool valid(string s)
{
  for(int i=0;i<s.size();i++)
  {
    if(s[i]<'0' || s[i]>'9')
    {
      //cout<<"Sorry!!! Enter valid input B(integer)."<<endl;
      return false;
      //exit(0);
    }
  }
  return true;
}
bool is_valid(string &s1,string &s2,int a,float b)
{
for(int i=0;i<s1.size();i++)
  {
    if((s1[i]<'0' || s1[i]>'9'))
    {
      cout<<"Sorry!!! Enter valid input for n."<<endl;
      return false;
      //exit(0);
    }
  }
  for(int i=0;i<s2.size();i++)
  {
    if((s2[i]<'0' || s2[i]>'9') && s2[i]!='.')
    {
      cout<<"Sorry!!! Enter valid input p."<<endl;
      return false;
      //exit(0);
    }
  }
  if(b<0 || b>1)
  {
    cout<<"Sorry!!! Enter valid input p."<<endl;
    return false;
  }

  // if(b<d)
  // {
  //   cout<<"Sorry!!! Enter valid input(b should be greater than d in bCd)."<<endl;
  //    return false;
  // }

  // if((a-b)<(c-d))
  // {
  //   cout<<"Sorry!!! Enter valid input(a-b should be greater than c-d)."<<endl;
  //    return false;
  // }

  // if(a<c)
  // {
  //   cout<<"Sorry!!! Enter valid input(a should be greater than c in aCc)."<<endl;
  //    return false;
  // }

    
  return true;            // also check for null input
}  
// Function to find the nCr 
long long printNcR(int n, int r) 
{ 
    long long p = 1, k = 1; 
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
    return p;
} 
int main(int argc,char* argv[])
{ 
  string s1,s2,s3,s4;
  string find_name,input,T="1";
    bool condition =false;
  int a;
  float b;
  cout<<"Enter value n:";
  cin>>s1;
  if(valid(s1))
    a=stoi(s1);
  //cin>>p;
    cout<<"Enter value p:";
  cin>>s2;
  int f=0;
  for(int i=0;i<s2.size();i++)
  {
    if((s2[i]<'0' || s2[i]>'9') && s2[i]!='.')
    {
      f=1;
    }
  }
  if(f==0)
  b=stof(s2);
  //cin>>n;
  // cout<<"Enter value C:";
  // cin>>s3;
  // if(valid(s3))
  // c=stoi(s3);

  // cout<<"Enter value D:";
  // cin>>s4;
  // if(valid(s4))
  // d=stoi(s4);
double res1,res2,mean,var,dev;

  if(is_valid(s1,s2,a,b))    //m ??
    {
    condition=true;
    // long long ncm1=printNcR(b, d); 
    // long long ncm2=printNcR((a-b),(c-d)); 
    // long long ncm3=printNcR(a, c); 
    // res1=ncm1*ncm2;
    // res2=res1/ncm3;
    // cout<<endl;
    mean=(float)a*b;
    var=(1-b)*mean;//(float)((float)(a-c)/(a-1));
    // //cout<<"VARIANCE:"<<var<<endl;
    // var=(float)var*c;
    // //cout<<"VARIANCE:"<<var<<endl;
    // var=(float)var*((float)b/a);
    // //cout<<"VARIANCE:"<<var<<endl;
    // var=(float)var*(1-((float)b/a));
    // //cout<<"VARIANCE:"<<var<<endl;
    dev=sqrt(var);
    cout<<"Intermediate OUTPUT:"<<endl;
    cout<<"MEAN:"<<mean<<endl;
    cout<<"VARIANCE:"<<var<<endl;
    cout<<"STANDARD DEVIATION:"<<dev<<endl;

   // cout<<"Interval(mean+-2*standard deviation): between "<<mean-(2*dev)<<" and "<<mean+(2*dev)<<endl<<endl;
  //  cout<<"Final OUTPUT[h(d;a;b;c)]:"<<res2<<endl;
    }

    
    


//////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//                                      For file                                    //
/////////////////////////////////////////////////////////////////////////////////////

    if(argc>1)
        T=argv[1];      // i.e ./a.out 2    so T=2 ,implying second test case
    string outputfile = "181IT211_IT302_P8_Output_TC"+T+".txt"; 
    freopen(outputfile.c_str(),"w+",stdout);
    if(condition)
    {

      cout<<"\nIntermediate Results:"<<endl;

      cout<<"MEAN:"<<mean<<endl;
    cout<<"VARIANCE:"<<var<<endl;
    cout<<"STANDARD DEVIATION:"<<dev<<endl<<endl;
    cout<<"FINAL OUTPUT[h(d;a;b;c)]:"<<res2<<endl;
    }
    else
        cout<<"Invaid input";

      return 0; 
}