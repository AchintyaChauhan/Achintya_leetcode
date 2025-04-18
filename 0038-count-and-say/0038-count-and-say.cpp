class Solution {
public:

    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string res="1";

        for(int i=2;i<=n;i++){
            string temp="";
            int count=1;

            for(int j=0;j<res.size();j++){
                if(j<res.size()-1 && res[j]==res[j+1] ){
                    count++;
                }
                else{
                    string c=to_string(count);
                    temp+=c;
                    temp+=res[j];
                    count=1;
                }

                
            }
            res=temp;


        }


        return res;


    }
};