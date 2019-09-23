
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Generate IP Address

// ????

void genip(string s,string output,int count,vector<string> &ans){
   if(count==0){
       if(s.length()>3)
        return;
        
          
       int num=0;
       for(int i=0;i<s.length();i++){
           num = num*10+(s[i]-'0');
       }
       if(s[0]=='0'&&s.length()>1&&num!=0)
         return;
        
      if(num>255)
        return;
        
       string temp = output+s;
       ans.push_back(temp);
       return;
   }
   int len = s.length();
    int x = min(3,len-1);
    int num = 0;
   for(int i=0;i<x;i++){
       output+=s[i];
       output+='.';
       int d = (s[i]-'0');
       num = num*10+d;
       if(num<=255)
        genip(s.substr(i+1,s.length()-1),output,count-1,ans);
       output.erase(output.length()-1);
       if(s[i]=='0'&&i==0)
        break;
   }
    
}

vector<string> genIp(string s)
{
    vector<string> ans;
    genip(s,"",3,ans);
    /*for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }*/
    return ans;
}
