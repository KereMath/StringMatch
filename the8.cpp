#include "the8.h"

int statechanger(std::string pat, int dif, int s, int x, char e,char f)
{if (s < dif && x == pat[s] or (pat[s]==e and x==f) or (pat[s]==f and x==e))
        {return s+1;}
    int futurestate, i;
    for (futurestate = s; futurestate > 0; futurestate--)
    {
        if (pat[futurestate-1] == x)
        {
            for (i = 0; i < futurestate-1; i++){
                if (pat[i] != pat[s-futurestate+1+i] and (pat[i]!=e and  pat[s-futurestate+1+i]!=f) and  (pat[i]!=f and  pat[s-futurestate+1+i]!=e))
                    break;}
            if (i == futurestate-1)
                return futurestate;
        }
    }
    return 0;
}
void calc(std::string pat, int dif, int statestable[][1000],char c, char d)
{int s, x;
    for (s = 0; s <= dif; ++s)
        for (x = 0; x < 1000; ++x)
            statestable[s][x] = statechanger(pat, dif, s, x,c,d);
}
void finder(std::string pat, std::string txt,char c, char d)
{ int flag=0;
int first=1;
    int dif = pat.size();
    int dif1 = txt.size();
    int statestable[dif+1][1000];
    int s=0;
    calc(pat, dif, statestable,c,d);
    for (int i = 0; i < dif1; i++)
    {
        s = statestable[s][txt[i]];
        if (s == dif){
            if(first){
                std::cout<<i-dif+1;
                first=0;
                flag=1;
            }
            else{std::cout<<" "<<i-dif+1;
            
            flag=1;}}
    }
    if(flag==0){
        std::cout<<"NONE";
    }
}
void matchPattern(const std::string& sequence, const std::pair<std::string,std::string> mapping, const std::string& pattern){
    char f,s;
    f=mapping.first[0];
    s=mapping.second[0];
    finder(pattern, sequence,f,s);
}
