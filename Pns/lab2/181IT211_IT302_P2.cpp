
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define loop(i,k,n)  for(int i=k;i<n;i++)
int main()
{
    ofstream f;
    f.open("181IT211_IT302_P2_Output_TCx.txt");
    int n;
    string find_name;//="John";
    cout<<"\nEnter the number of inspectors: ";
    //f<<"\nEnter the number of inspectors: ";
    cin>>n;
    vector<string> name(n);
    cout<<"\nEnter the names of inspectors: \n";
    //cout<<"\nEnter the names of inspectors: \n";
    loop(i,0,n)
        cin>>name[i];
    vector<double> percent(n),prob_of_stamp(n),prob_of_expire_fail(n);
    double totalpercent=0;
    cout<<"\nEnter the % of packages stamped by the inspectors: \n";
    loop(i,0,n)
    {
        cout<<name[i]<<" : ";
        cin>>percent[i];
        prob_of_stamp[i]=percent[i]/100;
        totalpercent+=percent[i];
    }
    if(totalpercent==(double)100)
    {
        vector<int> fail_expire(n);
        cout<<"\nEnter the maximum number of packages to be stamped that results in failing to stamp one : \n";
        loop(i,0,n)
        {
            cout<<name[i]<<":";
            cin>>fail_expire[i];
        }
        cout<<"\nProbability of an event that date is stamped by inspectors is:";
        loop(i,0,n)
            cout<<"\nP("<<name[i]<<") :"<<prob_of_stamp[i];
        loop(i,0,n)
            prob_of_expire_fail[i]=double(1.0)/fail_expire[i];
        cout<<"\n\nProbability of a person fails to stamp the expire date in A packets is :";
        loop(i,0,n)
            cout<<"\nP(S'/"<<name[i]<<"):"<<prob_of_expire_fail[i];
        double tot_prob_of_not_stamp=0;
        loop(i,0,n)
            tot_prob_of_not_stamp += prob_of_expire_fail[i] * prob_of_stamp[i];
        cout<<"\n\nTotal Probability of event that date is not stamped is:"<<tot_prob_of_not_stamp;
        int pos=-1;
        string given_name;
        cout<<"\n\nEnter the name whose probability to inspect is to be found: ";
        cin>>given_name;
        find_name=given_name;
        loop(i,0,n)
        {
            if(name[i].compare(find_name)==0)
            {
                pos=i;
                break;
            }
        }
        cout<<"\nProbability that it was inspected by " << given_name<<" is:";
        f<<"\nProbability that it was inspected by " << given_name<<" is:";
        if(pos!=-1)
        {
            double ans;
            ans=(prob_of_expire_fail[pos]*prob_of_stamp[pos])/(tot_prob_of_not_stamp);
            cout<<ans<<"\n";
            f<<ans<<"\n";
        }
        else
        {
            cout<<" 0 \n";
            f<<" 0 \n";
        }
    }
    else
    {
        cout<<"\nInvaid input\n";
        f<<"\nInvaid input\n";
    }
return 0;
}



//////////////////////////////////////////////////////////////////////////////////////
//                                      For file                                    //
/////////////////////////////////////////////////////////////////////////////////////

    // if(argc>1)
    //     T=argv[1];      // i.e ./a.out 2 so T=2 ,implying second test case
    // string outputfile = "181IT209_IT302_P2_Output_TC"+T+".txt"; 
    // freopen(outputfile.c_str(),"w+",stdout);
    // if(totalpercent==(double)100&&condition)
    // {

    //     cout<<"Probability of an event that date is stamped by inspectors is:";
    //     loop(i,0,n)
    //         cout<<"\nP("<<name[i]<<") :"<<prob_of_stamp[i];
    //     loop(i,0,n)
    //         prob_of_expire_fail[i]=double(1.0)/fail_expire[i];
    //     cout<<"\nProbability of a person fails to stamp the expire date in A packets is :";
    //     loop(i,0,n)
    //         cout<<"\nP(S'/"<<name[i]<<"):"<<prob_of_expire_fail[i];
    //     double tot_prob_of_not_stamp=0;
    //     loop(i,0,n)
    //         tot_prob_of_not_stamp += prob_of_expire_fail[i] * prob_of_stamp[i];
    //     cout<<"\nTotal Probability of event that date is not stamped is:"<<tot_prob_of_not_stamp;
    //     int pos=-1;
    //     loop(i,0,n)
    //     {
    //         if(name[i].compare(find_name)==0)
    //         {
    //             pos=i;
    //             break;
    //         }
    //     }
    //     cout<<"\nProbability that it was inspected by "<<find_name<<" :";
    //     if(pos!=-1)
    //     {
    //         double ans;
    //         ans=(prob_of_expire_fail[pos]*prob_of_stamp[pos])/(tot_prob_of_not_stamp);
    //         cout<<ans<<"\n";
    //     }
    //     else
    //         cout<<" 0 \n";
    // }
    // else
    //     cout<<"\nInvaid input\n";